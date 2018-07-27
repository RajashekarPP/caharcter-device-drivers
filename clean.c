#include"headers.h"
#include"declarations.h"

extern dev_t Dev_Id;

void __exit MyCharDev_exit(void)
{	
	printk(KERN_INFO , "Exiting from the character driver\n");
	if(unregister_chardev_region(Dev_Id , DEVNO) < 0)
	{
		printk(KERN_ALERT "unregistering has not been done\n");
	}
	printk(KERn_INFO "unregistering has been done\n");
}

module_exit(MyCharDev_exit);



