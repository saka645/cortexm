//(A+8B+7C-27)/4
//A=25,B=19,C=99


.syntax unified
.cpu cortex-m0
.thumb
.section .text
.global __main

__main:
	movs r6,#4 //4 factorial
	movs r7,#1

loop:
	cmp r6,#0

	//execute next three instructions if r6 > 0
	ittt GT
	mulgt r7,r6,r7 //multiply r6 with r7 if r6 is greater 0
	subgt r6,r6,#1 //subtract r6 with 1 if r6 is greater than 0
	bgt loop   //branch to loop if r6 is greater than 0




stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
