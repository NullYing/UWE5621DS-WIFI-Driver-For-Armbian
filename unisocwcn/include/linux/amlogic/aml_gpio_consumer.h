/* Stub for Armbian/mainline kernel that lacks Amlogic BSP private headers.
 * Power and reset are handled by mmc-pwrseq-simple in DTS (wifi-pwrseq).
 */
#ifndef _AML_GPIO_CONSUMER_STUB_H_
#define _AML_GPIO_CONSUMER_STUB_H_

#include <linux/mmc/host.h>

#ifndef GPIO_IRQ_HIGH
#define GPIO_IRQ_HIGH 0
#endif
#ifndef GPIO_IRQ_LOW
#define GPIO_IRQ_LOW  1
#endif

/* mmc_power_save_host / mmc_power_restore_host were removed in kernel 5.7+.
 * For our use (Amlogic SDIO WiFi), mmc-pwrseq-simple handles real power cycle.
 */
static inline void mmc_power_save_host(struct mmc_host *host) { (void)host; }
static inline void mmc_power_restore_host(struct mmc_host *host) { (void)host; }

#endif
