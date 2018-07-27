#include "headers.h"
#include "declarations.h"

MODULE_LICENSE("GPL");

dev_t Dev_Id = 0;
int majorno = MAJORNO;
int minorno = 0 ;     // default we will assign 0 as minor number


static int __init MyCharDev_init(void)
{
	printk(KERN_INFO "character device driver init started\n");
	if(register_chrdev_region(Dev_Id , DEVICE_COUNT , DEVICE_NAME ) < 0)
		printk(KERN_ALERT "NOT registered\n");

	if(alloc_chrdev_region(&Dev_Id , 0 ,DEVICE_COUNT , DEVICE_NAME ) < 0)
	{
		return FAIL;
	}

	majorno = MAJOR(Dev_Id);
	minorno = MINOR(Dev_Id);	

	printk(KERN_INFO "Major no = %d\tMinor No = %d\n",majorno,minorno); 

	return SUCESS;
}


module_init(MyCharDev_init);




