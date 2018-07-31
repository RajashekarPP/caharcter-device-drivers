#include"headers.h"
#include"declarations.h"

ssize_t readDev(struct file *filep , char __user *buf , size_t count , loff_t *f_pos)
{
	
	printk(KERN_INFO "Data read\n");
	return 0;
}
