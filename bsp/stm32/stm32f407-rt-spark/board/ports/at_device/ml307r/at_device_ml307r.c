/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-12-16     Jonas        first version
 */

#include <at_device_ml307r.h>
#include <ctype.h>
#include <rtthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "drv_gpio.h"

// #define AT_DEBUG
#define LOG_TAG "at.dev.ml307r"
#include <at_log.h>

// #include <anv_leaks.h>

#ifdef AT_DEVICE_USING_ML307R
#define ML307R_AT_DEFAULT_TIMEOUT 1000
#define ML307R_WAIT_CONNECT_TIME  5000
#define ML307R_THREAD_STACK_SIZE  2048
#define ML307R_POWER_OFF          RT_FALSE
#define ML307R_POWER_ON           RT_TRUE
#define ML307R_POWER_ON_TIME      3
#define ML307R_POWER_OFF_TIME     4
#define ML307R_THREAD_PRIORITY    (RT_THREAD_PRIORITY_MAX / 2)

static int ml307r_power_on(struct at_device *device)
{
    if (device == RT_NULL)
    {
        LOG_E("ml307r device is NULL.");
        return -RT_ERROR;
    }

    struct at_device_ml307r *ml307r = RT_NULL;

    ml307r = (struct at_device_ml307r *)device->user_data;

    /* not nead to set pin configuration for ml307r device power on */
    if (ml307r->power_pin == -1)
    {
        return RT_EOK;
    }
    LOG_I("%s power on", device->name);
    rt_pin_write(ml307r->power_pin, PIN_LOW);

    return RT_EOK;
}

static int ml307r_power_off(struct at_device *device)
{
    if (device == RT_NULL)
    {
        LOG_E("ml307r device is NULL.");
        return -RT_ERROR;
    }
    struct at_device_ml307r *ml307r = RT_NULL;

    ml307r = (struct at_device_ml307r *)device->user_data;
    /* not nead to set pin configuration for ml307r device power on */
    if (ml307r->power_pin == -1)
    {
        return RT_EOK;
    }
    LOG_I("%s power off", device->name);

    rt_pin_write(ml307r->power_pin, PIN_HIGH);

    return RT_EOK;
}

#ifdef AT_USING_NETDEV
static int ml307r_check_link_status(struct at_device *device)
{
    at_response_t resp = RT_NULL;
    int result = -RT_ERROR;
    int link_stat = 0;

    RT_ASSERT(device);

    resp = at_create_resp(96, 0, rt_tick_from_millisecond(300));
    if (resp == RT_NULL)
    {
        LOG_E("no memory for resp create.");
        return -RT_ERROR;
    }

    if (at_obj_exec_cmd(device->client, resp, "AT+MIPCALL?") < 0)
    {
        result = -RT_ERROR;
        goto __exit;
    }

    if (at_resp_parse_line_args_by_kw(resp, "+MIPCALL:", "+MIPCALL: %d,%*d,%*s",
                                      &link_stat)
        > 0)
    {
        if (link_stat == 1)
        {
            result = RT_EOK;
        }
    }

    if (at_obj_exec_cmd(device->client, resp, "AT+CGACT?") < 0)
    {
        result = -RT_ERROR;
        goto __exit;
    }
    //+CGACT: 1,1
    if (at_resp_parse_line_args_by_kw(resp, "+CGACT:", "+CGACT: %d,%*d", &link_stat) > 0)
    {
        result = link_stat;
    }

__exit:

    if (resp)
    {
        at_delete_resp(resp);
    }

    return (result);
}

/* =============================  ml307r network interface operations
 * ============================= */

/* set ml307r network interface device status and address information */
static int ml307r_netdev_set_info(struct netdev *netdev)
{
#define IPADDR_RETRY            10
#define ML307R_IMEI_RESP_SIZE   32
#define ML307R_IPADDR_RESP_SIZE 64
#define ML307R_DNS_RESP_SIZE    96
#define ML307R_INFO_RESP_TIMO   rt_tick_from_millisecond(600)

    int result = RT_EOK;
    ip_addr_t addr;
    at_response_t resp = RT_NULL;
    struct at_device *device = RT_NULL;
    int i = 0, j = 0;
    RT_ASSERT(netdev);

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        LOG_E("get device(%s) failed.", netdev->name);
        return -RT_ERROR;
    }

    /* set network interface device status */
    netdev_low_level_set_status(netdev, RT_TRUE);
    netdev_low_level_set_link_status(netdev, RT_TRUE);
    netdev_low_level_set_dhcp_status(netdev, RT_TRUE);

    resp = at_create_resp(ML307R_IMEI_RESP_SIZE, 0, ML307R_INFO_RESP_TIMO);
    if (resp == RT_NULL)
    {
        LOG_E("no memory for resp create.");
        result = -RT_ENOMEM;
        goto __exit;
    }

    /* set network interface device hardware address(IMEI) */
    {
#define ML307R_NETDEV_HWADDR_LEN 8
#define ML307R_IMEI_LEN          15

        char imei[ML307R_IMEI_LEN] = {0};


        /* send "AT+GSN" commond to get device IMEI */
        if (at_obj_exec_cmd(device->client, resp, "AT+GSN=1") < 0)
        {
            result = -RT_ERROR;
            goto __exit;
        }
        if (at_resp_parse_line_args_by_kw(resp, "+GSN:", "+GSN:%s", imei) <= 0)
        {
            LOG_E("ml307r device(%s) prase \"AT+GSN\" commands resposne data error.",
                  device->name);
            result = -RT_ERROR;
            goto __exit;
        }

        LOG_D("ml307r device(%s) IMEI number: %s", device->name, imei);

        netdev->hwaddr_len = ML307R_NETDEV_HWADDR_LEN;
        /* get hardware address by IMEI */
        for (i = 0, j = 0; i < ML307R_NETDEV_HWADDR_LEN && j < ML307R_IMEI_LEN;
             i++, j += 2)
        {
            if (j != ML307R_IMEI_LEN - 1)
            {
                netdev->hwaddr[i] = (imei[j] - '0') * 10 + (imei[j + 1] - '0');
            }
            else
            {
                netdev->hwaddr[i] = (imei[j] - '0');
            }
        }
    }

    /* set network interface device IP address */
    for (i = 0; i < IPADDR_RETRY; i++)
    {
#define IP_ADDR_SIZE_MAX 16
        char ipaddr[IP_ADDR_SIZE_MAX] = {0};

        at_resp_set_info(resp, ML307R_IPADDR_RESP_SIZE * 2, 2, ML307R_INFO_RESP_TIMO);

        /* send "AT+CIFSR" commond to get IP address */
        if (at_obj_exec_cmd(device->client, resp, "AT+CGPADDR=1") < 0)
        {
            result = -RT_ERROR;
            goto __exit;
        }

        if (at_resp_parse_line_args_by_kw(resp, "+CGPADDR:", "+CGPADDR: %*d,\"%[^\"]",
                                          ipaddr)
            > 0)
        {
            LOG_D("ml307r device(%s) IP address: %s", device->name, ipaddr);

            /* set network interface address information */
            inet_aton(ipaddr, &addr);
            netdev_low_level_set_ipaddr(netdev, &addr);
            break;
        }
    }
    if (i == IPADDR_RETRY)
    {
        LOG_E("ml307r device(%s) prase \"AT+CGPADDR=1\" commands resposne data error!",
              device->name);
        result = -RT_ERROR;
        goto __exit;
    }
    /* set network interface device dns server */
    for (i = 0; i < IPADDR_RETRY; i++)
    {
#define DNS_ADDR_SIZE_MAX 16
        char dns_server1[DNS_ADDR_SIZE_MAX] = {0}, dns_server2[DNS_ADDR_SIZE_MAX] = {0};
        char dns_str[DNS_ADDR_SIZE_MAX * 3] = {0};

        at_resp_set_info(resp, ML307R_DNS_RESP_SIZE, 0, ML307R_INFO_RESP_TIMO);

        /* send "AT+MDNSCFG=\"priority\",0" commond to set resolve IPV4 address priority
         */
        if (at_obj_exec_cmd(device->client, resp, "AT+MDNSCFG=\"priority\",0") != 0)
        {
            rt_thread_mdelay((i + 1) * 500);
            continue;
        }
        /* send "AT+MDNSCFG=\"ip\"" commond to get DNS servers address */
        if (at_obj_exec_cmd(device->client, resp, "AT+MDNSCFG=\"ip\"") < 0)
        {
            rt_thread_mdelay((i + 1) * 500);
            continue;
        }
        //+MDNSCFG: "ip","183.230.126.224",,"183.230.126.225"
        if (at_resp_parse_line_args_by_kw(resp, "+MDNSCFG:", "+MDNSCFG: \"ip\",%s",
                                          dns_str)
            < 0)
        {
            rt_thread_mdelay((i + 1) * 500);
            continue;
        }

        const char *dns1_str = strstr(dns_str, "\"");
        rt_sscanf(dns1_str, "\"%[^\"]", dns_server1);
        const char *dns2_str = strstr(dns_str, "\",\"");
        rt_sscanf(dns2_str, "\",\"%[^\"]", dns_server2);

        LOG_D("ml307r device(%s) primary DNS server address: %s", device->name,
              dns_server1);
        LOG_D("ml307r device(%s) secondary DNS server address: %s", device->name,
              dns_server2);

        inet_aton(dns_server1, &addr);
        netdev_low_level_set_dns_server(netdev, 0, &addr);

        inet_aton(dns_server2, &addr);
        netdev_low_level_set_dns_server(netdev, 1, &addr);
        goto __exit;
    }
    LOG_E("ml307r device(%s) get DNS FAIL!", device->name);
    result = -RT_ERROR;

__exit:
    if (resp)
    {
        at_delete_resp(resp);
    }

    return result;
}

static void check_link_status_entry(void *parameter)
{
#define ML307R_LINK_STATUS_OK  1
#define ML307R_LINK_RESP_SIZE  128
#define ML307R_LINK_RESP_TIMO  (3 * RT_TICK_PER_SECOND)
#define ML307R_LINK_DELAY_TIME (30 * RT_TICK_PER_SECOND)

    int link_status;
    struct at_device *device = RT_NULL;
    struct netdev *netdev = (struct netdev *)parameter;

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        LOG_E("get device(%s) failed.", netdev->name);
        return;
    }

    while (1)
    {
        rt_thread_mdelay(ML307R_LINK_DELAY_TIME);
        link_status = ml307r_check_link_status(device);
        if (link_status < 0)
        {
            continue;
        }
        /* check the network interface device link status  */
        if ((ML307R_LINK_STATUS_OK == link_status) != netdev_is_link_up(netdev))
        {
            netdev_low_level_set_link_status(netdev,
                                             (ML307R_LINK_STATUS_OK == link_status));
        }
    }
}

static int ml307r_netdev_check_link_status(struct netdev *netdev)
{
#define ML307R_LINK_THREAD_TICK       20
#define ML307R_LINK_THREAD_STACK_SIZE (1024 + 512)
#define ML307R_LINK_THREAD_PRIORITY   (RT_THREAD_PRIORITY_MAX - 2)

    rt_thread_t tid;
    char tname[RT_NAME_MAX] = {0};

    if (netdev == RT_NULL)
    {
        LOG_E("input network interface device is NULL.\n");
        return -RT_ERROR;
    }

    rt_snprintf(tname, RT_NAME_MAX, "%s_link", netdev->name);

    tid = rt_thread_create(tname, check_link_status_entry, (void *)netdev,
                           ML307R_LINK_THREAD_STACK_SIZE, ML307R_LINK_THREAD_PRIORITY,
                           ML307R_LINK_THREAD_TICK);
    if (tid)
    {
        rt_thread_startup(tid);
    }

    return RT_EOK;
}

static int ml307r_netdev_set_down(struct netdev *netdev)
{
    struct at_device *device = RT_NULL;

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        LOG_E("get ml307r device by netdev name(%s) failed.", netdev->name);
        return -RT_ERROR;
    }

    if (device->is_init == RT_TRUE)
    {
        ml307r_power_off(device);
        device->is_init = RT_FALSE;

        netdev_low_level_set_status(netdev, RT_FALSE);
        LOG_D("the network interface device(%s) set down status.", netdev->name);
    }

    return RT_EOK;
}

static int ml307r_netdev_set_dns_server(struct netdev *netdev, uint8_t dns_num,
                                        ip_addr_t *dns_server)
{
#define ML307R_DNS_RESP_LEN   8
#define ML307R_DNS_RESP_TIMEO rt_tick_from_millisecond(300)

    int result = RT_EOK;
    at_response_t resp = RT_NULL;
    struct at_device *device = RT_NULL;

    RT_ASSERT(netdev);
    RT_ASSERT(dns_server);

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        LOG_E("get ml307r device by netdev name(%s) failed.", netdev->name);
        return -RT_ERROR;
    }

    resp = at_create_resp(ML307R_DNS_RESP_LEN, 0, ML307R_DNS_RESP_TIMEO);
    if (resp == RT_NULL)
    {
        LOG_D("ml307r set dns server failed, no memory for response object.");
        result = -RT_ENOMEM;
        goto __exit;
    }

    /* send "AT+CDNSCFG=<pri_dns>[,<sec_dns>]" commond to set dns servers */
    if (at_obj_exec_cmd(device->client, resp, "AT+MDNSCFG=\"%s\"", inet_ntoa(*dns_server))
        < 0)
    {
        result = -RT_ERROR;
        goto __exit;
    }

    netdev_low_level_set_dns_server(netdev, dns_num, dns_server);

__exit:
    if (resp)
    {
        at_delete_resp(resp);
    }

    return result;
}

static int ml307r_ping_domain_resolve(struct at_device *device, const char *name,
                                      char ip[16])
{
    int result = RT_EOK;
    char recv_ip[16] = {0};
    at_response_t resp = RT_NULL;

    /* The maximum response time is 14 seconds, affected by network status */
    resp = at_create_resp(512, 4, 14 * RT_TICK_PER_SECOND);
    if (resp == RT_NULL)
    {
        LOG_E("no memory for ml307r device(%s) response structure.", device->name);
        return -RT_ENOMEM;
    }

    if (at_obj_exec_cmd(device->client, resp, "AT+CGACT?") < 0)
    {
        result = -RT_ERROR;
        goto __exit;
    }

    if (at_obj_exec_cmd(device->client, resp, "AT+MDNSGIP=\"%s\"", name) < 0)
    {
        result = -RT_ERROR;
        goto __exit;
    }

    if (at_resp_parse_line_args_by_kw(resp, "+MDNSGIP:", "%*[^,],\"%[^\"]", recv_ip) < 0)
    {
        rt_thread_mdelay(100);
        /* resolve failed, maybe receive an URC CRLF */
    }

    if (rt_strlen(recv_ip) < 8)
    {
        rt_thread_mdelay(100);
        /* resolve failed, maybe receive an URC CRLF */
    }
    else
    {
        rt_strncpy(ip, recv_ip, 15);
        ip[15] = '\0';
    }

__exit:
    if (resp)
    {
        at_delete_resp(resp);
    }

    return result;
}

#ifdef NETDEV_USING_PING
#ifdef AT_DEVICE_USING_ML307R
static int ml307r_netdev_ping(struct netdev *netdev, const char *host, size_t data_len,
                              uint32_t timeout, struct netdev_ping_resp *ping_resp
#if RT_VER_NUM >= 0x50100
                              ,
                              rt_bool_t is_bind
#endif
)
{
#define ML307R_PING_RESP_SIZE 128
#define ML307R_PING_IP_SIZE   16
#define ML307R_PING_TIMEO     (5 * RT_TICK_PER_SECOND)
    int result = -RT_ERROR;
    int response, time, ttl, bytes;
    char ip_addr[ML307R_PING_IP_SIZE] = {0};
    char ip_addr_resp[ML307R_PING_IP_SIZE + 8] = {0};
    at_response_t resp = RT_NULL;
    struct at_device *device = RT_NULL;

#if RT_VER_NUM >= 0x50100
    RT_UNUSED(is_bind);
#endif

    RT_ASSERT(netdev);
    RT_ASSERT(host);
    RT_ASSERT(ping_resp);

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        LOG_E("get device(%s) failed.", netdev->name);
        return -RT_ERROR;
    }

    /* Response line number set six because no \r\nOK\r\n at the end*/
    resp = at_create_resp(ML307R_PING_RESP_SIZE, 4, ML307R_PING_TIMEO);
    if (resp == RT_NULL)
    {
        LOG_E("no memory for resp create.");
        result = -RT_ERROR;
        goto __exit;
    }

    /* send "AT+MPING="<host>"[,[<timeout>][,<pingnum>]]" timeout:1-255 second,
     * pingnum:1-10, commond to send ping request */
    if (ml307r_ping_domain_resolve(device, host, ip_addr) == RT_EOK)
    {
        at_obj_exec_cmd(device->client, resp, "AT+MPING=\"%s\", 10, 1", ip_addr);
    }
    else
    {
        at_obj_exec_cmd(device->client, resp, "AT+MPING=\"%s\", 10, 1", host);
    }

    rt_sscanf(at_resp_get_line_by_kw(resp, "+MPING:"), "+MPING:%d,%*s", &response);

    switch (response)
    {
    case 0:
        if (at_resp_parse_line_args(resp, 4, "+MPING: %d, %[^,], %d, %d, %d", &response,
                                    ip_addr_resp, &bytes, &time, &ttl)
            != RT_NULL)
        {
            rt_sscanf(ip_addr_resp, "%[^\"]", ip_addr);

            /* ping result reponse at the sixth line */
            //            if (at_resp_parse_line_args(resp, 12, "+MPING: %*[^,], %d, %d,
            //            %d, %d, %d",
            //                 &sent, &lost, &min, &max, &avg) != RT_NULL)
            //            {
            //
            //            }
            inet_aton(ip_addr, &(ping_resp->ip_addr));
            ping_resp->data_len = bytes;
            ping_resp->ticks = time;
            ping_resp->ttl = ttl;
            result = RT_EOK;
        }
        break;
    case 1:
        LOG_E("%s device DNS resolution failed.", device->name);
        break;
    case 2:
        LOG_E("%s device DNS resolution timeout.", device->name);
        break;
    case 3:
        LOG_E("%s device Response error.", device->name);
        break;
    case 4:
        LOG_E("%s device Response timeout.", device->name);
        break;
    case 5:
        LOG_E("%s device Other errors.", device->name);
        break;
    default:
        break;
    }


__exit:
    if (resp)
    {
        at_delete_resp(resp);
    }

    return result;
}
#endif
#endif /* NETDEV_USING_PING */

#ifdef NETDEV_USING_NETSTAT
void ml307r_netdev_netstat(struct netdev *netdev)
{
#define ML307R_NETSTAT_RESP_SIZE   320
#define ML307R_NETSTAT_TYPE_SIZE   4
#define ML307R_NETSTAT_IPADDR_SIZE 17
#define ML307R_NETSTAT_EXPRESSION  "+MIPSTATE:%*d,\"%[^\"]\",\"%[^\"]\",%d,%d"

    at_response_t resp = RT_NULL;
    struct at_device *device = RT_NULL;
    int remote_port = 0, link_sta;
    rt_size_t i;
    char *type = RT_NULL;
    char *ipaddr = RT_NULL;

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        LOG_E("get device(%s) failed.", netdev->name);
        return;
    }

    type = (char *)rt_calloc(1, ML307R_NETSTAT_TYPE_SIZE);
    ipaddr = (char *)rt_calloc(1, ML307R_NETSTAT_IPADDR_SIZE);
    if ((type && ipaddr) == RT_NULL)
    {
        LOG_E("no memory for ipaddr create.");
        goto __exit;
    }

    resp = at_create_resp(ML307R_NETSTAT_RESP_SIZE, 0, 5 * RT_TICK_PER_SECOND);
    if (resp == RT_NULL)
    {
        LOG_E("no memory for resp create.", device->name);
        goto __exit;
    }

    /* send network connection information commond "AT+MIPSTATE?" and wait response */
    if (at_obj_exec_cmd(device->client, resp, "AT+MIPSTATE?") < 0)
    {
        goto __exit;
    }

    for (i = 1; i <= resp->line_counts; i++)
    {
        if (strstr(at_resp_get_line(resp, i), "+MIPSTATE:"))
        {
            /* parse the third line of response data, get the network connection
             * information */
            if (at_resp_parse_line_args(resp, i, ML307R_NETSTAT_EXPRESSION, type, ipaddr,
                                        &remote_port, &link_sta)
                < 0)
            {
                goto __exit;
            }
            else
            {
                /* link_sta==2?"LINK_INTNET_UP":"LINK_INTNET_DOWN" */
                LOG_RAW("%s: %s ==> %s:%d\n", type, inet_ntoa(netdev->ip_addr), ipaddr,
                        remote_port);
            }
        }
    }

__exit:
    if (resp)
    {
        at_delete_resp(resp);
    }

    if (type)
    {
        rt_free(type);
    }

    if (ipaddr)
    {
        rt_free(ipaddr);
    }
}
#endif /* NETDEV_USING_NETSTAT */

const struct netdev_ops ml307r_netdev_ops = {
    ml307r_set_up,
    ml307r_netdev_set_down,

    RT_NULL, /* not support set ip, netmask, gatway address */
    ml307r_netdev_set_dns_server,
    RT_NULL, /* not support set DHCP status */

#ifdef NETDEV_USING_PING
    ml307r_netdev_ping,
#endif
#ifdef NETDEV_USING_NETSTAT
    ml307r_netdev_netstat,
#endif
    NULL,
};

static struct netdev *ml307r_netdev_add(const char *netdev_name)
{
#define ML307R_NETDEV_MTU 1500
    struct netdev *netdev = RT_NULL;

    RT_ASSERT(netdev_name);

    netdev = netdev_get_by_name(netdev_name);
    if (netdev != RT_NULL)
    {
        return (netdev);
    }

    netdev = (struct netdev *)rt_calloc(1, sizeof(struct netdev));
    if (netdev == RT_NULL)
    {
        LOG_E("no memory for ml307r device(%s) netdev structure.", netdev_name);
        return RT_NULL;
    }

    netdev->mtu = ML307R_NETDEV_MTU;
    netdev->ops = &ml307r_netdev_ops;

#ifdef SAL_USING_AT
    extern int sal_at_netdev_set_pf_info(struct netdev * netdev);
    /* set the network interface socket/netdb operations */
    sal_at_netdev_set_pf_info(netdev);
#endif

    netdev_register(netdev, netdev_name, RT_NULL);

    return netdev;
}
#endif /* AT_USING_NETDEV */

/* =============================  ml307r device operations =============================
 */

#define AT_SEND_CMD(client, resp, resp_line, timeout, cmd)                               \
    do                                                                                   \
    {                                                                                    \
        (resp) = at_resp_set_info((resp), 128, (resp_line),                              \
                                  rt_tick_from_millisecond(timeout));                    \
        if (at_obj_exec_cmd((client), (resp), (cmd)) < 0)                                \
        {                                                                                \
            result = -RT_ERROR;                                                          \
            goto __exit;                                                                 \
        }                                                                                \
    } while (0)

static int ml307r_get_signal(struct at_device *device)
{
    struct at_client *client = device->client;
    at_response_t resp = RT_NULL;
    char parsed_data[10] = {0};
    int result = -RT_ERROR;
    resp = at_create_resp(128, 0, rt_tick_from_millisecond(500));
    AT_SEND_CMD(client, resp, 0, 3 * ML307R_AT_DEFAULT_TIMEOUT, "AT+CSQ");
    at_resp_parse_line_args_by_kw(resp, "+CSQ:", "+CSQ: %s", &parsed_data);
    if (rt_strncmp(parsed_data, "99,99", sizeof(parsed_data)))
    {
        result = atoi(parsed_data);
    }
    else
    {
        LOG_D("signal strength: %s", parsed_data);
        result = -1; /* no signal */
    }

__exit:
    if (resp)
    {
        at_delete_resp(resp);
    }
    return result;
}

static int ml307r_net_init(struct at_device *device);
/* init for ml307r */
static void ml307r_init_thread_entry(void *parameter)
{
#define INIT_RETRY    32000
#define CPIN_RETRY    10
#define CSQ_RETRY     10
#define CREG_RETRY    10
#define CGREG_RETRY   20
#define IPADDR_RETRY  10
#define CGATT_RETRY   10
#define COMMON_RETRY  10
#define MIPCALL_RETRY 20

    int i, retry_num = INIT_RETRY;
    char parsed_data[32] = {0};
    rt_err_t result = RT_EOK;
    at_response_t resp = RT_NULL;
    struct at_device *device = (struct at_device *)parameter;
    struct at_client *client = device->client;

    rt_thread_mdelay(5000);

    resp = at_create_resp(128, 0, rt_tick_from_millisecond(500));
    if (resp == RT_NULL)
    {
        LOG_E("no memory for ml307r device(%s) response structure.", device->name);
        return;
    }

    LOG_I("start initializing the device(%s)", device->name);

    while (retry_num--)
    {
        ml307r_power_off(device);
        rt_thread_mdelay(500);
        ml307r_power_on(device);
        rt_thread_mdelay(1000);

        /* wait ml307r startup finish */
        if (at_client_obj_wait_connect(client, ML307R_WAIT_CONNECT_TIME))
        {
            result = -RT_ETIMEOUT;
            goto __exit;
        }

        /* disable echo */
        AT_SEND_CMD(client, resp, 0, ML307R_AT_DEFAULT_TIMEOUT, "ATE0");
        /* get module version */
        AT_SEND_CMD(client, resp, 4, 2 * ML307R_AT_DEFAULT_TIMEOUT, "ATI");
        /* show module version */
        for (i = 0; i < (int)resp->line_counts - 1; i++)
        {
            LOG_I("%s", at_resp_get_line(resp, i + 1));
        }
#ifdef AT_USING_RNDIS
        /* Check RNDIS support */
        int mode = -1;
        AT_SEND_CMD(client, resp, 0, ML307R_AT_DEFAULT_TIMEOUT, "AT+MDIALUPCFG=\"mode\"");
        if (at_resp_parse_line_args_by_kw(resp, "+MDIALUPCFG", "+MDIALUPCFG: \"mode\",%d",
                                          &mode)
            > 0)
        {
            LOG_I("%s device RNDIS mode is %s", device->name,
                  (mode == 0) ? "enabled" : "disabled");
            if (mode != 0) // RNDIS mode is disabled
            {
                LOG_I("ml307r device(%s) set RNDIS mode to enable.", device->name);
                AT_SEND_CMD(client, resp, 0, ML307R_AT_DEFAULT_TIMEOUT,
                            "AT+MDIALUPCFG=\"mode\",0");
                result = -RT_ERROR;
                goto __exit;
            }
        }
        else
        {
            LOG_E("ml307r device(%s) get RNDIS mode failed.", device->name);
            result = -RT_ERROR;
            goto __exit;
        }

        /* Check auto dialup */
        mode = -1;
        AT_SEND_CMD(client, resp, 0, ML307R_AT_DEFAULT_TIMEOUT, "AT+MDIALUPCFG=\"auto\"");
        if (at_resp_parse_line_args_by_kw(resp, "+MDIALUPCFG", "+MDIALUPCFG: \"auto\",%d",
                                          &mode)
            > 0)
        {
            LOG_I("%s device auto dialup is %s", device->name,
                  (mode == 1) ? "enabled" : "disabled");
            if (mode != 1) // auto dialup is disabled
            {
                LOG_I("ml307r device(%s) set auto dialup to enable.", device->name);
                AT_SEND_CMD(client, resp, 0, ML307R_AT_DEFAULT_TIMEOUT,
                            "AT+MDIALUPCFG=\"auto\",1");
                result = -RT_ERROR;
                goto __exit;
            }
        }
        else
        {
            LOG_E("ml307r device(%s) get config 'auto dialup' failed.", device->name);
            result = -RT_ERROR;
            goto __exit;
        }
#endif /* AT_USING_RNDIS */
        /* check SIM card */
        rt_thread_mdelay(1500);
        // for (i = 0; i < CPIN_RETRY; i++)
        // {
        //     AT_SEND_CMD(client, resp, 2, 5 * RT_TICK_PER_SECOND, "AT+CPIN?");

        //     if (at_resp_get_line_by_kw(resp, "READY"))
        //     {
        //         LOG_I("ml307r device(%s) SIM card detection success.", device->name);
        //         break;
        //     }
        //     rt_thread_mdelay(500);
        // }
        // if (i == CPIN_RETRY)
        // {
        //     LOG_E("ml307r device(%s) SIM card detection failed.", device->name);
        //     result = -RT_ERROR;
        //     goto __exit;
        // }
        /* check SIM card (ICCID) */
        for (i = 0; i < CPIN_RETRY; i++)
        {
            AT_SEND_CMD(client, resp, 2, 10 * 1000, "AT+ICCID");
            rt_memset(parsed_data, 0, sizeof(parsed_data));
            if (at_resp_parse_line_args_by_kw(resp, "+ICCID:", "+ICCID: %s", &parsed_data)
                > 0)
            {
                LOG_I("%s device SIM card ID: %s", device->name, parsed_data);
                break;
            }
            rt_thread_mdelay(1000);
        }
        if (i >= CPIN_RETRY)
        {
            LOG_E("%s device SIM card detection failed.", device->name);
            result = -RT_ERROR;
            goto __exit;
        }

        /* check signal strength */
        int signal = 0;
        for (i = 0; i < CSQ_RETRY; i++)
        {
            signal = ml307r_get_signal(device);
            if (signal >= 0)
            {
                break;
            }
            rt_thread_mdelay(2000);
        }
        if (i >= CSQ_RETRY)
        {
            LOG_E("%s device signal strength check failed(%d). Retryed(%d)", device->name,
                  signal, i);
            result = -RT_ERROR;
            goto __exit;
        }
        else
        {
            LOG_I("%s device signal strength: %d", device->name, signal);
            result = RT_EOK;
        }

#ifdef AT_USING_RNDIS
        // /* check dialup status */
        // for (i = 0; i < MIPCALL_RETRY; i++)
        // {
        //     AT_SEND_CMD(client, resp, 0, 10 * RT_TICK_PER_SECOND, "AT+MIPCALL?");
        //     int status = 0;
        //     int channel = 0;
        //     rt_memset(parsed_data, 0, sizeof(parsed_data));
        //     if (at_resp_parse_line_args_by_kw(resp, "+MIPCALL:", "+MIPCALL: %d,%d,%s",
        //                                       &status, &channel, &parsed_data)
        //         > 0)
        //     {
        //         LOG_I("ml307r device(%s) dialup success. IP address: %s", device->name,
        //               parsed_data);
        //         break;
        //     }
        //     rt_thread_mdelay(1000);
        // }
        // if (i >= MIPCALL_RETRY)
        // {
        //     LOG_E("ml307r device(%s) dialup failed.", device->name);
        //     result = -RT_ERROR;
        //     goto __exit;
        // }
#endif /* AT_USING_RNDIS */

    __exit:
        if (result == RT_EOK)
        {
            break;
        }
        else
        {
            LOG_I("ml307r device(%s) initialize retry...", device->name);
        }
    }

    if (resp)
    {
        at_delete_resp(resp);
    }

    if (result == RT_EOK)
    {
#ifdef AT_USING_NETDEV
        rt_thread_mdelay(200);
        /* set network interface device status and address information */
        ml307r_netdev_set_info(device->netdev);
        /*  */
        ml307r_netdev_check_link_status(device->netdev);
#endif /* AT_USING_NETDEV */
        LOG_I("ml307r device(%s) network initialize success!", device->name);
        device->is_init = RT_TRUE;
    }
    else
    {
#ifdef AT_USING_NETDEV
        netdev_low_level_set_status(device->netdev, RT_FALSE);
#endif /* AT_USING_NETDEV */
        LOG_E("ml307r device(%s) network initialize failed(%d)!", device->name, result);
    }
}

static int ml307r_net_init(struct at_device *device)
{
    if (device->is_init != RT_FALSE)
    {
        return RT_EOK;
    }

#ifdef AT_DEVICE_ML307R_INIT_ASYN
    rt_thread_t tid;

    tid = rt_thread_create("ml307Init", ml307r_init_thread_entry, (void *)device,
                           ML307R_THREAD_STACK_SIZE, ML307R_THREAD_PRIORITY, 20);
    if (tid)
    {
        rt_thread_startup(tid);
    }
    else
    {
        LOG_E("create ml307r device(%s) initialization thread failed.", device->name);
        return -RT_ERROR;
    }
#else
    ml307r_init_thread_entry(device);
#endif /* AT_DEVICE_ML307R_INIT_ASYN */

    return RT_EOK;
}

static void urc_func(struct at_client *client, const char *data, rt_size_t size)
{
    RT_ASSERT(data);

    LOG_I("URC data : %.*s", size, data);
}

/* ml307r device URC table for the device control */
static const struct at_urc urc_table[] = {
    {"READY", "\r\n", urc_func},
};

static int ml307r_init(struct at_device *device)
{
    struct at_device_ml307r *ml307r = (struct at_device_ml307r *)device->user_data;

    struct serial_configure serial_config = RT_SERIAL_CONFIG_DEFAULT;

    rt_device_t serial = rt_device_find(ml307r->client_name);

    if (serial == RT_NULL)
    {
        LOG_E("ml307r device(%s) initialize failed, get AT client(%s) failed.",
              ml307r->device_name, ml307r->client_name);
        return -RT_ERROR;
    }
#ifdef RT_USING_SERIAL_V2
    serial_config.rx_bufsz = ml307r->recv_buff_size;
    serial_config.tx_bufsz = ml307r->recv_buff_size;
#else
    serial_config.bufsz = ml307r->recv_buff_size;
#endif
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &serial_config);

    /* initialize AT client */
#if RT_VER_NUM >= 0x50100
    at_client_init(ml307r->client_name, ml307r->recv_buff_size, ml307r->recv_buff_size);
#else
    at_client_init(ml307r->client_name, ml307r->recv_buff_size);
#endif

    device->client = at_client_get(ml307r->client_name);
    if (device->client == RT_NULL)
    {
        LOG_E("ml307r device(%s) initialize failed, get AT client(%s) failed.",
              ml307r->device_name, ml307r->client_name);
        return -RT_ERROR;
    }

    /* register URC data execution function  */
    at_obj_set_urc_table(device->client, urc_table,
                         sizeof(urc_table) / sizeof(urc_table[0]));

    /* initialize ml307r pin configuration */
    if (ml307r->power_pin != -1)
    {
        rt_pin_mode(ml307r->power_pin, PIN_MODE_OUTPUT);
    }

    if (ml307r->power_status_pin != -1)
    {
        rt_pin_mode(ml307r->power_status_pin, PIN_MODE_INPUT_PULLUP);
    }
#ifdef AT_USING_NETDEV
#ifdef AT_USING_SOCKET
    ml307r_socket_init(device);
#endif

    /* add ml307r device to the netdev list */
    device->netdev = ml307r_netdev_add(ml307r->device_name);
    if (device->netdev == RT_NULL)
    {
        LOG_E("ml307r device(%s) initialize failed, get network interface device failed.",
              ml307r->device_name);
        return -RT_ERROR;
    }
#endif /* AT_USING_NETDEV */

    /* initialize ml307r device network */
    return ml307r_net_init(device);
}

static int ml307r_deinit(struct at_device *device)
{
    device->is_init = RT_FALSE;
#ifdef AT_USING_NETDEV
    return ml307r_netdev_set_down(device->netdev);
#else
    return RT_EOK;
#endif /* AT_USING_NETDEV */
}

static int ml307r_control(struct at_device *device, int cmd, void *arg)
{
    (void)arg;
    int result = -RT_ERROR;

    RT_ASSERT(device);

    switch (cmd)
    {
    case AT_DEVICE_CTRL_POWER_ON:
        ml307r_power_on(device);
        rt_thread_mdelay(500);
        result = ml307r_net_init(device);
        break;
    case AT_DEVICE_CTRL_POWER_OFF:
        ml307r_power_off(device);
        result = ml307r_deinit(device);
        break;
    case AT_DEVICE_CTRL_GET_SIGNAL:
        result = ml307r_get_signal(device);
        break;
    case AT_DEVICE_CTRL_RESET:
    case AT_DEVICE_CTRL_LOW_POWER:
    case AT_DEVICE_CTRL_SLEEP:
    case AT_DEVICE_CTRL_WAKEUP:
    case AT_DEVICE_CTRL_NET_CONN:
    case AT_DEVICE_CTRL_NET_DISCONN:
    case AT_DEVICE_CTRL_SET_WIFI_INFO:
    case AT_DEVICE_CTRL_GET_GPS:
    case AT_DEVICE_CTRL_GET_VER:
        LOG_W("ml307r not support the control command(%d).", cmd);
        break;
    default:
        LOG_E("input error control command(%d).", cmd);
        break;
    }

    return result;
}

const struct at_device_ops ml307r_device_ops = {
    ml307r_init,
    ml307r_deinit,
    ml307r_control,
};

static int ml307r_device_class_register(void)
{
    struct at_device_class *class = RT_NULL;

    class = (struct at_device_class *)rt_calloc(1, sizeof(struct at_device_class));
    if (class == RT_NULL)
    {
        LOG_E("no memory for ml307r device class create.");
        return -RT_ENOMEM;
    }

    /* fill ml307r device class object */
#ifdef AT_USING_SOCKET
    ml307r_socket_class_register(class);
#endif
    class->device_ops = &ml307r_device_ops;

    return at_device_class_register(class, AT_DEVICE_CLASS_ML307R);
}
INIT_DEVICE_EXPORT(ml307r_device_class_register);

#endif /* AT_DEVICE_USING_ML307R */
