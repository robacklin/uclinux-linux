#include <linux/config.h>
	
	.global _start
	.global _stext

	.global _rambase
	.global _ramvec
	.global _ramstart
	.global _ramend

#ifdef CONFIG_INIT_LCD
	.global splash_bits
#endif

	.data

/*
 *      Set up the usable of RAM stuff. Size of RAM is determined then
 *      an initial stack set up at the end.
 */
.align 4
_ramvec:
.long   0
_rambase:
.long   0
_ramstart:
.long   0
_ramend:
.long   0

#ifdef CONFIG_INIT_LCD
splash_bits:
#include "bootlogo.rh"
#endif
	
	.text
_start:
_stext:	movew	#0x2700,%sr
#ifdef CONFIG_INIT_LCD
	movel	#splash_bits, 0xfffffA00 /* LSSA */
	moveb	#0x28,   0xfffffA05	/* LVPW:	640 bits wide */
	movew	#0x280,  0xFFFFFa08	/* LXMAX:	640 pixels */
	movew	#0x1df,  0xFFFFFa0a	/* LYMAX:	lines=479+1 */
	moveb	#0,      0xfffffa29	/* LBAR:	
					 * - actually LRRA - frame period
					 * = (12+xmax+rra)*ymax*(pxcd+1)*
					 *   ldclk_period */
	moveb	#0,      0xfffffa25	/* LPXCD:	lcdclk divisor-1 */
	moveb	#0x08,   0xFFFFFa20	/* LPICF:	panel bus w.= 4bit */
	moveb	#0x01,   0xFFFFFA21	/* LPOLCF:	-ve polarity */
	moveb	#0xff,   0xfffff413	/* PCSEL:	LCD pins */
	moveb	#0x81,   0xfffffA27	/* LCKCON:	lcd enable (+1?) */
#endif

#ifdef CONFIG_DIRECT_IO_ACCESS
	moveb	#0x0,	0xfffff000
#endif

	moveal  #__ramend-CONFIG_MEMORY_RESERVE*0x100000 - 0x10, %sp
	movew	#32767, %d0  /* PLL settle wait loop */
1:	subq	#1, %d0
	bne	1b

	/* Copy data segment from ROM to RAM */
	moveal	#__data_rom_start, %a0
	moveal	#_sdata, %a1
	moveal	#_edata, %a2

	/* Copy %a0 to %a1 until %a1 == %a2 */
1:	movel	%a0@+, %a1@+
	cmpal	%a1, %a2
	bhi	1b

	moveal	#_sbss, %a0
	moveal	#_ebss, %a1
	/* Copy 0 to %a0 until %a0 == %a1 */
	
1:
	clrl	%a0@+
	cmpal	%a0, %a1
	bhi	1b

        movel   #_sdata, %d0    
        movel   %d0,    _rambase        
        movel   #_ebss,  %d0
        movel   %d0,    _ramstart
	movel	#__ramend-CONFIG_MEMORY_RESERVE*0x100000, %d0
	movel	%d0,	_ramend
	movel	#__ramvec,	%d0
	movel	%d0,	_ramvec

#ifdef CONFIG_68328_SERIAL_UART2
	/* Enable RXD TXD port bits to enable UART2 */
	moveb	#0xcf,   0xfffff43b
#endif	
	
/*
 * load the current task pointer and stack
 */
        lea     init_task_union,%a0
        movel   %a0, _current_task
        lea     0x2000(%a0),%sp

1:	jsr	start_kernel
        bra 1b
_exit:

	jmp	_exit


putc:
	moveb	%d7,0xfffff907
1:
	movew	0xfffff906, %d7
	andw	#0x2000, %d7
	beq	1b
	rts

	.data
env:
	.long	0
	.text

