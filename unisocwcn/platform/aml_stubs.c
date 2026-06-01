/* OOB IRQ via /wifi node + gpio_intc; trigger HIGH per vendor meson1_0.dts. */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/of_irq.h>

#define WCN_PFX "aml_stubs: "

static int g_wifi_irq = -1;

int wifi_irq_num(void)
{
	struct device_node *np;

	if (g_wifi_irq > 0)
		return g_wifi_irq;

	np = of_find_node_by_name(NULL, "wifi");
	if (!np) {
		pr_err(WCN_PFX "no /wifi node\n");
		return -1;
	}
	g_wifi_irq = irq_of_parse_and_map(np, 0);
	pr_info(WCN_PFX "wifi_irq_num: irq=%d (via gpio_intc)\n", g_wifi_irq);
	if (g_wifi_irq <= 0) {
		g_wifi_irq = -1;
		return -1;
	}
	return g_wifi_irq;
}

int wifi_irq_trigger_level(void)
{
	/* GPIO_IRQ_HIGH = 0 per vendor convention */
	return 0;
}

void extern_wifi_set_enable(int is_on) { (void)is_on; }
void extern_bt_set_enable(int is_on)   { (void)is_on; }
void sdio_reinit(void) { }
void sdio_clk_always_on(int on) { (void)on; }
void sdio_set_max_reqsz(unsigned int size) { (void)size; }
