#include"headers.h"
#include"declarations.h"

int openDev(struct inode *inodep, struct file *filep)
{
	struct myDev *localdevice;
	printk(KERN_INFO "Begins %s\n" , __func__);
	localdevice = container_of( inodep->i_cdev , struct myDev , cdev); //Its is a macro defined 
	filep->private_data = localdevice ; //stores the data related to one of the device pointed by VFS
	if((filep->f_flags & O_ACCMODE ) == O_RDONLY )	
	{
		printk(KERN_INFO "File opened in READ mode");
	}
	else if((filep->f_flags & O_ACCMODE ) == O_WRONLY )	
	{
		printk(KERN_INFO "File opened in WRITE mode");
	}
	else
	{
		printk(KERN_INFO "FILE opened in wrong mode \n");
	}
	printk(KERN_INFO "Ends %s\n" , __func__);
	return 0;
}

