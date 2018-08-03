#include"headers.h"
#include"declarations.h"



ssize_t writeDev(struct file *filep, const char __user *buff, size_t count, loff_t *f_pos)
{

	int ret;
	int byteswritten =0 ;//datasize = count;
	struct myDev *device ;
	struct myQset *head ; //head pointer used to store  the address of the first quantum set

	printk(KERN_INFO "BEGINS %s\n",__func__);
	device = filep->private_data;
	head = device -> data;
	if( (filep->f_flags & O_ACCMODE ) != O_WRONLY)	
	{
		printk(KERN_INFO "File not opened in write mode\n");
		return -1;
	}
	if( !buff || (count<=0) )
	{
		printk(KERN_INFO "buffer or data size is not proper\n");
		return -1;
	}
	// allocation of memory for only one quantum set
	head = device->data =kmalloc (sizeof(struct myQset) , GFP_KERNEL) ;
	memset ( head , 0 , count);

	if( !head)
	{
		return -1;
	}

	head->data = kmalloc ( count , GFP_KERNEL );
	memset( head->data , 0 , count );

	ret = copy_from_user( head->data , buff+byteswritten , strlen(buff) );
	if(!ret)
	{
		byteswritten += strlen(buff);
		*f_pos = byteswritten;
	}

	printk(KERN_INFO "Bytes written = %d\n",byteswritten);
	device->size = byteswritten ;

	printk(KERN_INFO "ENDS %s\n",__func__);
	return byteswritten;
}

