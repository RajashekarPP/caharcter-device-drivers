#include"headers.h"
#include"declarations.h"



ssize_t writeDev(struct file *filep, const char __user *buff, size_t count, loff_t *f_pos)
{
	printk(KERN_INFO "BEGINS %s\n",__func__);

	printk(KERN_INFO "ENDS %s\n",__func__);

	return 0;
}

