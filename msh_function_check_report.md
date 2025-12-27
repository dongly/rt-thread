# MSH函数规范检查报告

## 统计信息

- 总函数数: 547
- 符合规范的函数: 380
- 不符合规范的函数: 167

## 违规统计

- 函数签名错误: 158
- 参数argc未使用且未标记RT_UNUSED: 25
- 参数argv未使用且未标记RT_UNUSED: 25
- 函数缺少返回语句: 24
- 找不到函数定义: 1
- 静态函数数量: 499
- 非静态函数在头文件中无声明: 47

## 检查结果

✅ static int memcheck(int argc, char **argv)
  声明: src/mem.c:600
  定义: src/mem.c:546

✅ static int memtrace(int argc, char **argv)
  声明: src/mem.c:661
  定义: src/mem.c:602

✅ static int memheapcheck(int argc, char **argv)
  声明: src/memheap.c:927
  定义: src/memheap.c:864

✅ static int memheaptrace(int argc, char **argv)
  声明: src/memheap.c:995
  定义: src/memheap.c:929

✅ static int cmd_backtrace(int argc, char **argv)
  声明: src/kservice.c:627
  定义: src/kservice.c:588

✅ static int termios_test(int argc, char **argv)
  声明: examples/libc/termios_test.c:348
  定义: examples/libc/termios_test.c:322

✅ static int ringbuffer_example(int argc, char **argv)
  声明: examples/test/ringbuffer_test.c:48
  定义: examples/test/ringbuffer_test.c:25

❌ int ringbuffer_force_example(void)
  声明: examples/test/ringbuffer_test.c:70
  定义: examples/test/ringbuffer_test.c:51
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void ringbuffer_sample(int argc, char** argv)
  声明: examples/test/ringbuffer_test.c:112
  定义: examples/test/ringbuffer_test.c:84
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rtc_test(int argc, char **argv)
  声明: examples/test/rtc_test.c:62
  定义: examples/test/rtc_test.c:14

✅ static int hwtimer(int argc, char **argv)
  声明: examples/test/hwtimer_test.c:111
  定义: examples/test/hwtimer_test.c:25

✅ static int tcpserver_test(int argc, char **argv)
  声明: examples/network/tcpserver.c:294
  定义: examples/network/tcpserver.c:243

✅ static int tcpclient_test(int argc, char **argv)
  声明: examples/network/tcpclient.c:264
  定义: examples/network/tcpclient.c:206

✅ static int udpserver_test(int argc, char **argv)
  声明: examples/network/udpserver.c:212
  定义: examples/network/udpserver.c:161

✅ static int udpclient_test(int argc, char **argv)
  声明: examples/network/udpclient.c:180
  定义: examples/network/udpclient.c:117

✅ static int rtlink_exsend(int argc, char **argv)
  声明: examples/rt-link/rtlink_example.c:195
  定义: examples/rt-link/rtlink_example.c:134

✅ static int rtlink_fopen(int argc, char **argv)
  声明: examples/rt-link/rtlink_dev_example.c:72
  定义: examples/rt-link/rtlink_dev_example.c:60

❌ static void rtlink_fclose(int argc, char *argv[])
  声明: examples/rt-link/rtlink_dev_example.c:80
  定义: examples/rt-link/rtlink_dev_example.c:74
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rtlink_fread(int argc, char *argv[])
  声明: examples/rt-link/rtlink_dev_example.c:89
  定义: examples/rt-link/rtlink_dev_example.c:82
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rtlink_fwrite(int argc, char *argv[])
  声明: examples/rt-link/rtlink_dev_example.c:134
  定义: examples/rt-link/rtlink_dev_example.c:91
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rtlink_fselect()
  声明: examples/rt-link/rtlink_dev_example.c:217
  定义: examples/rt-link/rtlink_dev_example.c:185
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rtlink_dread(void)
  声明: examples/rt-link/rtlink_dev_example.c:235
  定义: examples/rt-link/rtlink_dev_example.c:220
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static rt_err_t rtlink_dwrite(int argc, char *argv[])
  声明: examples/rt-link/rtlink_dev_example.c:367
  定义: examples/rt-link/rtlink_dev_example.c:322
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rtlink_dinit(void)
  声明: examples/rt-link/rtlink_dev_example.c:396
  定义: examples/rt-link/rtlink_dev_example.c:369
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rtlink_dopen()
  声明: examples/rt-link/rtlink_dev_example.c:412
  定义: examples/rt-link/rtlink_dev_example.c:398
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int cmd_readspeed(int argc, char **argv)
  声明: examples/file/readspeed.c:88
  定义: examples/file/readspeed.c:65

✅ static int seekdir_test(int argc, char **argv)
  声明: examples/file/seekdir.c:55
  定义: examples/file/seekdir.c:17

✅ static int cmd_writespeed(int argc, char **argv)
  声明: examples/file/writespeed.c:99
  定义: examples/file/writespeed.c:73

✅ static int cmd_list_dir(int argc, char **argv)
  声明: examples/file/listdir.c:89
  定义: examples/file/listdir.c:74

✅ static int cmd_readwrite(int argc, char **argv)
  声明: examples/file/readwrite.c:169
  定义: examples/file/readwrite.c:154

✅ static int found_by_module(int argc, char **argv)
  声明: examples/var_export/var_export_example.c:66
  定义: examples/var_export/var_export_example.c:25

✅ static int gic_dump(int argc, char **argv)
  声明: libcpu/aarch64/common/gic.c:519
  定义: libcpu/aarch64/common/gic.c:510

✅ static int gic_dump(int argc, char **argv)
  声明: libcpu/aarch64/common/gicv3.c:856
  定义: libcpu/aarch64/common/gicv3.c:845

✅ static int gic_dump(int argc, char **argv)
  声明: libcpu/arm/cortex-a/gic.c:500
  定义: libcpu/arm/cortex-a/gic.c:491

✅ static int gic_dump(int argc, char **argv)
  声明: libcpu/arm/cortex-a/gicv3.c:710
  定义: libcpu/arm/cortex-a/gicv3.c:701

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/bouffalo_lab/bl61x/board/board.c:174
  定义: bsp/bouffalo_lab/bl61x/board/board.c:167

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/bouffalo_lab/bl60x/board/board.c:87
  定义: bsp/bouffalo_lab/bl60x/board/board.c:79

✅ static int pwm_led_sample(int argc, char **argv)
  声明: bsp/bouffalo_lab/libraries/rt_drivers/sample/pwm_led_sample.c:70
  定义: bsp/bouffalo_lab/libraries/rt_drivers/sample/pwm_led_sample.c:25

✅ static int wdt_sample(int argc, char **argv)
  声明: bsp/bouffalo_lab/libraries/rt_drivers/sample/wdt_sample.c:80
  定义: bsp/bouffalo_lab/libraries/rt_drivers/sample/wdt_sample.c:35

✅ static int hwtimer_sample(int argc, char **argv)
  声明: bsp/bouffalo_lab/libraries/rt_drivers/sample/hwtimer_sample.c:92
  定义: bsp/bouffalo_lab/libraries/rt_drivers/sample/hwtimer_sample.c:33

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/bouffalo_lab/libraries/rt_drivers/sample/spi_sample.c:84
  定义: bsp/bouffalo_lab/libraries/rt_drivers/sample/spi_sample.c:47

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/bouffalo_lab/bl70x/board/board.c:200
  定义: bsp/bouffalo_lab/bl70x/board/board.c:192

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/bouffalo_lab/bl808/lp/board/board.c:59
  定义: bsp/bouffalo_lab/bl808/lp/board/board.c:52

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/bouffalo_lab/bl808/m0/board/board.c:214
  定义: bsp/bouffalo_lab/bl808/m0/board/board.c:207

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/bouffalo_lab/bl808/d0/board/board.c:124
  定义: bsp/bouffalo_lab/bl808/d0/board/board.c:114

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/xuantie/virt64/c906/board/board.c:111
  定义: bsp/xuantie/virt64/c906/board/board.c:101

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/tkm32F499/drivers/drv_lcd.c:292
  定义: bsp/tkm32F499/drivers/drv_lcd.c:256

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/tkm32F499/drivers/board.c:26
  定义: bsp/tkm32F499/drivers/board.c:19
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/apm32/libraries/Drivers/drv_common.c:32
  定义: bsp/apm32/libraries/Drivers/drv_common.c:25
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/fm33lc026/libraries/HAL_Drivers/drv_common.c:28
  定义: bsp/fm33lc026/libraries/HAL_Drivers/drv_common.c:21
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int buzzer_test(int argc, char **argv)
  声明: bsp/nuvoton/numaker-pfm-m487/board/board_dev.c:398
  定义: bsp/nuvoton/numaker-pfm-m487/board/board_dev.c:390

✅ static int nu_check_register(int argc, char **argv)
  声明: bsp/nuvoton/numaker-iot-ma35d1/board/board_dev.c:315
  定义: bsp/nuvoton/numaker-iot-ma35d1/board/board_dev.c:308

✅ static int cmd_reset(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:330
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:323

❌ int cmd_shutdown(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:339
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:332
  问题:
    - 非静态函数在头文件中无声明

❌ int nu_clocks(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:366
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:341
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 非静态函数在头文件中无声明

❌ int list_interrupt(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:386
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_sys.c:370
  问题:
    - 非静态函数在头文件中无声明

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_rtc.c:306
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_rtc.c:290

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_rtc.c:329
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_rtc.c:313

✅ static int lwiperf_example_init(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nuc980/rtt_port/drv_emac.c:693
  定义: bsp/nuvoton/libraries/nuc980/rtt_port/drv_emac.c:686

✅ static int cmd_reset(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:292
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:285

❌ int cmd_shutdown(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:301
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:294
  问题:
    - 非静态函数在头文件中无声明

❌ int nu_clocks(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:319
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:303
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 非静态函数在头文件中无声明

❌ int list_interrupt(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:338
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_sys.c:322
  问题:
    - 非静态函数在头文件中无声明

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_rtc.c:341
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_rtc.c:325

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_rtc.c:364
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_rtc.c:348

✅ static int devmem(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_common.c:115
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_common.c:81

✅ static int vpost_set_osd_colkey(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:425
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:405

✅ static int vpost_show_layer(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:444
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:428

✅ static int vpost_hide_layer(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:463
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:447

✅ static int vpost_fill_color(int argc, char **argv)
  声明: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:494
  定义: bsp/nuvoton/libraries/n9h30/rtt_port/drv_vpost.c:466

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m2354/rtt_port/drv_rtc.c:305
  定义: bsp/nuvoton/libraries/m2354/rtt_port/drv_rtc.c:289

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m2354/rtt_port/drv_rtc.c:328
  定义: bsp/nuvoton/libraries/m2354/rtt_port/drv_rtc.c:312

✅ static int usb_role(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m2354/rtt_port/drv_otg.c:50
  定义: bsp/nuvoton/libraries/m2354/rtt_port/drv_otg.c:31

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/nuvoton/libraries/m2354/rtt_port/drv_common.c:144
  定义: bsp/nuvoton/libraries/m2354/rtt_port/drv_common.c:137
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int nu_sd_attach(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m2354/rtt_port/drv_sdio.c:786
  定义: bsp/nuvoton/libraries/m2354/rtt_port/drv_sdio.c:773

❌ void nu_sd_regdump(void)
  声明: bsp/nuvoton/libraries/m2354/rtt_port/drv_sdio.c:800
  定义: bsp/nuvoton/libraries/m2354/rtt_port/drv_sdio.c:788
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lcd_show_video_layer(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:377
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:370

❌ static rt_err_t lcd_set_overlay_colkey(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:413
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:396
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void lcd_show_overlay_layer(void)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:424
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:415
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void lcd_fill_layer_color(void)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:457
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:427
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static rt_err_t lcd_set_alphablend_opmode(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:479
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_disp.c:459
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int reboot(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:59
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:52

❌ static int nu_tempsen_go(void)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:165
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:148
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void nu_clock_dump(void)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:299
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:187
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void nu_clock_isready(void)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:301
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:228
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void devmem(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:339
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:305
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void devmem2(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:374
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sys.c:341
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtc.c:318
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtc.c:302

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtc.c:341
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtc.c:325

✅ static int nu_rtp_start(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtp.c:135
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtp.c:124

❌ int nu_rtp_load_run(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtp.c:222
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_rtp.c:197
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int nu_sd_attach(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sdio.c:785
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sdio.c:772

❌ int nu_sd_mbr_dump(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sdio.c:971
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sdio.c:964
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ int nu_sd_mbr_layout(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/ma35/rtt_port/drv_sdio.c:1062
  定义: bsp/nuvoton/libraries/ma35/rtt_port/drv_sdio.c:1052
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lwiperf_example_init(int argc, char **argv)
  声明: bsp/nuvoton/libraries/ma35/rtt_port/gmac/drv_gmac.c:793
  定义: bsp/nuvoton/libraries/ma35/rtt_port/gmac/drv_gmac.c:786

✅ static int usb_role(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m480/rtt_port/drv_hsotg.c:51
  定义: bsp/nuvoton/libraries/m480/rtt_port/drv_hsotg.c:32

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m480/rtt_port/drv_rtc.c:304
  定义: bsp/nuvoton/libraries/m480/rtt_port/drv_rtc.c:288

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m480/rtt_port/drv_rtc.c:327
  定义: bsp/nuvoton/libraries/m480/rtt_port/drv_rtc.c:311

✅ static int reboot(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m480/rtt_port/drv_common.c:130
  定义: bsp/nuvoton/libraries/m480/rtt_port/drv_common.c:120

✅ static int nu_sd_attach(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m480/rtt_port/drv_sdio.c:786
  定义: bsp/nuvoton/libraries/m480/rtt_port/drv_sdio.c:773

❌ void nu_sd_regdump(void)
  声明: bsp/nuvoton/libraries/m480/rtt_port/drv_sdio.c:800
  定义: bsp/nuvoton/libraries/m480/rtt_port/drv_sdio.c:788
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int usb_role(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_hsotg.c:51
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_hsotg.c:32

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_rtc.c:304
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_rtc.c:288

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_rtc.c:327
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_rtc.c:311

✅ static int reboot(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_common.c:158
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_common.c:148

❌ void devmem(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_common.c:194
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_common.c:160
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void devmem2(int argc, char *argv[])
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_common.c:228
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_common.c:196
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int nu_sd_attach(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_sdio.c:786
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_sdio.c:773

❌ void nu_sd_regdump(void)
  声明: bsp/nuvoton/libraries/m460/rtt_port/drv_sdio.c:800
  定义: bsp/nuvoton/libraries/m460/rtt_port/drv_sdio.c:788
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lwiperf_example_init(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m460/rtt_port/emac/drv_emac.c:775
  定义: bsp/nuvoton/libraries/m460/rtt_port/emac/drv_emac.c:768

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/ILI9341/lcd_ili9341.c:427
  定义: bsp/nuvoton/libraries/nu_packages/ILI9341/lcd_ili9341.c:346

✅ static int nprobe_auto(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:950
  定义: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:937

✅ static int nid(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:982
  定义: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:855

✅ static int nmove(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:984
  定义: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:669

✅ static int nerase_force(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:986
  定义: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:732

✅ static int ncheck_all(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:988
  定义: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:828

✅ static int nwrite(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:990
  定义: bsp/nuvoton/libraries/nu_packages/SPINAND/drv_spinand.c:618

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/FSA506/lcd_fsa506.c:390
  定义: bsp/nuvoton/libraries/nu_packages/FSA506/lcd_fsa506.c:309

✅ static int audio_test(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/AudioCodec/audio_test.c:90
  定义: bsp/nuvoton/libraries/nu_packages/AudioCodec/audio_test.c:30

✅ static int audio_overnight(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/AudioCodec/audio_test.c:133
  定义: bsp/nuvoton/libraries/nu_packages/AudioCodec/audio_test.c:94

✅ static int hwsem_counter_app(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/hwsem_counter.c:92
  定义: bsp/nuvoton/libraries/nu_packages/Demo/hwsem_counter.c:69

✅ static int whc_devmem(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/wormhole_demo.c:323
  定义: bsp/nuvoton/libraries/nu_packages/Demo/wormhole_demo.c:289

✅ static int go_happy_counter(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:50
  定义: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:38

❌ void go_happy_memcpy_0_1(void)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:95
  定义: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:80
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void go_happy_memcpy_0(void)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:107
  定义: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:97
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void go_happy_memcpy_1(void)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:119
  定义: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:109
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int go_happy_mutex(void)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:188
  定义: bsp/nuvoton/libraries/nu_packages/Demo/smp_demo.c:155
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int ccap_saver(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/ccap_saver.c:410
  定义: bsp/nuvoton/libraries/nu_packages/Demo/ccap_saver.c:396

✅ static int at_wifi_set(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/atdev_utils.c:44
  定义: bsp/nuvoton/libraries/nu_packages/Demo/atdev_utils.c:19

✅ static int ccap_demo(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/Demo/ccap_demo.c:547
  定义: bsp/nuvoton/libraries/nu_packages/Demo/ccap_demo.c:533

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/SSD1963/lcd_ssd1963.c:388
  定义: bsp/nuvoton/libraries/nu_packages/SSD1963/lcd_ssd1963.c:307

✅ static int nu_touch_start(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/ADC_TOUCH/adc_touch.c:718
  定义: bsp/nuvoton/libraries/nu_packages/ADC_TOUCH/adc_touch.c:700

❌ static rt_err_t nu_touch_stop(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/ADC_TOUCH/adc_touch.c:729
  定义: bsp/nuvoton/libraries/nu_packages/ADC_TOUCH/adc_touch.c:721
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static rt_err_t nu_touch_calibration(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/ADC_TOUCH/adc_touch.c:746
  定义: bsp/nuvoton/libraries/nu_packages/ADC_TOUCH/adc_touch.c:737
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int da9062_dump(int argc, char **argv)
  声明: bsp/nuvoton/libraries/nu_packages/DA9062/da9062.c:233
  定义: bsp/nuvoton/libraries/nu_packages/DA9062/da9062.c:223

✅ static int msh_rtc_set_date(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m031/rtt_port/drv_rtc.c:302
  定义: bsp/nuvoton/libraries/m031/rtt_port/drv_rtc.c:286

✅ static int msh_rtc_set_time(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m031/rtt_port/drv_rtc.c:325
  定义: bsp/nuvoton/libraries/m031/rtt_port/drv_rtc.c:309

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/nuvoton/libraries/m031/rtt_port/drv_common.c:139
  定义: bsp/nuvoton/libraries/m031/rtt_port/drv_common.c:130
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int xpwm_get(int argc, char **argv)
  声明: bsp/nuvoton/libraries/m031/rtt_port/drv_pwm.c:261
  定义: bsp/nuvoton/libraries/m031/rtt_port/drv_pwm.c:234

✅ static int test_rs485(int argc, char **argv)
  声明: bsp/nuvoton/nk-rtu980/board/board_dev.c:235
  定义: bsp/nuvoton/nk-rtu980/board/board_dev.c:198

✅ static int buzzer_test(int argc, char **argv)
  声明: bsp/nuvoton/nk-n9h30/board/board_dev.c:377
  定义: bsp/nuvoton/nk-n9h30/board/board_dev.c:369

❌ int test_rs485(int argc, char **argv)
  声明: bsp/nuvoton/nk-n9h30/board/board_dev.c:425
  定义: bsp/nuvoton/nk-n9h30/board/board_dev.c:385
  问题:
    - 非静态函数在头文件中无声明

✅ static int buzzer_test(int argc, char **argv)
  声明: bsp/nuvoton/numaker-hmi-ma35d1/board/board_dev.c:416
  定义: bsp/nuvoton/numaker-hmi-ma35d1/board/board_dev.c:408

❌ void nu_check_register(void)
  声明: bsp/nuvoton/numaker-hmi-ma35d1/board/board_dev.c:663
  定义: bsp/nuvoton/numaker-hmi-ma35d1/board/board_dev.c:656
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/beaglebone/applications/board.c:161
  定义: bsp/beaglebone/applications/board.c:151

✅ static int cmd_list_irq(int argc, char **argv)
  声明: bsp/at91/at91sam9260/platform/interrupt.c:447
  定义: bsp/at91/at91sam9260/platform/interrupt.c:440

✅ static int cmd_reset(int argc, char **argv)
  声明: bsp/at91/at91sam9260/platform/reset.c:43
  定义: bsp/at91/at91sam9260/platform/reset.c:36

❌ int cmd_shutdown(int argc, char** argv)
  声明: bsp/at91/at91sam9260/platform/reset.c:52
  定义: bsp/at91/at91sam9260/platform/reset.c:45
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int cmd_list_irq(int argc, char **argv)
  声明: bsp/at91/at91sam9g45/platform/interrupt.c:457
  定义: bsp/at91/at91sam9g45/platform/interrupt.c:450

✅ static int cmd_reset(int argc, char **argv)
  声明: bsp/at91/at91sam9g45/platform/reset.c:42
  定义: bsp/at91/at91sam9g45/platform/reset.c:35

❌ int cmd_shutdown(int argc, char** argv)
  声明: bsp/at91/at91sam9g45/platform/reset.c:51
  定义: bsp/at91/at91sam9g45/platform/reset.c:44
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int blehr_sample(int argc, char **argv)
  声明: bsp/bluetrum/ab32vg1-ab-prougen/applications/blehr_app.c:75
  定义: bsp/bluetrum/ab32vg1-ab-prougen/applications/blehr_app.c:57

✅ static int fal_ops_test(int argc, char **argv)
  声明: bsp/bluetrum/libraries/hal_drivers/drv_flash.c:139
  定义: bsp/bluetrum/libraries/hal_drivers/drv_flash.c:76

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/ft32/ft32f072xb-starter/board/board.c:31
  定义: bsp/ft32/ft32f072xb-starter/board/board.c:24
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/w60x/drivers/board.c:257
  定义: bsp/w60x/drivers/board.c:249
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int standby(uint8_t argc, char **argv)
  声明: bsp/w60x/drivers/drv_standby.c:101
  定义: bsp/w60x/drivers/drv_standby.c:88
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int oneshot_demo(int argc, char **argv)
  声明: bsp/w60x/oneshot/oneshot_demo.c:148
  定义: bsp/w60x/oneshot/oneshot_demo.c:111

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/mm32f103x/drivers/board.c:26
  定义: bsp/mm32f103x/drivers/board.c:19
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int console(int argc, char **argv)
  声明: bsp/qemu-virt64-aarch64/applications/console.c:60
  定义: bsp/qemu-virt64-aarch64/applications/console.c:35

✅ static int graphic_test(int argc, char **argv)
  声明: bsp/qemu-virt64-aarch64/applications/graphic.c:226
  定义: bsp/qemu-virt64-aarch64/applications/graphic.c:210

✅ static int dma_ch_info(int argc, char **argv)
  声明: bsp/k210/drivers/dmalock.c:93
  定义: bsp/k210/drivers/dmalock.c:74

✅ static int print_io_config(int argc, char **argv)
  声明: bsp/k210/drivers/drv_io_config.c:102
  定义: bsp/k210/drivers/drv_io_config.c:86

✅ static int showcolor(int argc, char **argv)
  声明: bsp/k210/drivers/test/lcd_test.c:101
  定义: bsp/k210/drivers/test/lcd_test.c:35

✅ static int freq(int argc, char **argv)
  声明: bsp/k210/board/board.c:74
  定义: bsp/k210/board/board.c:46

❌ void rt_hw_cpu_reset(void)
  声明: bsp/k210/board/board.c:124
  定义: bsp/k210/board/board.c:118
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062S2-43012/board/ports/slider_sample.c:245
  定义: bsp/Infineon/psoc6-cy8ckit-062S2-43012/board/ports/slider_sample.c:222

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062S2-43012/board/ports/spi_sample.c:82
  定义: bsp/Infineon/psoc6-cy8ckit-062S2-43012/board/ports/spi_sample.c:45

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062-BLE/board/ports/slider_sample.c:244
  定义: bsp/Infineon/psoc6-cy8ckit-062-BLE/board/ports/slider_sample.c:221

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062-BLE/board/ports/spi_sample.c:82
  定义: bsp/Infineon/psoc6-cy8ckit-062-BLE/board/ports/spi_sample.c:45

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-evaluationkit-062S2/board/ports/slider_sample.c:245
  定义: bsp/Infineon/psoc6-evaluationkit-062S2/board/ports/slider_sample.c:222

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-evaluationkit-062S2/board/ports/spi_sample.c:82
  定义: bsp/Infineon/psoc6-evaluationkit-062S2/board/ports/spi_sample.c:45

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/libraries/templates/PSOC62/board/ports/slider_sample.c:244
  定义: bsp/Infineon/libraries/templates/PSOC62/board/ports/slider_sample.c:221

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/libraries/templates/PSOC62/board/ports/spi_sample.c:82
  定义: bsp/Infineon/libraries/templates/PSOC62/board/ports/spi_sample.c:45

✅ static int hwtimer_sample(int argc, char **argv)
  声明: bsp/Infineon/libraries/HAL_Drivers/drv_hwtimer.c:334
  定义: bsp/Infineon/libraries/HAL_Drivers/drv_hwtimer.c:280

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/Infineon/libraries/HAL_Drivers/drv_common.c:30
  定义: bsp/Infineon/libraries/HAL_Drivers/drv_common.c:23
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int flash64k_test(int argc, char **argv)
  声明: bsp/Infineon/libraries/HAL_Drivers/drv_flash.c:380
  定义: bsp/Infineon/libraries/HAL_Drivers/drv_flash.c:334

❌ int flash32k_test(void)
  声明: bsp/Infineon/libraries/HAL_Drivers/drv_flash.c:428
  定义: bsp/Infineon/libraries/HAL_Drivers/drv_flash.c:382
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int pwm_sample(int argc, char **argv)
  声明: bsp/Infineon/libraries/HAL_Drivers/drv_pwm.c:275
  定义: bsp/Infineon/libraries/HAL_Drivers/drv_pwm.c:226

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8cproto-062S3-4343W/board/ports/slider_sample.c:245
  定义: bsp/Infineon/psoc6-cy8cproto-062S3-4343W/board/ports/slider_sample.c:222

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8cproto-062S3-4343W/board/ports/spi_sample.c:82
  定义: bsp/Infineon/psoc6-cy8cproto-062S3-4343W/board/ports/spi_sample.c:45

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062-WIFI-BT/board/ports/slider_sample.c:244
  定义: bsp/Infineon/psoc6-cy8ckit-062-WIFI-BT/board/ports/slider_sample.c:221

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062-WIFI-BT/board/ports/spi_sample.c:82
  定义: bsp/Infineon/psoc6-cy8ckit-062-WIFI-BT/board/ports/spi_sample.c:45

✅ static int Slider_ctrl_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062s4/board/ports/slider_sample.c:244
  定义: bsp/Infineon/psoc6-cy8ckit-062s4/board/ports/slider_sample.c:221

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/Infineon/psoc6-cy8ckit-062s4/board/ports/spi_sample.c:82
  定义: bsp/Infineon/psoc6-cy8ckit-062s4/board/ports/spi_sample.c:45

✅ static int rt_hw_exit(int argc, char **argv)
  声明: bsp/simulator/drivers/board.c:91
  定义: bsp/simulator/drivers/board.c:67

✅ static int usb_device_init(int argc, char **argv)
  声明: bsp/phytium/libraries/port/cherryusb_port/usbd_msh.c:29
  定义: bsp/phytium/libraries/port/cherryusb_port/usbd_msh.c:14

✅ static int usb_host_init(int argc, char **argv)
  声明: bsp/phytium/libraries/port/cherryusb_port/usbh_msh.c:58
  定义: bsp/phytium/libraries/port/cherryusb_port/usbh_msh.c:12

✅ static int qspi_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/qspi_sample.c:100
  定义: bsp/phytium/libraries/drivers_example/qspi_sample.c:31

✅ static int fspim_test_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/spi_sample.c:118
  定义: bsp/phytium/libraries/drivers_example/spi_sample.c:33

✅ static int i2c_msg_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/i2c_msg_sample.c:57
  定义: bsp/phytium/libraries/drivers_example/i2c_msg_sample.c:8

✅ static int can_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/can_sample.c:130
  定义: bsp/phytium/libraries/drivers_example/can_sample.c:48

✅ static int i2c_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/i2c_sample.c:64
  定义: bsp/phytium/libraries/drivers_example/i2c_sample.c:7

✅ static int gpio_toggle_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/gpio_sample.c:112
  定义: bsp/phytium/libraries/drivers_example/gpio_sample.c:50

✅ static int can_loopback_sample(int argc, char **argv)
  声明: bsp/phytium/libraries/drivers_example/can_loopback_sample.c:213
  定义: bsp/phytium/libraries/drivers_example/can_loopback_sample.c:85

✅ static int send_core_isg(int argc, char **argv)
  声明: bsp/phytium/board/phytium_cpu.c:118
  定义: bsp/phytium/board/phytium_cpu.c:105

✅ static int smp_sgi_sample(int argc, char **argv)
  声明: bsp/phytium/board/smp_sgi_test.c:111
  定义: bsp/phytium/board/smp_sgi_test.c:97

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/hk32/hk32f030c8-mini/board/board.c:27
  定义: bsp/hk32/hk32f030c8-mini/board/board.c:20
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/at32/libraries/rt_drivers/drv_common.c:30
  定义: bsp/at32/libraries/rt_drivers/drv_common.c:23
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/airm2m/air105/libraries/rt_drivers/drv_common.c:35
  定义: bsp/airm2m/air105/libraries/rt_drivers/drv_common.c:28
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/airm2m/air32f103/libraries/rt_drivers/drv_common.c:35
  定义: bsp/airm2m/air32f103/libraries/rt_drivers/drv_common.c:28
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/loongson/ls2kdev/drivers/board.c:36
  定义: bsp/loongson/ls2kdev/drivers/board.c:25

❌ void rt_hw_cpu_shutdown(void)
  声明: bsp/loongson/ls2kdev/drivers/board.c:54
  定义: bsp/loongson/ls2kdev/drivers/board.c:43
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int cmd_spi_init(int argc, char **argv)
  声明: bsp/loongson/ls2kdev/drivers/drv_spi.c:101
  定义: bsp/loongson/ls2kdev/drivers/drv_spi.c:80

❌ static int cmd_spi_set_csn(int argc, char *argv[])
  声明: bsp/loongson/ls2kdev/drivers/drv_spi.c:119
  定义: bsp/loongson/ls2kdev/drivers/drv_spi.c:103
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int cmd_spi_write(int argc, char *argv[])
  声明: bsp/loongson/ls2kdev/drivers/drv_spi.c:137
  定义: bsp/loongson/ls2kdev/drivers/drv_spi.c:121
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int cmd_dump_emac_stats(int argc, char **argv)
  声明: bsp/dm365/drivers/davinci_emac.c:1754
  定义: bsp/dm365/drivers/davinci_emac.c:1747

✅ static int cmd_list_irq(int argc, char **argv)
  声明: bsp/dm365/platform/interrupt.c:291
  定义: bsp/dm365/platform/interrupt.c:284

✅ static int cmd_reset(int argc, char **argv)
  声明: bsp/dm365/platform/reset.c:51
  定义: bsp/dm365/platform/reset.c:44

❌ int cmd_shutdown(int argc, char** argv)
  声明: bsp/dm365/platform/reset.c:60
  定义: bsp/dm365/platform/reset.c:53
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int k64_dump_tx_bd(int argc, char **argv)
  声明: bsp/frdm-k64f/board/drv_emac.c:425
  定义: bsp/frdm-k64f/board/drv_emac.c:409

❌ long k64_dump_rx_bd(void)
  声明: bsp/frdm-k64f/board/drv_emac.c:449
  定义: bsp/frdm-k64f/board/drv_emac.c:427
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/renesas/libraries/HAL_Drivers/drv_common.c:49
  定义: bsp/renesas/libraries/HAL_Drivers/drv_common.c:37
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int hwtimer_sample(int argc, char **argv)
  声明: bsp/renesas/libraries/HAL_Drivers/drivers/drv_hwtimer.c:318
  定义: bsp/renesas/libraries/HAL_Drivers/drivers/drv_hwtimer.c:267

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/renesas/libraries/HAL_Drivers/drivers/drv_lcd.c:463
  定义: bsp/renesas/libraries/HAL_Drivers/drivers/drv_lcd.c:418

✅ static int icu_sample(int argc, char **argv)
  声明: bsp/renesas/ra2l1-cpk/src/hal_entry.c:59
  定义: bsp/renesas/ra2l1-cpk/src/hal_entry.c:40

✅ static int icu_sample(int argc, char **argv)
  声明: bsp/renesas/ra6m4-cpk/src/hal_entry.c:61
  定义: bsp/renesas/ra6m4-cpk/src/hal_entry.c:42

✅ static int G2D_Test_Draw_Circle(int argc, char **argv)
  声明: bsp/renesas/ra6m3-hmi-board/board/ports/drv_g2d.c:132
  定义: bsp/renesas/ra6m3-hmi-board/board/ports/drv_g2d.c:124

❌ int G2D_Test_Draw_FillRect(int argc, const char *argv[])
  声明: bsp/renesas/ra6m3-hmi-board/board/ports/drv_g2d.c:218
  定义: bsp/renesas/ra6m3-hmi-board/board/ports/drv_g2d.c:207
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int can_sample(int argc, char **argv)
  声明: bsp/renesas/ra6m3-hmi-board/board/ports/can_test.c:145
  定义: bsp/renesas/ra6m3-hmi-board/board/ports/can_test.c:78

✅ static int reboot(int argc, char **argv)
  声明: bsp/rockchip/rk3500/driver/board.c:34
  定义: bsp/rockchip/rk3500/driver/board.c:27

✅ static int reboot(int argc, char **argv)
  声明: bsp/rockchip/rk3568/driver/board.c:111
  定义: bsp/rockchip/rk3568/driver/board.c:100

❌ static void print_cpu_id(int argc, char *argv[])
  声明: bsp/rockchip/rk3568/driver/board.c:117
  定义: bsp/rockchip/rk3568/driver/board.c:113
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void start_cpu(int argc, char *argv[])
  声明: bsp/rockchip/rk3568/driver/board.c:129
  定义: bsp/rockchip/rk3568/driver/board.c:120
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int dump_irq_summry(int argc, char **argv)
  声明: bsp/rockchip/common/drivers/interrupt.c:204
  定义: bsp/rockchip/common/drivers/interrupt.c:186

✅ static int clk_dump(int argc, char **argv)
  声明: bsp/rockchip/common/drivers/drv_clock.c:484
  定义: bsp/rockchip/common/drivers/drv_clock.c:451

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/rockchip/common/drivers/reset.c:41
  定义: bsp/rockchip/common/drivers/reset.c:31
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int io_mem(int argc, char **argv)
  声明: bsp/rockchip/common/drivers/io.c:245
  定义: bsp/rockchip/common/drivers/io.c:108

✅ static int saadc_sample(int argc, char **argv)
  声明: bsp/nrf5x/libraries/drivers/drv_adc.c:285
  定义: bsp/nrf5x/libraries/drivers/drv_adc.c:236

✅ static int gpio_sample(int argc, char **argv)
  声明: bsp/nrf5x/libraries/drivers/drv_gpio.c:496
  定义: bsp/nrf5x/libraries/drivers/drv_gpio.c:465

✅ static int wdt_sample(int argc, char **argv)
  声明: bsp/nrf5x/libraries/drivers/drv_wdt.c:92
  定义: bsp/nrf5x/libraries/drivers/drv_wdt.c:81

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/nrf5x/libraries/drivers/drv_spi.c:375
  定义: bsp/nrf5x/libraries/drivers/drv_spi.c:341

✅ static int pwm_led_sample(int argc, char **argv)
  声明: bsp/nrf5x/libraries/drivers/drv_pwm.c:434
  定义: bsp/nrf5x/libraries/drivers/drv_pwm.c:387

✅ static int sys_run_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:163
  定义: bsp/ht32/ht32f52352/applications/test.c:123

✅ static int gpio_output_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:226
  定义: bsp/ht32/ht32f52352/applications/test.c:186

✅ static int gpio_input_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:313
  定义: bsp/ht32/ht32f52352/applications/test.c:276

✅ static int uart_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:410
  定义: bsp/ht32/ht32f52352/applications/test.c:341

✅ static int i2c_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:513
  定义: bsp/ht32/ht32f52352/applications/test.c:459

✅ static int spi_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:602
  定义: bsp/ht32/ht32f52352/applications/test.c:531

✅ static int adc_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:660
  定义: bsp/ht32/ht32f52352/applications/test.c:629

✅ static int wdt_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:733
  定义: bsp/ht32/ht32f52352/applications/test.c:669

✅ static int usbd_task(int argc, char **argv)
  声明: bsp/ht32/ht32f52352/applications/test.c:800
  定义: bsp/ht32/ht32f52352/applications/test.c:762

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/ht32/libraries/ht32_drivers/drv_common.c:26
  定义: bsp/ht32/libraries/ht32_drivers/drv_common.c:19
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int sys_run_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:163
  定义: bsp/ht32/ht32f53252/applications/test.c:123

✅ static int gpio_output_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:226
  定义: bsp/ht32/ht32f53252/applications/test.c:186

✅ static int gpio_input_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:313
  定义: bsp/ht32/ht32f53252/applications/test.c:276

✅ static int uart_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:410
  定义: bsp/ht32/ht32f53252/applications/test.c:341

✅ static int i2c_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:513
  定义: bsp/ht32/ht32f53252/applications/test.c:459

✅ static int spi_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:602
  定义: bsp/ht32/ht32f53252/applications/test.c:531

✅ static int adc_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:660
  定义: bsp/ht32/ht32f53252/applications/test.c:629

✅ static int wdt_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:733
  定义: bsp/ht32/ht32f53252/applications/test.c:669

✅ static int usbd_task(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:800
  定义: bsp/ht32/ht32f53252/applications/test.c:762

✅ static int can_test(int argc, char **argv)
  声明: bsp/ht32/ht32f53252/applications/test.c:937
  定义: bsp/ht32/ht32f53252/applications/test.c:893

✅ static int sys_run_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:162
  定义: bsp/ht32/ht32f12366/applications/test.c:122

✅ static int gpio_output_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:225
  定义: bsp/ht32/ht32f12366/applications/test.c:185

✅ static int gpio_input_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:312
  定义: bsp/ht32/ht32f12366/applications/test.c:275

✅ static int uart_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:409
  定义: bsp/ht32/ht32f12366/applications/test.c:340

✅ static int i2c_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:512
  定义: bsp/ht32/ht32f12366/applications/test.c:458

✅ static int spi_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:601
  定义: bsp/ht32/ht32f12366/applications/test.c:530

✅ static int adc_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:659
  定义: bsp/ht32/ht32f12366/applications/test.c:628

✅ static int wdt_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:732
  定义: bsp/ht32/ht32f12366/applications/test.c:668

✅ static int usbd_task(int argc, char **argv)
  声明: bsp/ht32/ht32f12366/applications/test.c:799
  定义: bsp/ht32/ht32f12366/applications/test.c:761

❌ static int cmd05_check(int argc, char **argv)
  声明: bsp/ft2004/drivers/drv_qspi.c:359
  定义: bsp/ft2004/drivers/drv_qspi.c:319
  问题:
    - 函数缺少返回语句

❌ static void cmd35_check(void)
  声明: bsp/ft2004/drivers/drv_qspi.c:402
  定义: bsp/ft2004/drivers/drv_qspi.c:363
  问题:
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void cmd15_check(void)
  声明: bsp/ft2004/drivers/drv_qspi.c:429
  定义: bsp/ft2004/drivers/drv_qspi.c:405
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int send_core_isg(int argc, char **argv)
  声明: bsp/ft2004/drivers/ft2004.c:89
  定义: bsp/ft2004/drivers/ft2004.c:76

✅ static int ft_reset(int argc, char **argv)
  声明: bsp/ft2004/drivers/board.c:151
  定义: bsp/ft2004/drivers/board.c:144

✅ static int demo_dump_sdc(int argc, char **argv)
  声明: bsp/ft2004/drivers/drv_sdctrl.c:60
  定义: bsp/ft2004/drivers/drv_sdctrl.c:53

✅ static int spi_9f_s25fs_sample(int argc, char **argv)
  声明: bsp/ft2004/drivers/drv_spi.c:431
  定义: bsp/ft2004/drivers/drv_spi.c:412

❌ static void spi_5a_s25fs_sample(int argc, char *argv[])
  声明: bsp/ft2004/drivers/drv_spi.c:453
  定义: bsp/ft2004/drivers/drv_spi.c:434
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int cmd_reset(int argc, char **argv)
  声明: bsp/nv32f100x/board/src/board.c:111
  定义: bsp/nv32f100x/board/src/board.c:103

✅ static int sayHello(int argc, char **argv)
  声明: bsp/smartfusion2/board/config.c:30
  定义: bsp/smartfusion2/board/config.c:22

✅ static int wifi_weather_sample(int argc, char **argv)
  声明: bsp/nxp/mcx/mcxn/frdm-mcxn947/board/ports/wifi_weather_sample.c:198
  定义: bsp/nxp/mcx/mcxn/frdm-mcxn947/board/ports/wifi_weather_sample.c:187

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/nxp/mcx/mcxn/frdm-mcxn947/board/ports/spi_sample.c:78
  定义: bsp/nxp/mcx/mcxn/frdm-mcxn947/board/ports/spi_sample.c:46

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/nxp/mcx/mcxn/frdm-mcxn236/board/ports/spi_sample.c:78
  定义: bsp/nxp/mcx/mcxn/frdm-mcxn236/board/ports/spi_sample.c:46

✅ static int fal_sample(int argc, char **argv)
  声明: bsp/nxp/lpc/lpc55sxx/lpc55s69_nxp_evk/board/ports/fal/fal_sample.c:178
  定义: bsp/nxp/lpc/lpc55sxx/lpc55s69_nxp_evk/board/ports/fal/fal_sample.c:152

❌ static void fal_elmfat_sample(void)
  声明: bsp/nxp/lpc/lpc55sxx/lpc55s69_nxp_evk/board/ports/fal/fal_sample.c:240
  定义: bsp/nxp/lpc/lpc55sxx/lpc55s69_nxp_evk/board/ports/fal/fal_sample.c:180
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void easyflash_sample(void)
  声明: bsp/nxp/lpc/lpc55sxx/lpc55s69_nxp_evk/board/ports/fal/fal_sample.c:275
  定义: bsp/nxp/lpc/lpc55sxx/lpc55s69_nxp_evk/board/ports/fal/fal_sample.c:242
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int get_mma8562(uint8_t data)
  声明: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/drv_mma8562.c:108
  定义: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/drv_mma8562.c:78
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lcd_touch_sample(int argc, char **argv)
  声明: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/sample/lcd_touch_sample.c:67
  定义: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/sample/lcd_touch_sample.c:20

✅ static int lcd_sample(int argc, char **argv)
  声明: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/sample/lcd_sample.c:71
  定义: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/sample/lcd_sample.c:19

✅ static int touch_sample(int argc, char **argv)
  声明: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/sample/touch_sample.c:49
  定义: bsp/nxp/lpc/lpc55sxx/Libraries/drivers/sample/touch_sample.c:19

❌ static int lcd_clear(rt_uint16_t color)
  声明: bsp/nxp/lpc/lpc54608-LPCXpresso/drivers/drv_lcd.c:466
  定义: bsp/nxp/lpc/lpc54608-LPCXpresso/drivers/drv_lcd.c:411
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rtc_sample(int argc, char **argv)
  声明: bsp/nxp/imx/imxrt/libraries/drivers/drv_rtc.c:218
  定义: bsp/nxp/imx/imxrt/libraries/drivers/drv_rtc.c:176

✅ static int board_reboot(int argc, char **argv)
  声明: bsp/nxp/imx/imx6ull-smart/drivers/board.c:86
  定义: bsp/nxp/imx/imx6ull-smart/drivers/board.c:58

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/ultrarisc/ur_dp1000_evb/board/board.c:129
  定义: bsp/ultrarisc/ur_dp1000_evb/board/board.c:119

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/k230/board/board.c:135
  定义: bsp/k230/board/board.c:127

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/qemu-virt64-riscv/driver/board.c:111
  定义: bsp/qemu-virt64-riscv/driver/board.c:101

✅ static int led(int argc, char **argv)
  声明: bsp/wch/risc-v/ch32v103r-evt/applications/main.c:75
  定义: bsp/wch/risc-v/ch32v103r-evt/applications/main.c:55

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/wch/arm/ch579m/board/board.c:29
  定义: bsp/wch/arm/ch579m/board/board.c:22
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/wch/arm/Libraries/ch32_drivers/drv_common.c:33
  定义: bsp/wch/arm/Libraries/ch32_drivers/drv_common.c:26
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int pin_sample(int argc, char **argv)
  声明: bsp/synwit/swm320-mini/applications/main.c:48
  定义: bsp/synwit/swm320-mini/applications/main.c:38

❌ static int adc_vol_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:84
  定义: bsp/synwit/swm320-mini/applications/main.c:57
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int hwtimer_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:148
  定义: bsp/synwit/swm320-mini/applications/main.c:98
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int pwm_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:177
  定义: bsp/synwit/swm320-mini/applications/main.c:157
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int rtc_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:209
  定义: bsp/synwit/swm320-mini/applications/main.c:182
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int wdt_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:265
  定义: bsp/synwit/swm320-mini/applications/main.c:223
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void spi_w25q_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:344
  定义: bsp/synwit/swm320-mini/applications/main.c:289
  问题:
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void spi_flash_elmfat_sample(void)
  声明: bsp/synwit/swm320-mini/applications/main.c:390
  定义: bsp/synwit/swm320-mini/applications/main.c:349
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void elmfat_sample(void)
  声明: bsp/synwit/swm320-mini/applications/main.c:455
  定义: bsp/synwit/swm320-mini/applications/main.c:414
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void sdio_elmfat_sample(void)
  声明: bsp/synwit/swm320-mini/applications/main.c:506
  定义: bsp/synwit/swm320-mini/applications/main.c:465
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void crypto_sample(void)
  声明: bsp/synwit/swm320-mini/applications/main.c:533
  定义: bsp/synwit/swm320-mini/applications/main.c:510
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int norflash_sample(int argc, char *argv[])
  声明: bsp/synwit/swm320-mini/applications/main.c:598
  定义: bsp/synwit/swm320-mini/applications/main.c:538
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int pin_sample(int argc, char **argv)
  声明: bsp/synwit/swm341-mini/applications/main.c:49
  定义: bsp/synwit/swm341-mini/applications/main.c:39

❌ static int adc_vol_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:83
  定义: bsp/synwit/swm341-mini/applications/main.c:58
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int dac_vol_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:128
  定义: bsp/synwit/swm341-mini/applications/main.c:94
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ int can_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:253
  定义: bsp/synwit/swm341-mini/applications/main.c:189
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int hwtimer_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:316
  定义: bsp/synwit/swm341-mini/applications/main.c:266
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int pwm_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:345
  定义: bsp/synwit/swm341-mini/applications/main.c:325
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int rtc_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:378
  定义: bsp/synwit/swm341-mini/applications/main.c:351
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int wdt_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:434
  定义: bsp/synwit/swm341-mini/applications/main.c:392
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void spi_w25q_sample(int argc, char *argv[])
  声明: bsp/synwit/swm341-mini/applications/main.c:509
  定义: bsp/synwit/swm341-mini/applications/main.c:459
  问题:
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void elmfat_sample(void)
  声明: bsp/synwit/swm341-mini/applications/main.c:555
  定义: bsp/synwit/swm341-mini/applications/main.c:514
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void elmfat_sample(void)
  声明: bsp/synwit/swm341-mini/applications/main.c:555
  定义: bsp/synwit/swm341-mini/applications/main.c:514
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void elmfat_sample(void)
  声明: bsp/synwit/swm341-mini/applications/main.c:555
  定义: bsp/synwit/swm341-mini/applications/main.c:514
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void crypto_sample(void)
  声明: bsp/synwit/swm341-mini/applications/main.c:709
  定义: bsp/synwit/swm341-mini/applications/main.c:672
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ int dynmem_sample(void)
  声明: bsp/synwit/swm341-mini/applications/main.c:765
  定义: bsp/synwit/swm341-mini/applications/main.c:749
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int gt9147_sample(void)
  声明: bsp/synwit/swm341-mini/applications/main.c:879
  定义: bsp/synwit/swm341-mini/applications/main.c:840
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/synwit/libraries/SWM341_drivers/drv_rgb_lcd.c:230
  定义: bsp/synwit/libraries/SWM341_drivers/drv_rgb_lcd.c:194

✅ static int pico_reboot(int argc, char **argv)
  声明: bsp/raspberry-pico/RP2040/board/board.c:106
  定义: bsp/raspberry-pico/RP2040/board/board.c:99

✅ static int adc_vol_sample(int argc, char **argv)
  声明: bsp/n32g452xx/n32g452xx-mini-system/board/msp/n32_msp.c:883
  定义: bsp/n32g452xx/n32g452xx-mini-system/board/msp/n32_msp.c:857

❌ static int hwtimer_sample(int argc, char *argv[])
  声明: bsp/n32g452xx/n32g452xx-mini-system/board/msp/n32_msp.c:949
  定义: bsp/n32g452xx/n32g452xx-mini-system/board/msp/n32_msp.c:937
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int crc_demo(uint8_t argc, char **argv)
  声明: bsp/n32g452xx/Libraries/rt_drivers/drv_crypto.c:417
  定义: bsp/n32g452xx/Libraries/rt_drivers/drv_crypto.c:363
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/n32g452xx/Libraries/rt_drivers/drv_common.c:31
  定义: bsp/n32g452xx/Libraries/rt_drivers/drv_common.c:24
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6300evk/board/rtt_board.c:122
  定义: bsp/hpmicro/hpm6300evk/board/rtt_board.c:107

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6p00evk/board/rtt_board.c:114
  定义: bsp/hpmicro/hpm6p00evk/board/rtt_board.c:102

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6800evk/board/rtt_board.c:125
  定义: bsp/hpmicro/hpm6800evk/board/rtt_board.c:113

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm5e00evk/board/rtt_board.c:114
  定义: bsp/hpmicro/hpm5e00evk/board/rtt_board.c:102

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6200evk/board/rtt_board.c:122
  定义: bsp/hpmicro/hpm6200evk/board/rtt_board.c:107

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6e00evk/board/rtt_board.c:125
  定义: bsp/hpmicro/hpm6e00evk/board/rtt_board.c:113

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm5300evk/board/rtt_board.c:122
  定义: bsp/hpmicro/hpm5300evk/board/rtt_board.c:109

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm5301evklite/board/rtt_board.c:123
  定义: bsp/hpmicro/hpm5301evklite/board/rtt_board.c:110

✅ static int rw007_update(int argc, char **argv)
  声明: bsp/hpmicro/hpm6750evkmini/board/rw007_port.c:99
  定义: bsp/hpmicro/hpm6750evkmini/board/rw007_port.c:90

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6750evkmini/board/rtt_board.c:119
  定义: bsp/hpmicro/hpm6750evkmini/board/rtt_board.c:104

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6750evk2/board/rtt_board.c:119
  定义: bsp/hpmicro/hpm6750evk2/board/rtt_board.c:104

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/hpmicro/hpm6750evk/board/rtt_board.c:119
  定义: bsp/hpmicro/hpm6750evk/board/rtt_board.c:104

✅ static int smartconfig_demo(int argc, char **argv)
  声明: bsp/amebaz/applications/smartconfig_app.c:133
  定义: bsp/amebaz/applications/smartconfig_app.c:123

✅ static int _ac97_reg_dump(int argc, char **argv)
  声明: bsp/qemu-vexpress-a9/drivers/audio/drv_ac97.c:107
  定义: bsp/qemu-vexpress-a9/drivers/audio/drv_ac97.c:74

✅ static int _aaci_pl041_reg_dump(int argc, char **argv)
  声明: bsp/qemu-vexpress-a9/drivers/audio/drv_pl041.c:396
  定义: bsp/qemu-vexpress-a9/drivers/audio/drv_pl041.c:351

❌ static int lcd_fill(int argc, static int **argv)
  声明: bsp/stm32/stm32f407-atk-explorer/board/ports/drv_lcd.c:2045
  定义: bsp/stm32/stm32f407-atk-explorer/board/ports/drv_lcd.c:2017
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int sram_test(int argc, char **argv)
  声明: bsp/stm32/stm32f407-atk-explorer/board/ports/drv_sram.c:160
  定义: bsp/stm32/stm32f407-atk-explorer/board/ports/drv_sram.c:91

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/stm32/stm32h750-weact-ministm32h7xx/board/port/drv_lcd_spi.c:237
  定义: bsp/stm32/stm32h750-weact-ministm32h7xx/board/port/drv_lcd_spi.c:201

✅ static int show_logo(int argc, char **argv)
  声明: bsp/stm32/stm32h750-weact-ministm32h7xx/board/port/st7735/lcd.c:285
  定义: bsp/stm32/stm32h750-weact-ministm32h7xx/board/port/st7735/lcd.c:264

✅ static int external_sram_test(int argc, char **argv)
  声明: bsp/stm32/stm32f103-100ask-pro/board/ports/drv_sram.c:168
  定义: bsp/stm32/stm32f103-100ask-pro/board/ports/drv_sram.c:96

✅ static int touch_show_state(int argc, char **argv)
  声明: bsp/stm32/stm32f429-st-disco/board/ports/touch/drv_touch.c:211
  定义: bsp/stm32/stm32f429-st-disco/board/ports/touch/drv_touch.c:197

✅ static int external_sram_test(int argc, char **argv)
  声明: bsp/stm32/stm32f103-atk-warshipv3/board/ports/drv_sram.c:167
  定义: bsp/stm32/stm32f103-atk-warshipv3/board/ports/drv_sram.c:95

✅ static int ili9488_test(int argc, char **argv)
  声明: bsp/stm32/stm32h750-artpi/board/port/drv_spi_ili9488.c:1167
  定义: bsp/stm32/stm32h750-artpi/board/port/drv_spi_ili9488.c:1095

✅ static int pwr_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_pwr.c:202
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_pwr.c:171

✅ static int i2c_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_pmic.c:936
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_pmic.c:910

✅ static int wwdg_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_wwdg.c:113
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_wwdg.c:83

✅ static int rcc_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_rcc.c:57
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_rcc.c:29

✅ static int tim_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/timer_sample.c:158
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/timer_sample.c:128

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/spi_sample.c:82
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/spi_sample.c:45

✅ static int lptim_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_lptim.c:159
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/drv_lptim.c:118

✅ static int console(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/OpenAMP/drv_openamp.c:324
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/OpenAMP/drv_openamp.c:298

✅ static int wavplay_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/audio/audio_play.c:140
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/audio/audio_play.c:61

✅ static int wavrecord_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/audio/audio_play.c:260
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/audio/audio_play.c:188

✅ static int crypto(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-discovery/board/ports/crypto/crypto_sample.c:449
  定义: bsp/stm32/stm32mp157a-st-discovery/board/ports/crypto/crypto_sample.c:321

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/stm32/stm32h750-fk750m1-vbt6/board/port/lcd/drv_lcd_spi.c:581
  定义: bsp/stm32/stm32h750-fk750m1-vbt6/board/port/lcd/drv_lcd_spi.c:544

❌ void lcd_fill(int argc, void **argv)
  声明: bsp/stm32/stm32h750-fk750m1-vbt6/board/port/lcd/drv_lcd_spi.c:622
  定义: bsp/stm32/stm32h750-fk750m1-vbt6/board/port/lcd/drv_lcd_spi.c:594
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int camera_sample(int argc, char **argv)
  声明: bsp/stm32/stm32h750-fk750m1-vbt6/board/port/camera/drv_ov2640.c:534
  定义: bsp/stm32/stm32h750-fk750m1-vbt6/board/port/camera/drv_ov2640.c:500

✅ static int sram_test(int argc, char **argv)
  声明: bsp/stm32/stm32l4r9-st-eval/board/ports/drv_sram.c:162
  定义: bsp/stm32/stm32l4r9-st-eval/board/ports/drv_sram.c:90

✅ static int lcd_dsi_test(int argc, char **argv)
  声明: bsp/stm32/stm32l4r9-st-eval/board/ports/drv_lcd_dsi.c:703
  定义: bsp/stm32/stm32l4r9-st-eval/board/ports/drv_lcd_dsi.c:659

❌ void line()
  声明: bsp/stm32/stm32l4r9-st-eval/board/ports/drv_lcd_dsi.c:727
  定义: bsp/stm32/stm32l4r9-st-eval/board/ports/drv_lcd_dsi.c:706
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int camera_sample(int argc, char **argv)
  声明: bsp/stm32/stm32h743-atk-apollo/board/ports/drv_ov2640.c:753
  定义: bsp/stm32/stm32h743-atk-apollo/board/ports/drv_ov2640.c:680

✅ static int led_matrix_test2(int argc, char **argv)
  声明: bsp/stm32/stm32f407-rt-spark/board/ports/led_matrix/drv_matrix_led.c:290
  定义: bsp/stm32/stm32f407-rt-spark/board/ports/led_matrix/drv_matrix_led.c:265

❌ static int lcd_fill_test(int argc, static int **argv)
  声明: bsp/stm32/stm32f407-rt-spark/board/ports/lcd/drv_lcd.c:1490
  定义: bsp/stm32/stm32f407-rt-spark/board/ports/lcd/drv_lcd.c:1462
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int rs485_test(int argc, static int **argv)
  声明: bsp/stm32/stm32f407-rt-spark/board/ports/rs485/drv_rs485.c:138
  定义: bsp/stm32/stm32f407-rt-spark/board/ports/rs485/drv_rs485.c:121
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/stm32/libraries/HAL_Drivers/drv_common.c:39
  定义: bsp/stm32/libraries/HAL_Drivers/drv_common.c:32
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lcd_test(int argc, char **argv)
  声明: bsp/stm32/libraries/HAL_Drivers/drivers/drv_lcd.c:454
  定义: bsp/stm32/libraries/HAL_Drivers/drivers/drv_lcd.c:429

✅ static int camera_sample(int argc, char **argv)
  声明: bsp/stm32/stm32h743-openmv-h7plus/board/ports/drv_ov5640.c:692
  定义: bsp/stm32/stm32h743-openmv-h7plus/board/ports/drv_ov5640.c:601

✅ static int camera_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_ov5640.c:667
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_ov5640.c:578

✅ static int wavplay_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_sound.c:570
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_sound.c:487

✅ static int spdifrx_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_spdifrx.c:302
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_spdifrx.c:240

✅ static int pwr_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_pwr.c:202
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_pwr.c:171

✅ static int dfsdm_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_dfsdm.c:385
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_dfsdm.c:309

✅ static int wwdg_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_wwdg.c:113
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_wwdg.c:83

✅ static int tim_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/timer_sample.c:158
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/timer_sample.c:128

✅ static int fdcan_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_fdcan.c:286
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_fdcan.c:246

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/spi_sample.c:83
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/spi_sample.c:46

✅ static int lptim_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_lptim.c:161
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/drv_lptim.c:120

✅ static int crypto(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/crypto_sample.c:365
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/crypto_sample.c:252

✅ static int uart_dma_sample(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/dma_sample.c:119
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/dma_sample.c:62

✅ static int console(int argc, char **argv)
  声明: bsp/stm32/stm32mp157a-st-ev1/board/ports/OpenAMP/drv_openamp.c:324
  定义: bsp/stm32/stm32mp157a-st-ev1/board/ports/OpenAMP/drv_openamp.c:298

✅ static int reboot(int argc, char **argv)
  声明: bsp/raspberry-pi/raspi4-32/driver/drv_wdt.c:137
  定义: bsp/raspberry-pi/raspi4-32/driver/drv_wdt.c:119

✅ static int reboot(int argc, char **argv)
  声明: bsp/raspberry-pi/raspi3-32/driver/drv_wdt.c:139
  定义: bsp/raspberry-pi/raspi3-32/driver/drv_wdt.c:121

✅ static int test_device(int argc, char **argv)
  声明: bsp/raspberry-pi/raspi3-32/applications/test_device.c:465
  定义: bsp/raspberry-pi/raspi3-32/applications/test_device.c:414

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/raspberry-pi/raspi4-64/drivers/drv_wdt.c:137
  定义: bsp/raspberry-pi/raspi4-64/drivers/drv_wdt.c:119

✅ static int reboot(int argc, char **argv)
  声明: bsp/raspberry-pi/raspi3-64/driver/drv_wdt.c:140
  定义: bsp/raspberry-pi/raspi3-64/driver/drv_wdt.c:122

✅ static int reboot(int argc, char **argv)
  声明: bsp/x86/drivers/board.c:90
  定义: bsp/x86/drivers/board.c:82

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/hc32/libraries/hc32_drivers/drv_common.c:38
  定义: bsp/hc32/libraries/hc32_drivers/drv_common.c:31
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int spi_w25q_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_spi.c:360
  定义: bsp/hc32/tests/test_spi.c:329

✅ static int nand_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_nand.c:284
  定义: bsp/hc32/tests/test_nand.c:273

✅ static int sw_i2c_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_soft_i2c.c:305
  定义: bsp/hc32/tests/test_soft_i2c.c:132

✅ static int uart_sample_v2(int argc, char **argv)
  声明: bsp/hc32/tests/test_uart_v2.c:306
  定义: bsp/hc32/tests/test_uart_v2.c:187

✅ static int pm_sample_init(int argc, char **argv)
  声明: bsp/hc32/tests/test_pm.c:484
  定义: bsp/hc32/tests/test_pm.c:448

✅ static int dac_vol_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_dac.c:120
  定义: bsp/hc32/tests/test_dac.c:31

✅ static int wdt_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_wdt.c:123
  定义: bsp/hc32/tests/test_wdt.c:51

✅ static int sdmmc_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_sdmmc.c:160
  定义: bsp/hc32/tests/test_sdmmc.c:149

✅ static int ipconfig(int argc, char **argv)
  声明: bsp/hc32/tests/test_cherryusb.c:124
  定义: bsp/hc32/tests/test_cherryusb.c:116

❌ static void cherryusb_cdc_send(int argc, char **argv)
  声明: bsp/hc32/tests/test_cherryusb.c:160
  定义: bsp/hc32/tests/test_cherryusb.c:152
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int qspi_w25q_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_qspi.c:570
  定义: bsp/hc32/tests/test_qspi.c:538

✅ static int rtc_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_rtc.c:265
  定义: bsp/hc32/tests/test_rtc.c:76

✅ static int pin_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_gpio.c:81
  定义: bsp/hc32/tests/test_gpio.c:61

✅ static int fal_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_fal.c:135
  定义: bsp/hc32/tests/test_fal.c:40

✅ static int cdc_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_usbd.c:89
  定义: bsp/hc32/tests/test_usbd.c:46

❌ static int hid_sample(void)
  声明: bsp/hc32/tests/test_usbd.c:256
  定义: bsp/hc32/tests/test_usbd.c:214
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int winusb_sample(void)
  声明: bsp/hc32/tests/test_usbd.c:337
  定义: bsp/hc32/tests/test_usbd.c:303
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int usbh_readwrite(const char *filename)
  声明: bsp/hc32/tests/test_usbh.c:103
  定义: bsp/hc32/tests/test_usbh.c:44
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int sdram_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_sdram.c:185
  定义: bsp/hc32/tests/test_sdram.c:174

✅ static int uart_sample_v1(int argc, char **argv)
  声明: bsp/hc32/tests/test_uart_v1.c:279
  定义: bsp/hc32/tests/test_uart_v1.c:160

✅ static int can(int argc, char **argv)
  声明: bsp/hc32/tests/test_can.c:333
  定义: bsp/hc32/tests/test_can.c:305

✅ static int can_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_can.c:408
  定义: bsp/hc32/tests/test_can.c:335

✅ static int eth_webserver(int argc, char **argv)
  声明: bsp/hc32/tests/test_eth.c:75
  定义: bsp/hc32/tests/test_eth.c:67

✅ static int adc_vol_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_adc.c:160
  定义: bsp/hc32/tests/test_adc.c:86

✅ static int encoder_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_pulse_encoder.c:225
  定义: bsp/hc32/tests/test_pulse_encoder.c:163

✅ static int hwtimer_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_hwtimer.c:163
  定义: bsp/hc32/tests/test_hwtimer.c:58

✅ static int i2c_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_i2c.c:273
  定义: bsp/hc32/tests/test_i2c.c:262

✅ static int crypto_sample(int argc, char **argv)
  声明: bsp/hc32/tests/test_crypto.c:333
  定义: bsp/hc32/tests/test_crypto.c:257

❌ static int reboot(uint8_t argc, char **argv)
  声明: bsp/mm32/libraries/HAL_Drivers/drv_common.c:24
  定义: bsp/mm32/libraries/HAL_Drivers/drv_common.c:17
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int _rw007_int(int argc, char *args[])
  声明: bsp/allwinner/d1s/ports/wifi/rw007_pin_port.c:62
  定义: bsp/allwinner/d1s/ports/wifi/rw007_pin_port.c:50
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void _rw007_reset(void)
  声明: bsp/allwinner/d1s/ports/wifi/rw007_pin_port.c:71
  定义: bsp/allwinner/d1s/ports/wifi/rw007_pin_port.c:64
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int _i2c_test(int argc, char *args[])
  声明: bsp/allwinner/libraries/drivers/drv_i2c.c:320
  定义: bsp/allwinner/libraries/drivers/drv_i2c.c:284
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void _pin_test(void)
  声明: bsp/allwinner/libraries/drivers/drv_i2c.c:340
  定义: bsp/allwinner/libraries/drivers/drv_i2c.c:322
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/allwinner/libraries/drivers/drv_wdt.c:108
  定义: bsp/allwinner/libraries/drivers/drv_wdt.c:99

❌ static int lcd_draw_point(int args, char **argv)
  声明: bsp/allwinner/libraries/drivers/drv_lcd.c:807
  定义: bsp/allwinner/libraries/drivers/drv_lcd.c:755
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void lcd_pwm_test(int argc, char **argv)
  声明: bsp/allwinner/libraries/drivers/drv_lcd.c:817
  定义: bsp/allwinner/libraries/drivers/drv_lcd.c:809
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int spi_sample(int argc, char **argv)
  声明: bsp/allwinner/libraries/drivers/drv_spi.c:395
  定义: bsp/allwinner/libraries/drivers/drv_spi.c:333

✅ static int cmd_test_gpio(int argc, char **argv)
  声明: bsp/allwinner/libraries/sunxi-hal/hal/test/gpio/test_gpio.c:141
  定义: bsp/allwinner/libraries/sunxi-hal/hal/test/gpio/test_gpio.c:49

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/allwinner/d1/board/board.c:127
  定义: bsp/allwinner/d1/board/board.c:119

❌ static int sdhci_reg_dump(uint8_t argc, char **argv)
  声明: bsp/cvitek/drivers/drv_sdhci.c:1096
  定义: bsp/cvitek/drivers/drv_sdhci.c:1029
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rt_hw_cpu_reset(int argc, char **argv)
  声明: bsp/cvitek/drivers/drv_por.c:69
  定义: bsp/cvitek/drivers/drv_por.c:53

✅ static int rt_pm_release_mode(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1060
  定义: components/drivers/pm/pm.c:1049

❌ static void rt_pm_release_mode_all(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1073
  定义: components/drivers/pm/pm.c:1062
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_pm_request_mode(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1086
  定义: components/drivers/pm/pm.c:1075
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_module_release_mode(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1102
  定义: components/drivers/pm/pm.c:1088
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_module_release_mode_all(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1118
  定义: components/drivers/pm/pm.c:1104
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_module_request_mode(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1134
  定义: components/drivers/pm/pm.c:1120
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_module_delay_sleep(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1149
  定义: components/drivers/pm/pm.c:1136
  问题:
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_pm_run_mode_switch(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1161
  定义: components/drivers/pm/pm.c:1151
  问题:
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ void pm_sleep_dump(void)
  声明: components/drivers/pm/pm.c:1222
  定义: components/drivers/pm/pm.c:1201
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void pm_sleep_request(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1237
  定义: components/drivers/pm/pm.c:1224
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void pm_sleep_release(int argc, char **argv)
  声明: components/drivers/pm/pm.c:1254
  定义: components/drivers/pm/pm.c:1239
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void rt_pm_dump_status(void)
  声明: components/drivers/pm/pm.c:1296
  定义: components/drivers/pm/pm.c:1257
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int lptimer_dump(int argc, char **argv)
  声明: components/drivers/pm/lptimer.c:179
  定义: components/drivers/pm/lptimer.c:144

✅ static int list_irq(int argc, char **argv)
  声明: components/drivers/pic/pic.c:1309
  定义: components/drivers/pic/pic.c:1168

✅ static int adb_enter(int argc, char **argv)
  声明: components/drivers/usb/cherryusb/platform/rtthread/usbd_adb_shell.c:142
  定义: components/drivers/usb/cherryusb/platform/rtthread/usbd_adb_shell.c:132

✅ static int adb_exit(int argc, char **argv)
  声明: components/drivers/usb/cherryusb/platform/rtthread/usbd_adb_shell.c:156
  定义: components/drivers/usb/cherryusb/platform/rtthread/usbd_adb_shell.c:144

✅ static int usbh_init(int argc, char **argv)
  声明: components/drivers/usb/cherryusb/platform/rtthread/usb_msh.c:44
  定义: components/drivers/usb/cherryusb/platform/rtthread/usb_msh.c:12

❌ 找不到定义: lsusb()
  声明: components/drivers/usb/cherryusb/platform/rtthread/usb_msh.c:46
  定义: 未找到
  问题:
    - 找不到函数定义: lsusb

✅ static int list_thermal(int argc, char **argv)
  声明: components/drivers/thermal/thermal.c:915
  定义: components/drivers/thermal/thermal.c:863

✅ static int sensor_fifo(int argc, char **argv)
  声明: components/drivers/sensor/v1/sensor_cmd.c:179
  定义: components/drivers/sensor/v1/sensor_cmd.c:134

❌ static void sensor_int(int argc, char **argv)
  声明: components/drivers/sensor/v1/sensor_cmd.c:245
  定义: components/drivers/sensor/v1/sensor_cmd.c:201
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void sensor_polling(int argc, char **argv)
  声明: components/drivers/sensor/v1/sensor_cmd.c:294
  定义: components/drivers/sensor/v1/sensor_cmd.c:248
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int sensor(int argc, char **argv)
  声明: components/drivers/sensor/v1/sensor_cmd.c:539
  定义: components/drivers/sensor/v1/sensor_cmd.c:297

✅ static int sensor_fifo(int argc, char **argv)
  声明: components/drivers/sensor/v2/sensor_cmd.c:427
  定义: components/drivers/sensor/v2/sensor_cmd.c:385

❌ static void sensor_int(int argc, char **argv)
  声明: components/drivers/sensor/v2/sensor_cmd.c:490
  定义: components/drivers/sensor/v2/sensor_cmd.c:448
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void sensor_polling(int argc, char **argv)
  声明: components/drivers/sensor/v2/sensor_cmd.c:536
  定义: components/drivers/sensor/v2/sensor_cmd.c:492
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int sensor(int argc, char **argv)
  声明: components/drivers/sensor/v2/sensor_cmd.c:805
  定义: components/drivers/sensor/v2/sensor_cmd.c:557

✅ static int _pin_cmd(int argc, char **argv)
  声明: components/drivers/pin/dev_pin.c:382
  定义: components/drivers/pin/dev_pin.c:353

✅ static int adc(int argc, char **argv)
  声明: components/drivers/misc/adc.c:298
  定义: components/drivers/misc/adc.c:199

✅ static int pwm_list(int argc, char **argv)
  声明: components/drivers/misc/rt_drv_pwm.c:456
  定义: components/drivers/misc/rt_drv_pwm.c:320

✅ static int dac(int argc, char **argv)
  声明: components/drivers/misc/dac.c:232
  定义: components/drivers/misc/dac.c:149

✅ static int ofw_dts(int argc, char **argv)
  声明: components/drivers/ofw/ofw.c:730
  定义: components/drivers/ofw/ofw.c:677

✅ static int list_dma_pool(int argc, char **argv)
  声明: components/drivers/dma/dma_pool.c:692
  定义: components/drivers/dma/dma_pool.c:664

❌ static int sf(uint8_t argc, char **argv)
  声明: components/drivers/spi/dev_spi_flash_sfud.c:812
  定义: components/drivers/spi/dev_spi_flash_sfud.c:552
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int mtd_nand(int argc, char **argv)
  声明: components/drivers/mtd/mtd_nand.c:411
  定义: components/drivers/mtd/mtd_nand.c:345

✅ static int rt_alarm_dump(int argc, char **argv)
  声明: components/drivers/rtc/dev_alarm.c:818
  定义: components/drivers/rtc/dev_alarm.c:789

✅ static int cmd_rtc_sync(int argc, char **argv)
  声明: components/drivers/rtc/dev_soft_rtc.c:437
  定义: components/drivers/rtc/dev_soft_rtc.c:421

✅ static int wifi_msh(int argc, char **argv)
  声明: components/drivers/wlan/dev_wlan_cmd.c:824
  定义: components/drivers/wlan/dev_wlan_cmd.c:782

❌ static int cmd_canstat(int argc, void **argv)
  声明: components/drivers/can/dev_can.c:1215
  定义: components/drivers/can/dev_can.c:1154
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int list_blk(int argc, char **argv)
  声明: components/drivers/block/blk.c:574
  定义: components/drivers/block/blk.c:501

✅ static int lsof(int argc, char **argv)
  声明: components/dfs/dfs_v1/src/dfs.c:1082
  定义: components/dfs/dfs_v1/src/dfs.c:1046

✅ static int dfs_dentry_dump(int argc, char **argv)
  声明: components/dfs/dfs_v2/src/dfs_dentry.c:517
  定义: components/dfs/dfs_v2/src/dfs_dentry.c:498

✅ static int list_fd(int argc, char **argv)
  声明: components/dfs/dfs_v2/src/dfs.c:1151
  定义: components/dfs/dfs_v2/src/dfs.c:1107

❌ int dfs_fd_dump(int argc, char** argv)
  声明: components/dfs/dfs_v2/src/dfs.c:1196
  定义: components/dfs/dfs_v2/src/dfs.c:1162
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ int dfs_dlog(int argc, char** argv)
  声明: components/dfs/dfs_v2/src/dfs.c:1240
  定义: components/dfs/dfs_v2/src/dfs.c:1217
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int dfs_pcache_dump(int argc, char **argv)
  声明: components/dfs/dfs_v2/src/dfs_pcache.c:943
  定义: components/dfs/dfs_v2/src/dfs_pcache.c:887

✅ static int msh_proc_dump(int argc, char **argv)
  声明: components/dfs/dfs_v2/filesystems/procfs/proc.c:620
  定义: components/dfs/dfs_v2/filesystems/procfs/proc.c:606

✅ static int msh_proc_remove(int argc, char **argv)
  声明: components/dfs/dfs_v2/filesystems/procfs/proc.c:670
  定义: components/dfs/dfs_v2/filesystems/procfs/proc.c:622

✅ static int msh_proc_symlink(int argc, char **argv)
  声明: components/dfs/dfs_v2/filesystems/procfs/proc.c:689
  定义: components/dfs/dfs_v2/filesystems/procfs/proc.c:672

✅ static int msh_proc_echo(int argc, char **argv)
  声明: components/dfs/dfs_v2/filesystems/procfs/proc.c:711
  定义: components/dfs/dfs_v2/filesystems/procfs/proc.c:691

✅ static int msh_proc_mkdir(int argc, char **argv)
  声明: components/dfs/dfs_v2/filesystems/procfs/proc.c:733
  定义: components/dfs/dfs_v2/filesystems/procfs/proc.c:713

✅ static int msh_proc_pid(int argc, char **argv)
  声明: components/dfs/dfs_v2/filesystems/procfs/proc_pid.c:447
  定义: components/dfs/dfs_v2/filesystems/procfs/proc_pid.c:435

✅ static int list_symbols(int argc, char **argv)
  声明: components/libc/posix/libdl/dlmodule.c:921
  定义: components/libc/posix/libdl/dlmodule.c:902

❌ int list_module(void)
  声明: components/libc/posix/libdl/dlmodule.c:945
  定义: components/libc/posix/libdl/dlmodule.c:923
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int rtlink_status(int argc, char **argv)
  声明: components/utilities/rt-link/src/rtlink.c:1173
  定义: components/utilities/rt-link/src/rtlink.c:1126

❌ int rt_link_init(void)
  声明: components/utilities/rt-link/src/rtlink.c:1273
  定义: components/utilities/rt-link/src/rtlink.c:1205
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int ulog_be_lvl(uint8_t argc, char **argv)
  声明: components/utilities/ulog/ulog.c:1143
  定义: components/utilities/ulog/ulog.c:1123
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void ulog_tag_lvl(uint8_t argc, char **argv)
  声明: components/utilities/ulog/ulog.c:1165
  定义: components/utilities/ulog/ulog.c:1145
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void ulog_lvl(uint8_t argc, char **argv)
  声明: components/utilities/ulog/ulog.c:1187
  定义: components/utilities/ulog/ulog.c:1167
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void ulog_tag(uint8_t argc, char **argv)
  声明: components/utilities/ulog/ulog.c:1208
  定义: components/utilities/ulog/ulog.c:1189
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void ulog_kw(uint8_t argc, char **argv)
  声明: components/utilities/ulog/ulog.c:1229
  定义: components/utilities/ulog/ulog.c:1210
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void ulog_filter(uint8_t argc, char **argv)
  声明: components/utilities/ulog/ulog.c:1282
  定义: components/utilities/ulog/ulog.c:1231
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int utest_tc_list(int argc, char **argv)
  声明: components/utilities/utest/utest.c:176
  定义: components/utilities/utest/utest.c:161

❌ int utest_testcase_run(int argc, char** argv)
  声明: components/utilities/utest/utest.c:415
  定义: components/utilities/utest/utest.c:368
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int ve_find(int argc, char **argv)
  声明: components/utilities/var_export/var_export_cmd.c:166
  定义: components/utilities/var_export/var_export_cmd.c:124

❌ static int ry(uint8_t argc, char **argv)
  声明: components/utilities/ymodem/ry_sy.c:265
  定义: components/utilities/ymodem/ry_sy.c:240
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int sy(uint8_t argc, char **argv)
  声明: components/utilities/ymodem/ry_sy.c:294
  定义: components/utilities/ymodem/ry_sy.c:267
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int list_kmem(int argc, char **argv)
  声明: components/mm/mm_kmem.c:27
  定义: components/mm/mm_kmem.c:20

✅ static int rt_page_leak_trace_start(int argc, char **argv)
  声明: components/mm/mm_page.c:140
  定义: components/mm/mm_page.c:130

❌ void rt_page_leak_trace_stop()
  声明: components/mm/mm_page.c:168
  定义: components/mm/mm_page.c:162
  问题:
    - 参数argc未使用且未标记RT_UNUSED
    - 参数argv未使用且未标记RT_UNUSED
    - 函数缺少返回语句
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ int list_page(void)
  声明: components/mm/mm_page.c:1041
  定义: components/mm/mm_page.c:998
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int dtb_test(int argc, char **argv)
  声明: components/legacy/fdt/examples/fdt_test.c:124
  定义: components/legacy/fdt/examples/fdt_test.c:4

❌ int dtb_dump(int argc, char** argv)
  声明: components/legacy/fdt/examples/fdt_test.c:145
  定义: components/legacy/fdt/examples/fdt_test.c:126
  问题:
    - 非静态函数在头文件中无声明
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static int fal(rt_uint8_t argc, char **argv)
  声明: components/fal/src/fal_rtt.c:942
  定义: components/fal/src/fal_rtt.c:560
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int list_channel(int argc, char **argv)
  声明: components/lwp/lwp_ipc.c:1331
  定义: components/lwp/lwp_ipc.c:1267

✅ static int list_session(int argc, char **argv)
  声明: components/lwp/lwp_session.c:433
  定义: components/lwp/lwp_session.c:383

✅ static int list_processgroup(int argc, char **argv)
  声明: components/lwp/lwp_pgrp.c:555
  定义: components/lwp/lwp_pgrp.c:505

✅ static int list_shm(int argc, char **argv)
  声明: components/lwp/lwp_shm.c:566
  定义: components/lwp/lwp_shm.c:555

✅ static int dbg(int argc, char **argv)
  声明: components/lwp/lwp_dbg.c:72
  定义: components/lwp/lwp_dbg.c:58

✅ static int list_process(int argc, char **argv)
  声明: components/lwp/lwp_pid.c:1837
  定义: components/lwp/lwp_pid.c:1757

❌ static void cmd_kill(int argc, char** argv)
  声明: components/lwp/lwp_pid.c:1873
  定义: components/lwp/lwp_pid.c:1850
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void cmd_killall(int argc, char** argv)
  声明: components/lwp/lwp_pid.c:1901
  定义: components/lwp/lwp_pid.c:1884
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

❌ static void cmd_cpu_bind(int argc, char** argv)
  声明: components/lwp/lwp_pid.c:2310
  定义: components/lwp/lwp_pid.c:2295
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int msh_help(int argc, char **argv)
  声明: components/finsh/msh.c:57
  定义: components/finsh/msh.c:33

✅ static int cmd_ps(int argc, char **argv)
  声明: components/finsh/msh.c:73
  定义: components/finsh/msh.c:60

✅ static int cmd_free(int argc, char **argv)
  声明: components/finsh/msh.c:94
  定义: components/finsh/msh.c:76

✅ static int cmd_bind(int argc, char **argv)
  声明: components/finsh/msh.c:149
  定义: components/finsh/msh.c:98

✅ static int clear(int argc, char **argv)
  声明: components/finsh/cmd.c:55
  定义: components/finsh/cmd.c:47

✅ static int cmd_list(int argc, char **argv)
  声明: components/finsh/cmd.c:1139
  定义: components/finsh/cmd.c:941

✅ static int cmd_ls(int argc, char **argv)
  声明: components/finsh/msh_file.c:182
  定义: components/finsh/msh_file.c:159

✅ static int cmd_ln(int argc, char **argv)
  声明: components/finsh/msh_file.c:202
  定义: components/finsh/msh_file.c:185

✅ static int cmd_link(int argc, char **argv)
  声明: components/finsh/msh_file.c:221
  定义: components/finsh/msh_file.c:204

✅ static int cmd_cp(int argc, char **argv)
  声明: components/finsh/msh_file.c:240
  定义: components/finsh/msh_file.c:224

✅ static int cmd_mv(int argc, char **argv)
  声明: components/finsh/msh_file.c:299
  定义: components/finsh/msh_file.c:242

✅ static int cmd_cd(int argc, char **argv)
  声明: components/finsh/msh_file.c:484
  定义: components/finsh/msh_file.c:468

✅ static int cmd_pwd(int argc, char **argv)
  声明: components/finsh/msh_file.c:493
  定义: components/finsh/msh_file.c:486

✅ static int cmd_mkdir(int argc, char **argv)
  声明: components/finsh/msh_file.c:510
  定义: components/finsh/msh_file.c:496

✅ static int cmd_mkfs(int argc, char **argv)
  声明: components/finsh/msh_file.c:542
  定义: components/finsh/msh_file.c:512

✅ static int cmd_mount(int argc, char **argv)
  声明: components/finsh/msh_file.c:631
  定义: components/finsh/msh_file.c:552

✅ static int cmd_umount(int argc, char **argv)
  声明: components/finsh/msh_file.c:685
  定义: components/finsh/msh_file.c:634

✅ static int cmd_df(int argc, char **argv)
  声明: components/finsh/msh_file.c:711
  定义: components/finsh/msh_file.c:687

✅ static int cmd_echo(int argc, char **argv)
  声明: components/finsh/msh_file.c:741
  定义: components/finsh/msh_file.c:713

✅ static int cmd_tail(int argc, char **argv)
  声明: components/finsh/msh_file.c:844
  定义: components/finsh/msh_file.c:743

✅ static int cmd_chmod(int argc, char **argv)
  声明: components/finsh/msh_file.c:1142
  定义: components/finsh/msh_file.c:921

✅ static int netdev_ifconfig(int argc, char **argv)
  声明: components/net/netdev/src/netdev.c:1307
  定义: components/net/netdev/src/netdev.c:1274

✅ static int netdev_ping(int argc, char **argv)
  声明: components/net/netdev/src/netdev.c:1454
  定义: components/net/netdev/src/netdev.c:1429

✅ static int netdev_dns(int argc, char **argv)
  声明: components/net/netdev/src/netdev.c:1505
  定义: components/net/netdev/src/netdev.c:1483

✅ static int netdev_netstat(int argc, char **argv)
  声明: components/net/netdev/src/netdev.c:1555
  定义: components/net/netdev/src/netdev.c:1540

✅ static int cmd_ping(int argc, char **argv)
  声明: components/net/lwip/lwip-2.1.2/src/apps/ping/ping.c:239
  定义: components/net/lwip/lwip-2.1.2/src/apps/ping/ping.c:226

❌ static int tftp_server(uint8_t argc, char **argv)
  声明: components/net/lwip/lwip-2.1.2/src/apps/tftp/tftp_port.c:74
  定义: components/net/lwip/lwip-2.1.2/src/apps/tftp/tftp_port.c:53
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int cmd_ping(int argc, char **argv)
  声明: components/net/lwip/lwip-1.4.1/src/apps/ping/ping.c:239
  定义: components/net/lwip/lwip-1.4.1/src/apps/ping/ping.c:226

✅ static int cmd_ping(int argc, char **argv)
  声明: components/net/lwip/lwip-2.0.3/src/apps/ping/ping.c:239
  定义: components/net/lwip/lwip-2.0.3/src/apps/ping/ping.c:226

❌ static int tftp_server(uint8_t argc, char **argv)
  声明: components/net/lwip/lwip-2.0.3/src/apps/tftp/tftp_port.c:74
  定义: components/net/lwip/lwip-2.0.3/src/apps/tftp/tftp_port.c:53
  问题:
    - 函数签名不符合规范：返回类型应为'int'，参数应为'int argc, char **argv'

✅ static int at(int argc, char **argv)
  声明: components/net/at/src/at_cli.c:343
  定义: components/net/at/src/at_cli.c:292

✅ static int mprotect_example_ro_data(int argc, char **argv)
  声明: components/mprotect/examples/mprotect_example_ro_data.c:90
  定义: components/mprotect/examples/mprotect_example_ro_data.c:66

✅ static int mprotect_example_exclusive_region(int argc, char **argv)
  声明: components/mprotect/examples/mprotect_example_exclusive_region.c:77
  定义: components/mprotect/examples/mprotect_example_exclusive_region.c:50

