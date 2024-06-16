
val1 .req r1
val2 .req r2
sum .req r3

.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main

__main:
	movs val1,#45
	movs val2,#45
	adds sum,val1,val2

stop:
	b	stop
	.align
	.end
