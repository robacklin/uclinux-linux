#
# Makefile for the linux kernel.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).

USE_STANDARD_AS_RULE := true

O_TARGET	:= cx821xx.o

# Object file lists.

obj-y		:= arch.o cnxtbsp.o cnxttimer.o cnxtirq.o \
		   eeprom.o gpio.o gpioisr.o hstif.o irq.o LnxTools.o \
		   pwrmanag.o sysalib.o sysdev.o syslib.o sysmem.o time.o \
		   ostimer.o gptimer.o 
ifeq ($(CONFIG_CNXT_FLASH),y)
obj-y		+= cnxtflash.o cnxtflashio.o
endif
ifneq ($(CONFIG_CNXT_ADSL),)
obj-y		+= cacheenb.o cnxtadsl.o cnxtsio.o dma.o dmasrv.o \
		   dsl.o dslbase.o dslisr.o iterate.o sysserial.o
endif
ifneq ($(CONFIG_CNXT_GSHDSL),)
obj-y		+= cacheenb.o cnxtadsl.o cnxtsio.o dma.o dmasrv.o \
		   dsl.o dslbase.o dslisr.o iterate.o sysserial.o
endif
ifeq ($(CONFIG_BD_TIBURON),y)
obj-y		+= tiburon-softreset.o
endif
obj-m		:=
obj-n		:=
obj-		:=

export-objs	:= cnxtbsp.o cnxttimer.o cnxtirq.o eeprom.o gpio.o gpioisr.o irq.o \
	           LnxTools.o pwrmanag.o ostimer.o gptimer.o
ifeq ($(CONFIG_CNXT_FLASH),y)
export-objs	+= cnxtflash.o
endif
ifneq ($(CONFIG_CNXT_ADSL),)
export-objs	+= cnxtadsl.o cnxtsio.o dma.o dmasrv.o dslbase.o iterate.o
endif
ifneq ($(CONFIG_CNXT_GSHDSL),)
export-objs	+= cnxtadsl.o cnxtsio.o dma.o dmasrv.o dslbase.o iterate.o
endif

obj-$(CONFIG_LEDS) += leds.o

include $(TOPDIR)/Rules.make
