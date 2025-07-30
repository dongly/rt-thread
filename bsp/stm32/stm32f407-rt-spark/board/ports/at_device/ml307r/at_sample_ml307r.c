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

#define LOG_TAG "at.sample.ml307r"
#include <at_log.h>

#define ML307R_SAMPLE_DEIVCE_NAME "ml307r0"

#if !defined(ML307R_SAMPLE_CLIENT_NAME)
#define ML307R_SAMPLE_CLIENT_NAME "uart2"
#endif /* ML307R_SAMPLE_CLIENT_NAME */

#if !defined(ML307R_SAMPLE_POWER_PIN)
#define ML307R_SAMPLE_POWER_PIN 0x1C
#endif

#if !defined(ML307R_SAMPLE_STATUS_PIN)
#define ML307R_SAMPLE_STATUS_PIN 0x1E
#endif

#if !defined(ML307R_SAMPLE_RECV_BUFF_LEN)
#define ML307R_SAMPLE_RECV_BUFF_LEN 4096
#endif

#if !defined(AT_DEVICE_CLASS_ML307R)
#define AT_DEVICE_CLASS_ML307R 0xFFFFU
#endif
static struct at_device_ml307r ml307r0 = {
    .device_name = ML307R_SAMPLE_DEIVCE_NAME,
    .client_name = ML307R_SAMPLE_CLIENT_NAME,

    .power_pin = ML307R_SAMPLE_POWER_PIN,
    .power_status_pin = ML307R_SAMPLE_STATUS_PIN,
    .recv_buff_size = ML307R_SAMPLE_RECV_BUFF_LEN,
};

static int ml307r_device_register(void)
{
    struct at_device_ml307r *ml307r = &ml307r0;

    return at_device_register(&(ml307r->device), ml307r->device_name, ml307r->client_name,
                              AT_DEVICE_CLASS_ML307R, (void *)ml307r);
}
INIT_APP_EXPORT(ml307r_device_register);
