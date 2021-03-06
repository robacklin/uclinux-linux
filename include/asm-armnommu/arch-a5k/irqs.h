/*
 * linux/include/asm-arm/arch-a5k/irqs.h
 *
 * Copyright (C) 1996 Russell King
 */

#define IRQ_PRINTER		0
#define IRQ_BATLOW		1
#define IRQ_FLOPPYINDEX		2
#define IRQ_VSYNCPULSE		3
#define IRQ_POWERON		4
#define IRQ_TIMER0		5
#define IRQ_TIMER1		6
#define IRQ_IMMEDIATE		7
#define IRQ_EXPCARDFIQ		8
#define IRQ_SOUNDCHANGE		9
#define IRQ_SERIALPORT		10
#define IRQ_HARDDISK		11
#define IRQ_FLOPPYDISK		12
#define IRQ_EXPANSIONCARD	13
#define IRQ_KEYBOARDTX		14
#define IRQ_KEYBOARDRX		15

#define FIQ_FLOPPYDATA		0
#define FIQ_ECONET		2
#define FIQ_SERIALPORT		4
#define FIQ_EXPANSIONCARD	6
#define FIQ_FORCE		7
