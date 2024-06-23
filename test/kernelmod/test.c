// test.c

#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */

MODULE_LICENSE("Same as NMap - that doesn't make sense...");
MODULE_AUTHOR("ur mom lol")
MODULE_DESCRIPTION("describe ur mom? sure thing!")

static int __init hello_start(void)
{
printk(KERN_INFO "Loading hello module...\n");
printk(KERN_INFO "Hello world\n");
return 0;
}

static void __exit hello_end(void)
{
printk(KERN_INFO "Goodbye Mr.\n");
}

module_init(hello_start);
module_exit(hello_end);

