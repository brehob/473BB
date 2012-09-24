obj-m := gpioD.o

KDIR  := ${HOME}/kernel/rootfs/lib/modules/3.2.25+/build
PWD   := ${HOME}/473BB/gpio_driver

default:
	make -C $(KDIR) SUBDIRS=$(PWD) modules
