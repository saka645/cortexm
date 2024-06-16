//(A+8B+7C-27)/4
//A=25,B=19,C=99


.syntax unified
.cpu cortex-m0
.thumb
.section .text
.global __main

__main:
//r0=a+8b
adds r0,r0,r1,lsl,#3

movs r1,#99
movs r2,#7

//add 7c to r0 and put result in r0
mla r0,r1,r2,r0 //r0= r1r2+r0
subs r0,r0,#27

//divide the total by 4
movs r0,r0,asr #2  please correct it


next:
	adds r0,r0,#1
	subs r3,r3,#1

	//branch to begin if result is not equal to zero
	bne begin

stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
