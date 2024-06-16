

.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main

__main:
	ldr r0,=0xBABEFACE;
	ldr r1,=0xDEADBEEF;
	eors r0,r0,r1;
	eors r1,r0,r1;
	eors r0,r0,r1;

stop:
	b	stop
	.align
	.end
