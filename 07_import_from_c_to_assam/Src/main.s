

.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.globl __main
.globl num
.globl Adder

__main:
	ldr r1,=num
	movs r0,#100
	str r0,[r1]
	bl Adder


stop:
	b	stop
	.align
	.end
