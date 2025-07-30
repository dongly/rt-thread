/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-12-16     Jonas        first version
 */

#ifndef __ML307R_DEVICE_H__
#define __ML307R_DEVICE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#include <at_device.h>

#define ML307R_AT_RESP_TIMEOUT       RT_TICK_PER_SECOND

/* The maximum number of sockets supported by the ml307r device */
#define AT_DEVICE_ML307R_SOCKETS_NUM         6
#define AT_DEVICE_CLASS_ML307R               0XF0U
struct at_device_ml307r
{
    char *device_name;
    char *client_name;

    int power_pin;
    int power_status_pin;
    size_t recv_buff_size;
    struct at_device device;

    void *user_data;
};

#ifdef AT_USING_SOCKET

/* ml307r device socket initialize */
int ml307r_socket_init(struct at_device *device);

/* ml307r device class socket register */
int ml307r_socket_class_register(struct at_device_class *class);
#endif /* AT_USING_SOCKET */

#ifdef __cplusplus
}
#endif

#endif  /*  __AT_DEVICE_ML307R_H__*/
