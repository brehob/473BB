obj-m := mem.o

KDIR  := ${HOME}/kernel/rootfs/lib/modules/3.2.25+/build
PWD   := ${HOME}/mem

default:
	make -C $(KDIR) SUBDIRS=$(PWD) modules
