#include "board.h"
#include "lwip/tcpip.h"
#include "usbh_core.h"
#include <rtthread.h>

int usb_init(void)
{
    rt_thread_mdelay(10000); // 等待系统稳定
    rt_kprintf("USB init...\n");
    usbh_initialize(0, USB_OTG_HS_PERIPH_BASE);
    return RT_EOK;
}
INIT_APP_EXPORT(usb_init);