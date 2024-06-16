.section .text
.global __main

__main:

    ldr r5, =45
    ldr r3, =45


    add r6, r5, r3

stop:

    b stop

    .align 2
