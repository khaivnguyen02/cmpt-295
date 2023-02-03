/*
 * Filename: decode2.c
 * 
 * Description: Assignment 3 - Q3
 * 
 * Author: Van Khai Nguyen (SFU ID: 3015 38378)
 * 
 * Modification date: Feb 1 2023
 */ 

#include <stdio.h>
#include <stdlib.h>
/*
 * Assembly code:
 *
 * decode2:
 *      subq    %rdx, %rsi
 *      imulq   %rsi, %rdi
 *      movq    %rsi, %rax
 *      salq    $63, %rax
 *      sarq    $63, %rax
 *      xorq    %rdi, %rax
 *      ret
*/

long decode2(long x, long y, long z) {
    // x -> %rdi
    // y -> %rsi
    // z -> %rdx
    // The code stores the return value in register %rax
    
    y -= z; // subq %rdx, %rsi - Subtract
    x *= y; // imulq %rsi, %rdi - Integral Multiply
    long result;
    result = y; // movq %rsi, %rax
    result = result << 63; // salq $63, %rax - Left Shift
    result = result >> 63; // sarq $63, %rax - Right Arithmetic Shift (Unsigned)     
    result = result ^ x; // xorq %rdi, %rax - XOR

    return result; // ret
}

int main(int argc, char *argv[]) {
    long a = 0;
    long b = 0;
    long c = 0;
    long answer = 0;

    if (argc == 4) {
        a = strtol(argv[1], NULL, 10);
        b = strtol(argv[2], NULL, 10);
        c = strtol(argv[3], NULL, 10);
        answer = decode2(a, b, c);
        printf("decode2(%ld, %ld, %ld) produces %ld as a result.\n", a, b, c, answer);
    }
    else {
        printf("Must supply 3 long int\n");
        return 1;
    }
    return 0;
}

// end of decode2.c