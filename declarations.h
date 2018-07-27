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
