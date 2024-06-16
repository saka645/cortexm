.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.globl num_fun


num_fun:
	movs r0,#123
	bx lr

	.align
	.end
