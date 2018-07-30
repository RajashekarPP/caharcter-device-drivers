#ifndef __HEADERS_H_
#define __HEADERS_H_

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>     	/*fops struct "file struct" "struct inode" are defined in it */
#include <linux/cdev.h>
#include<linux/slab.h>		/* kmalloc and kfree */
#include <linux/moduleparam.h>
#include <linux/errno.h>        /* error codes */
#include <linux/proc_fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>        /* copy_*_user */
#include <linux/uaccess.h>


#endif /*End of Headers.h*/


