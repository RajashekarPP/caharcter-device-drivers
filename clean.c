#include"headers.h"
#include"declarations.h"

extern dev_t Dev_Id;
extern int majorno;
extern int minorno;
extern int deviceno;
extern struct myDev *mydevices;


void __exit MyCharDev_exit(void)
{	
	printk(KERN_INFO  "Exiting driver\n");
	deletemydevices();
	printk(KERN_INFO "unregistering has been done\n");
}


int deletemydevices()
{
	int i;
	for( i=0 ; i<deviceno ; i++)
	{
		Dev_Id=MKDEV(majorno,i);
		cdev_del(&mydevices[i].cdev);
		unregister_chrdev_region(Dev_Id , 1);
	}
	kfree(mydevices);

}

module_exit(MyCharDev_exit);
