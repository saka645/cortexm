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
    // Load data address in r0
    ldr r0, =SIGN_DATA
    movs r3, #9        // Counter for 9 bytes
    movs r2, #0        // Initialize sum to 0
loop:
    // Load a signed byte from address r0
    ldr r1, [r0]
    adds r2, r2, r1    // Add the signed byte to sum
    adds r0, r0, #1    // Increment address by 1
    subs r3, r3, #1    // Decrement counter

    // Branch to top if counter is not zero
    bne loop

stop:
    b stop             // Infinite loop to stop the program
    .align
    .end
