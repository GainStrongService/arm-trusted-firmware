#!/bin/bash

# make -f Makefile CROSS_COMPILE=/usr/bin/aarch64-linux-gnu- PLAT=mt7981 BOARD_BGA=1 BL33=../u-boot/u-boot.bin BOOT_DEVICE=nor DRAM_USE_DDR4=0 all fip

make -f Makefile distclean

make
