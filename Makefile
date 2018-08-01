INSTALL_DIR = modules
obj-m := MyCharDev.o
MyCharDev-objs := init.o clean.o openDev.o readDev.o writeDev.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	rm -rf $(INSTALL_DIR) 
	mkdir $(INSTALL_DIR)
	mv -f *.o *mod.c *.ko .*.cmd *.order *.symvers $(INSTALL_DIR)
clean:
	rm -rf $(INSTALL_DIR)


