// CSE30 assignment template
// 
// id: 
//
////////////////////////////////////////
#include "Version.h"

#ifndef MYHASH_S
    .section .note.GNU-stack,"",%progbits
    .end
#else

    // version 1.0 08/22/2024
    .arch   armv6
    .arm
    .fpu    vfp
    .syntax unified

    
    .text

    .type   hashfn, %function
    .global hashfn
    // determine how many registers to save and set FP_OFF
    .equ    FP_OFF, 28          // (# of preserved regs - 1) * 4

    // preserved register use table fill this in to help you
    //
    // r4
    // r5
    // r6
    // r7
    // r8
    // r9

hashfn:
	push    {r4-r9, fp, lr}     // use r4-r9 protected regs
    	add     fp, sp, FP_OFF      // locate our frame pointer
    // DO NOT EDIT PROLOGUE ABOVE
    // You can use temporary r0-r3 and preserved r4-r9
    // Store return value (results) in r0
    ///////////////////////////////////////////////////////
	mov     r1, #0              // r2 - the current hash value (hash = 0)
        mov     r2, r0              // r2 = c
loop_start:
        ldrb    r0, [r3], #1        // Load the next character (unsigned) into r6 and increment pointer (r5)
        cmp     r0, #0              // Compare the character to '\0' (end of string)
        beq     loop_end  
	mov     r2, r1          // r2 = hash

        lsl     r3, r1, #6      // r3 = hash << 6

        lsl     r4, r1, #16     // r4 = hash << 16

        add     r5, r0, r3      // r5 = c + (hash << 6)

        add     r5, r5, r4      // r6 = c + (hash << 6) + (hash << 16)

        add     r2, r5, r2      // r0 = (c + (hash << 6) + (hash << 16)) - hash
	


    	cmp r2, #0
    	bne       loop_start          // Repeat the loop

loop_end:
    mov     r0, r2  
    
    // YOUR CODE GOES HERE
    
    ///////////////////////////////////////////////////////
    // DO NOT EDIT EPILOGUE BELOW
    sub     sp, fp, FP_OFF      // restore sp
    pop     {r4-r9, fp, lr}     // restore saved registers
    bx      lr                  // function return
    .size   hashfn, (. - hashfn)
    .section .note.GNU-stack,"",%progbits
.end
#endif
