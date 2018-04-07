/* Based on https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Proprietary");
MODULE_AUTHOR("Walter Sosa");
MODULE_DESCRIPTION("My first module");
MODULE_VERSION("0.1.0");

static int __init wasosa_kernel_module_init(void) {
  printk(KERN_INFO "[LOADING] Look at me! Look at me! I'm alive!\n");
  return 0;
}

static void __exit wasosa_kernel_module_exit(void) {
  printk(KERN_INFO "[UNLOADING] Oh well, it was nice while it lasted.\n");
}

module_init(wasosa_kernel_module_init);
module_exit(wasosa_kernel_module_exit);
