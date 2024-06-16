
.syntax unified
.cpu cortex-m0
.thumb
.section .text
.global __main

__main:

	ldr r3,=0xdeadbeef
	ldr r4,=0xbabeface
	push {r3}
	push {r4}
	pop  {r5}
	pop  {r6}



stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
