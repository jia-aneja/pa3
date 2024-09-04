// CSE30 assignment template
// 
// id: janeja
//
////////////////////////////////////////
#include "Version.h"

#ifndef MYINSTNODE_S
    .section .note.GNU-stack,"",%progbits
    .end
#else

    // version 1.0 08/22/2024
    .arch   armv6
    .arm
    .fpu    vfp
    .syntax unified

    #include "node.h"    
    
    .extern malloc
    .extern free
    .extern strcpy
    .extern strncpy
    .extern strlen
    .extern strdup
    .text

    .type   insert_node, %function
    .global insert_node
    // determine how many registers to save and set FP_OFF
    .equ    FP_OFF, 28

    // preserved register use table fill this in to help you
    //
    // r4 - Pointer to the new node
    // r5 - Pointer to the strdup result (node->id)
    // r6 - Temporary register

insert_node:
    // set up stack frame
    push    {r4-r9, fp, lr}     
    add     fp, sp, FP_OFF 

    ldr     r0, =8              // Load size of node struct (this might need adjusting)
    bl      malloc              // Call malloc
    mov     r4, r0              // Store the result (new node) in r4
    cmp     r4, #0              // Check if malloc returned NULL
    beq     insert_fail         // If NULL, jump to failure


    mov     r0, r0              // Load the `id` pointer argument
    bl      strdup              // Call strdup
    mov     r5, r0              // Store strdup result (node->id) in r5
    cmp     r5, #0              // Check if strdup returned NULL
    beq     free_node           // free the allocated node and fail

    
    str     r5, [r4, #0]        // Store id pointer in new_node->id
    str     r1, [r4, #4]        // Store height in new_node->height
    str     r2, [r4, #8]        // Store xcoord in new_node->xcoord
    str     r3, [r4, #12]       // Store ycoord in new_node->ycoord

    ldr     r6, [fp, #16]       // Load `front` pointer (next node in chain)
    str     r6, [r4, #16]       // Store `front` in new_node->next

    
    mov     r0, r4              // Move new node pointer into r0 for return
    b       cleanup             // Clean up and return

free_node:
    mov     r0, r4              // Load new_node pointer for freeing
    bl      free                // Call free(new_node)

insert_fail:
    mov     r0, #0              // Return NULL

cleanup:
    
    sub     sp, fp, FP_OFF      // Restore stack pointer
    pop     {r4-r9, fp, lr}     // Restore preserved registers and link register
    bx      lr                  // function return
    .size   insert_node, (. - insert_node)
    .section .note.GNU-stack,"",%progbits
.end
#endif


