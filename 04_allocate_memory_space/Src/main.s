

.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main

__main:
	ldr r0,=A //point r0 to memory loc A
	movs r1,#5
	str r1,[r0]//store content or r1 to memory location specified by r0

stop:
	b	stop


	.section .data

A:	.space 4 //allocate 4 bytes of memory filled with zero
B:	.space 4 //allocate 4 bytes of memory filled with zero
C:	.space 4 //allocate 4 bytes of memory filled with zero

	.align
	.end
