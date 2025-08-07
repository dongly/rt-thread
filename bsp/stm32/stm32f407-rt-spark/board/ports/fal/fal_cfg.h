/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-5      SummerGift   first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <board.h>
#include <fal_def.h>

#define BOOTLOADER_SIZE  (128 * 1024)
#define FLASH_SIZE_GRANULARITY_16K   (4 * 16 * 1024)
#define FLASH_SIZE_GRANULARITY_64K   (64 * 1024)
#define FLASH_SIZE_GRANULARITY_128K  (7 * 128 * 1024)
#define STM32_FLASH_START_ADRESS_16K  STM32_FLASH_START_ADRESS
#define STM32_FLASH_START_ADRESS_64K  (STM32_FLASH_START_ADRESS_16K + FLASH_SIZE_GRANULARITY_16K)
#define STM32_FLASH_START_ADRESS_128K (STM32_FLASH_START_ADRESS_64K + FLASH_SIZE_GRANULARITY_64K)

extern const struct fal_flash_dev stm32_onchip_flash_16k;
extern const struct fal_flash_dev stm32_onchip_flash_64k;
extern const struct fal_flash_dev stm32_onchip_flash_128k;
extern struct fal_flash_dev nor_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE         \
{                                   \
    &stm32_onchip_flash_16k,        \
    &stm32_onchip_flash_64k,        \
    &stm32_onchip_flash_128k,       \
    &nor_flash0,                    \
}

/* ====================== Partition Configuration ========================== */
//                          | 分区名       |            Flash 设备名     |      偏移地址  |        大小      |                |
#define FAL_PART_TABLE                                                                                                    \
{                                                                                                                         \
    {FAL_PART_MAGIC_WROD, "bootloader",           "onchip_flash_16k",              0,                BOOTLOADER_SIZE, 0}, \
    {FAL_PART_MAGIC_WROD,        "app",          "onchip_flash_128k",BOOTLOADER_SIZE,  1024 * 1024 - BOOTLOADER_SIZE, 0}, \
    {FAL_PART_MAGIC_WROD,      "param", FAL_USING_NOR_FLASH_DEV_NAME,              0,                     256 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD,   "download", FAL_USING_NOR_FLASH_DEV_NAME,     256 * 1024,                     768 * 1024, 0}, \
    {FAL_PART_MAGIC_WORD,    "factory", FAL_USING_NOR_FLASH_DEV_NAME,    1024 * 1024,                     768 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD, "filesystem", FAL_USING_NOR_FLASH_DEV_NAME,    1792 * 1024,                    2304 * 1024, 0}, \
}
#endif /* FAL_CFG_H */