// CSE30 assignment template
// 
// id:janeja
//
////////////////////////////////////////
#include "Version.h"

#ifndef MYNODELOOKUP_S
    .section .note.GNU-stack,"",%progbits
    .end
#else

    // version 1.0 08/22/2024
    .arch   armv6
    .arm
    .fpu    vfp
    .syntax unified

    #include "node.h"

    .extern strcmp
    .text

    .type   node_lookup, %function
    .global node_lookup
    // determine how many registers to save and set FP_OFF
    .equ    FP_OFF, 28

    // preserved register use table fill this in to help you
    //
    // r4 : current node pointer
    // r5 : id of the current node (node->id)
    // r6 : id to be matched (from input)
    // r7 : temp variable
    // r8
    // r9

node_lookup:
    // set up stack frame
    push {r4-r7, fp, lr}
    add fp, sp, FP_OFF

    mov r4, r0     //r4 = front of linked list
    mov r6, r1     //r6 = input id 
    
    // implement the function

lookup_loop:
    cmp r4, #0                           // front == null
    beq lookup_not_found                 // if front == null
    ldr r5, [r4]                     // load id of current node to r5
    mov r0, r5                           
    mov r1, r6 
    bl strcmp 
    cmp r0, #0
    beq lookup_found 
    ldr r4, [r4, #4]
    b lookup_loop  

lookup_not_found:
    mov r0, #0                 
    b lookup_return

lookup_found:
    mov r0, r4   

lookup_return:
    pop {r4-r7, pc} 

    // remove stack frame
    bx      lr                  // function return
    .size   node_lookup, (. - node_lookup)
    .section .note.GNU-stack,"",%progbits
.end
#endif
