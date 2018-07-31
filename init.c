#include "headers.h"
#include "declarations.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAJA SHEKAR");
MODULE_DESCRIPTION("MY CHARACTER DEVICE DRIVER");

dev_t Dev_Id = 0;
int majorno = MAJORNO;
int minorno = 0 ;     // default we will assign 0 as minor number
int deviceno = DEVICE_COUNT;

int no_of_registers = NUM_REGISTRES;
int size_of_registers = SIZE_REGISTRES;

struct myDev *myDevices;        

static struct file_operations fops = {
	open:openDev,
	//release:releaseDev,
	read:readDev,
	write:writeDev,
	//llseek:llseekDev
};

static int __init MyCharDev_init(void)
{
	int ret , err=0, i;
	printk(KERN_INFO "character device driver init started\n");
	/*
	//This is the old method of  registering of the device

	majorno = register_chrdev(majorno , DEVICE_NAME ,&fops )   //it returns 0 on sucess

	printk(KERN_ALERT "NOT registered\n");
	printk(KERN_INFO "Major NO = %d \n",MAJOR(Dev_Id) );
	 */

	if(alloc_chrdev_region(&Dev_Id , 0 , deviceno , DEVICE_NAME ) < 0)
	{
		return FAIL;
	}

	majorno = MAJOR(Dev_Id);
	minorno = MINOR(Dev_Id);
	printk(KERN_INFO "Major no = %d\tMinor No = %d\n",majorno,minorno);

	myDevices = kmalloc(deviceno*sizeof(struct myDev) , GFP_KERNEL );
	if(!myDevices)
	{
		ret = -1;
		goto fail;
	}

	memset(myDevices , 0 , deviceno*sizeof(struct myDev) );
	for(i=0 ; i<deviceno ; i++)
	{
		cdev_init(&myDevices[i].cdev , &fops);
		myDevices[i].cdev.ops = &fops;
		Dev_Id = MKDEV(majorno, i);
		err = cdev_add (&myDevices[i].cdev, Dev_Id, 1);

		if (err)
			printk(KERN_NOTICE "Error %d adding scull%d", err, i);
		printk(KERN_INFO "majorno:%d minorno:%d\n",MAJOR(Dev_Id) , MINOR(Dev_Id));
	}

	return SUCESS;
fail :
	deletemydevices();
	return err;
}


module_init(MyCharDev_init);

