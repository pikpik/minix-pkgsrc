/*	inb() - Input one byte				Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	unsigned inb(U16_t port); */
#include <machine/asm.h>

#undef ENTRY
#define ENTRY(l) l:

ENTRY(inb)
	push	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx	/* port */
	xorl	%eax, %eax
	inb	%dx	/* read 1 byte */
	pop	%ebp
	ret
/*	inl() - Input one dword				Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	unsigned inl(U16_t port); */
#include <machine/asm.h>

ENTRY(inl)
	push	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx	/* port */
	inl	%dx	/* read 1 dword */
	pop	%ebp
	ret
/*	intr_disable(), intr_enable - Disable/Enable hardware interrupts. */
/*							Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	void intr_disable(void); */
/*	void intr_enable(void); */
#include <machine/asm.h>

ENTRY(intr_disable)
	cli
	ret

ENTRY(intr_enable)
	sti
	ret
/*	inw() - Input one word				Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	unsigned inw(U16_t port); */
#include <machine/asm.h>

ENTRY(inw)
	push	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx	/* port */
	xorl	%eax, %eax
	inw	%dx	/* read 1 word */
	pop	%ebp
	ret
/*	outb() - Output one byte			Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	void outb(U16_t port, U8_t value); */
#include <machine/asm.h>

ENTRY(outb)
	push	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx	/* port */
	movl	8+4(%ebp), %eax	/* value */
	outb	%dx	/* output 1 byte */
	pop	%ebp
	ret
/*	outl() - Output one dword			Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	void outl(U16_t port, u32_t value); */
#include <machine/asm.h>

ENTRY(outl)
	push	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx	/* port */
	movl	8+4(%ebp), %eax	/* value */
	outl	%dx	/* output 1 dword */
	pop	%ebp
	ret
/*	outw() - Output one word			Author: Kees J. Bot */
/*								18 Mar 1996 */
/*	void outw(U16_t port, U16_t value); */
#include <machine/asm.h>

ENTRY(outw)
	push	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx	/* port */
	movl	8+4(%ebp), %eax	/* value */
	outw	%dx	/* output 1 word */
	pop	%ebp
	ret

.globl inb
.globl inl
.globl intr_disable
.globl intr_enable
.globl inw
.globl outb
.globl outl
.globl outw
