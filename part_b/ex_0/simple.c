#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int simple_init(void){
    printk(KERN_INFO "simple loaded.\n");
    return 0;
}

void simple_exit(void){
    printk(KERN_INFO "simple exited.\n");
}

module_init(simple_init);
module_exit(simple_exit);


MODULE_LICENSE("WTFPL");
MODULE_DESCRIPTION("Simple");
MODULE_AUTHOR("User");
