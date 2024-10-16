.equ RCC_BASE, 				0x40021000
.equ AHB_ENR_OFFSET, 		0x14
.equ RCC_AHBENR,			(RCC_BASE + AHB_ENR_OFFSET)
.equ GPIOC_BASE, 			0x48000800

.equ GPIOC_EN, 				(1<<19)
.equ GPIOC_ODR8, 			(1<<8)

.equ GPIOC_OFFSET, 			0x00
.equ GPIOC_MODER,			(GPIOC_BASE + GPIOC_OFFSET)
.equ GPIOC8_GPIO, 			(1<<16)

.equ GPIOC_ODR_OFFSET, 		0x14
.equ GPIOC_ODR,				(GPIOC_BASE + GPIOC_ODR_OFFSET)

.syntax unified
.cpu cortex-m0
.thumb
.section .text
.global __main

__main:
	//LOAD AHB REG IN R0
	ldr r0,=RCC_AHBENR
	//load address found in r0 to r1
	ldr r1,[r0]
	//enable gpioc//
	//orrs r1,r1,#GPIOC_EN
	movs r2,#1
	movs r3,#19
	LSLS R2, R2, R3
	orrs r1,r2,r1
	str r1,[r0]

//set pc8 as output
	ldr r0,=GPIOC_MODER
	//load address found in r0 to r1
	ldr r1,[r0]
	//enable gpioc//
	//orrs r1,r1,#GPIOC8_GPIO
	movs r2,#1
	movs r3,#16
	LSLS R2, R2, R3
	orrs r1,r2,r1
	str r1,[r0]


//make pc8 high
	ldr r0,=GPIOC_ODR
	ldr r1,=GPIOC_ODR8
	str r1,[r0]
	bx lr

stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
