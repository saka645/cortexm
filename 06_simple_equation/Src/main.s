
//P=Q+R+S=2+4+5

Q = 2
R = 4
S = 5

.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main

__main:
	movs r1, #Q
	movs r2, #R
	movs r3, #S
	adds r0, r1, r2 //add r1 and r2, store result in r0
	adds r0, r0, r3 //add r0 and r3, store result in r0

stop:
	b	stop
	.align
	.end
