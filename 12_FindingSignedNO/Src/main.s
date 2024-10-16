.section .data

SIGN_DATA:
.byte 13
.byte -10
.byte 9
.byte 14
.byte -18
.byte -9
.byte 12
.byte -19
.byte 16

.syntax unified
.cpu cortex-m0
.thumb
.section .text
.global __main

__main:
	// Load data address in r4
	ldr r4, =SIGN_DATA
	ldrsb r0, [r4,#0]   // Load the signed byte at SIGN_DATA[0] into r0
    movs r3, #9        // Counter for 9 bytes

    // Load a signed byte from address r0
    ldr r2, [r0]
	adds r0,r0,#1
begin:
    // Load a signed byte from address r0
    ldr r1, [r0]
	cmp r1,r2

	//branch to next if r1>=r2
	bge next
	mov r2,r1

next:
	adds r0,r0,#1
	subs r3,r3,#1

	//branch to begin if result is not equal to zero
	bne begin

stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
