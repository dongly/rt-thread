/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-12-16     Jonas        first version
 */

#include "at.h"
#include "drv_gpio.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LOG_TAG "ml307r"
#define LOG_LVL LOG_LVL_DBG
// #define LOG_LVL LOG_LVL_INFO
#include "ulog.h"

#define ML307R_AT_DEFAULT_TIMEOUT 1000
#define ML307R_WAIT_CONNECT_TIME  5000
#define ML307R_THREAD_STACK_SIZE  2048
#define ML307R_POWER_OFF          RT_FALSE
#define ML307R_POWER_ON           RT_TRUE
#define ML307R_POWER_ON_TIME      3
#define ML307R_POWER_OFF_TIME     4
#define ML307R_THREAD_PRIORITY    (RT_THREAD_PRIORITY_MAX / 2)

#define ML307R_UART_NAME "uart5"       // Default UART name
#define ML307R_POWER_PIN GET_PIN(D, 3) // Power pin
#define ML307R_BUFF_SIZE 256

static int ml307r_power_on(void)
{
    LOG_I("ML307R power on");
    rt_pin_write(ML307R_POWER_PIN, PIN_LOW);
    return RT_EOK;
}

static int ml307r_power_off(void)
{
    LOG_I("ML307R power off");
    rt_pin_write(ML307R_POWER_PIN, PIN_HIGH);
    return RT_EOK;
}

static int ml307_on_cmd(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    ml307r_power_on();
    return RT_EOK;
}
MSH_CMD_EXPORT_ALIAS(ml307_on_cmd, ml307_on_cmd, ML307R power on command);

static int ml307_off_cmd(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    ml307r_power_off();
    return RT_EOK;
}
MSH_CMD_EXPORT_ALIAS(ml307_off_cmd, ml307_off, ML307R power off command);

static int ml307r_init(void)
{
    struct serial_configure serial_config = RT_SERIAL_CONFIG_DEFAULT;

    rt_device_t serial = rt_device_find(ML307R_UART_NAME);

    if (serial == RT_NULL)
    {
        LOG_E("ml307r device(%s) initialize failed, get AT client(%s) failed.",
              ML307R_UART_NAME, ML307R_UART_NAME);
        return -RT_ERROR;
    }
#ifdef RT_USING_SERIAL_V2
    serial_config.rx_bufsz = ML307R_BUFF_SIZE;
    serial_config.tx_bufsz = ML307R_BUFF_SIZE;
#else
    serial_config.bufsz = ML307R_BUFF_SIZE;
#endif
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &serial_config);

    /* initialize AT client */
#if RT_VER_NUM >= 0x50100
    at_client_init(ML307R_UART_NAME, ML307R_BUFF_SIZE, ML307R_BUFF_SIZE);
#else
    at_client_init(ML307R_UART_NAME, ML307R_BUFF_SIZE);
#endif

    at_client_t client = at_client_get(ML307R_UART_NAME);
    if (client == RT_NULL)
    {
        LOG_E("ml307r device(%s) initialize failed, get AT client(%s) failed.",
              ML307R_UART_NAME, ML307R_UART_NAME);
        return -RT_ERROR;
    }

    /* initialize ml307r pin configuration */

    rt_pin_mode(ML307R_POWER_PIN, PIN_MODE_OUTPUT);
    ml307r_power_off();
    rt_thread_mdelay(ML307R_POWER_OFF_TIME * 1000); // 等待电源关闭

    ml307r_power_on();
    return RT_EOK;
}
INIT_APP_EXPORT(ml307r_init);
