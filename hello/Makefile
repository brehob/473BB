obj-m := hello.o

KDIR  := ${HOME}/kernel/rootfs/lib/modules/3.2.25+/build
PWD   := ${HOME}/hello

default:
	make -C $(KDIR) SUBDIRS=$(PWD) modules
