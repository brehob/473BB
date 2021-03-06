// Taken from https://github.com/furiousgreencloud/beagleboneIO/blob/master/src/beaglegpiomem.h
#ifndef _GPIO_MMAP_H
#define _GPIO_MMAP_H


#define MMAP_OFFSET 0x44c00000
#define MMAP_SIZE (0x48ffffff-MMAP_OFFSET)

#define GPIO0 (0x44e07000-MMAP_OFFSET)
#define GPIO1 (0x4804c000-MMAP_OFFSET)
#define GPIO2 (0x481ac000-MMAP_OFFSET)
#define GPIO3 (0x481ae000-MMAP_OFFSET)

#define GPIO_OE 0x134
#define GPIO_DATAIN 0x138
#define GPIO_DATAOUT 0x13c
#define GPIO_CLEARDATAOUT 0x190
#define GPIO_SETDATAOUT 0x194

#define OUT 0
#define IN 1

#endif // _GPIO_MMAP_H
