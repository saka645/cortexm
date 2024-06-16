//(A+8B+7C-27)/4
//A=25,B=19,C=99


.syntax unified
.cpu cortex-m0
.thumb
.section .text
.global __main

__main:

	ldr r0,=60
	movs r1,#10
	movs r2,#0

again:
	cmp r0,r1
	//branch to stop if r0 is less than r1
	blo stop

	subs r0,r0,r1
	adds r2,r2,#1
	b again





stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
