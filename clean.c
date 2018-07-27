#include"headers.h"
#include"declarations.h"

extern dev_t Dev_Id;

void __exit MyCharDev_exit(void)
{	
	printk(KERN_INFO , "Exiting driver\n");
	unregister_chrdev_region(Dev_Id , DEVICE_COUNT);
	printk(KERN_INFO "unregistering has been done\n");
}

module_exit(MyCharDev_exit);



