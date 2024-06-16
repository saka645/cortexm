
.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main

__main:
	movs r0,#11
	lsls r1,r0,#1

stop:
	b	stop
	.align
	.end
