/*
 * linux/include/asm-arm/arch-a5k/processor.h
 *
 * Copyright (c) 1996 Russell King.
 *
 * Changelog:
 *  10-09-1996	RMK	Created
 */

#ifndef __ASM_ARCH_PROCESSOR_H
#define __ASM_ARCH_PROCESSOR_H

/*
 * Bus types
 */
#define EISA_bus 0
#define EISA_bus__is_a_macro /* for versions in ksyms.c */
#define MCA_bus 0
#define MCA_bus__is_a_macro /* for versions in ksyms.c */

/*
 * User space: 26MB
 */
#define TASK_SIZE	(0x01a00000UL)

#define INIT_MMAP	{ &init_mm, 0, 0x02000000, PAGE_SHARED, VM_READ | VM_WRITE | VM_EXEC }

#endif
