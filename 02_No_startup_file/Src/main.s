.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main
.global Reset_Handler

Reset_Handler:
	movs r1,#100
	movs r2,#126


__main:
	movs r5,#45
	movs r3,#45
	adds r6,r5,r3

stop:
	b	stop
	.align
	.end
