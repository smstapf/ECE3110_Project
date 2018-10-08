#define MODULE
#define LINUX
#define _KERNEL_

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int init(void){
	printk("<1>Hello World 1.\n");

	return(0);
}

void cleanup(void){
	printk(KERN_ALERT "Goodbye world 1.\n");
}

module_init(init);
module_exit(cleanup);

MODULE_LICENSE("GPL");
