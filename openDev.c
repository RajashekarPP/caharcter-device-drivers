#include"headers.h"
#include"declarations.h"

int openDev(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Begins %s\n" , __func__);

	printk(KERN_INFO "Ends %s\n" , __func__);

	return 0;
}
