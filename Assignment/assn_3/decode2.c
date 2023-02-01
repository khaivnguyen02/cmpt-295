/*
 * Filename: decode2.c
 * 
 * Description: 
 *
 *
 *
 * Author:
 *
 * Modification date: Feb 1 2023
 */ 

#include<stdio.h>

/*
 * Assembly code:
 *
 * decode2:
 *      subq    %rdx, %rsi
 *      imulq   %rsi, %rdi
 *      movq    %rsi, %rax
 *      salq    $63, %rax
 *      sarq    %63, %rax
 *      xorq    %rdi, %rax
 *      ret
*/

long decode2(long x, long y, long z) {
    // x -> %rdi
    // y -> %rsi
    // z -> %rdx
    // The code stores the return value in register %rax


}

int main {

    return 0;
}