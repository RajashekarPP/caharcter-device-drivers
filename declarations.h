#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

#ifndef DEVICE_NAME
#define DEVICE_NAME "MyCharDev"   //Name of the character driver
#endif

#ifndef MAJORNO
#define MAJORNO	0
#endif

#ifndef DEVICE_COUNT
#define DEVICE_COUNT	1	//No of the devices
#endif

#ifndef SUCESS
#define SUCESS 0
#endif

#ifndef FAIL
#define FAIL -1
#endif

extern int majorno;
extern int minorno;
extern int devicesCount;

#endif

struct myQset 
{
	char *data;
};

struct myDev 
{
	struct myQset *data;
	int quantum;	
	int qset;
	unsigned long size;	
	struct cdev cdev;
	
};


extern int deletemydevices(void);
int openDev(struct inode *, struct file *);
int releaseDev(struct inode *, struct file *);
ssize_t readDev(struct file *, char *, size_t, loff_t *);
ssize_t writeDev(struct file *, const char *, size_t, loff_t *);
loff_t llseekDev (struct file *, loff_t, int);




