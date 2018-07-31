#include"headers.h"
#include"declarations.h"



ssize_t writeDev(struct file *filep, const char __user *buff, size_t count, loff_t *f_pos)
{

	int i,k,ret;
	int no_of_qsets , remno_of_quantums , byteswritten =0 ;//datasize = count;
	struct myDev *device = NULL ;
	struct myQset *head =NULL ; //head pointer used to store  the address of the first quantum set

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
	head = device->data = kmalloc (sizeof(struct myQset) , GFP_KERNEL) ;
	memset ( head , 0 ,sizeof(struct myQset) );

	no_of_qsets = count/((size_of_registers)*(no_of_registers));
	if(  count%((size_of_registers)*(no_of_registers)))
	{
		no_of_qsets++;
	}

	// this calculation is only for data less than one qset size
	/*
	   if(count % size_of_registers)
	   {
	   remno_of_quantums++;
	   }
	 */

	if( !head)
	{
		return -1;
	}
	/*
	   for(i=0;i<no_of_qsets;i++)
	   {
	   for(



	   }
	 */

	remno_of_quantums = count/size_of_registers;
	for(i=0;i<remno_of_quantums;i++)
	{
		head->data[i] = kmalloc( no_of_registers*(sizeof(char*)) , GFP_KERNEL);
	}

	for(k=0 ; k<remno_of_quantums ;k++)
	{
		ret = copy_from_user( (char*)head->data[k] , buff+byteswritten , size_of_registers);
		if(!ret)
		{
			byteswritten += size_of_registers;
			*f_pos = byteswritten;
			count -= size_of_registers;
		}
	}
	if( count % size_of_registers )
	{
		ret = copy_from_user ( (char *)head->data[k++] , buff+byteswritten , count);
		byteswritten += count;
		*f_pos = byteswritten;
	}

	printk(KERN_INFO "Bytes written = %d\n",byteswritten);

	device->size = byteswritten ;

	printk(KERN_INFO "ENDS %s\n",__func__);
	return byteswritten;
}

