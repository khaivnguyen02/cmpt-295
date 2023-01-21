/* 
 * Filename: Assn1_main.c
 *
 * Description: Test driver for Assn1_Q3.c
 *
 * Auhtors: AL + <your name>
 * Student number: <your student number>
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer, size_t);
void show_bytes_2(byte_pointer, size_t);
void show_bits(int);
void show_int(int);
void show_float(float);
void show_pointer(void *);
int  mask_LSbits(int);

int main() {
    int ival = 12345;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

/* Add your test cases here in order
   to test the functions you have modified 
   and the functions you have created. */

    // Q3.a
    show_bytes((byte_pointer) &ival, sizeof(int));
    show_bytes((byte_pointer) &fval, sizeof(float));
    show_bytes((byte_pointer) &pval, sizeof(int));

    // Q3.c
    // show_bytes_2((byte_pointer) &ival, sizeof(int));
    // show_bytes_2((byte_pointer) &fval, sizeof(float));
    // show_bytes_2((byte_pointer) &pval, sizeof(int));

    // Q3.d
    // show_bits(12345);
    // show_bits(-12345);

    // Q3.e
    // printf("%d\n",mask_LSbits(4));
    // printf("%d\n",mask_LSbits(5));
    // printf("%d\n",mask_LSbits(0));
    // printf("%d\n", mask_LSbits(32));
    return 0;

}