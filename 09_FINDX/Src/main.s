count   .req r0
max     .req r1
pointer .req r2
next    .req r3

mydata:
    .word  69       // Declaring a floating-point number
    .word  86          // Declaring an integer
    .word  45          // Declaring an integer
    .word  75          // Declaring an integer


.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb
.section .text
.global __main

__main:
	movs count,#4
	movs max,#0
	//load add in r2//
	ldr pointer,=mydata
again:
	//load value at address into next//
	ldr next,[pointer]

	//compare next with max and update conditional flag//
	cmp max,next

	//branch to continue if max>=next//
	bhs cont
	movs max,next

cont://add 4 bytes to pointer
	adds pointer,pointer,#4

	//decrement the counter and update conditional flag//
	subs count,count,#1

	//branch if result is not equal to zero//
	bne again

stop:
	b	stop
	.align
	.end
