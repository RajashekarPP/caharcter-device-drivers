#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

#ifndef DEVNAME
#define DEVNAME "MyCharDev"   //Name of the character driver
#endif

#ifndef MAJORNO
#define MAJORNO	0
#endif

#ifndef DEVCOUNT
#define DEVCOUNT	1	//No of the devices
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
