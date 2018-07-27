INSTALL_DIR = modules
obj-m := mychardev.o
mychardev-objs := init.o clean.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	@mkdir $(INSTALL_DIR)
	@mv -f *.o *mod.c *.ko .*.cmd modules

clean:
	rm -rf modules


