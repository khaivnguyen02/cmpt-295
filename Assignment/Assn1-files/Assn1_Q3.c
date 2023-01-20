/* 
 * Filename: Assn1_Q3.c
 *
 * Description:
 *
 * Author: Van Khai Nguyen
 * Student number: 3015 38378

 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

// Question 3 a.
void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++)
    printf("%p 0x%.2x\n", &start[i], start[i]); 	
  printf("\n");
  return;	
}

// Question 3 b.
// Put your answer to Question 3 b) here as a comment
/*
*/


// Question 3 c.
void show_bytes_2(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++)
    printf("%p 0x%.2x\n", start + i, *(start + i)); 	
  printf("\n");
  return;		
}

// Question 3 d.
void show_bits(int decimal) {
	
  // put your code here!
  int i, temp, andMask;

  for (i = 31; i >= 0; i--) {
    andMask = 1 << i;
    temp = decimal & andMask;
    temp == 0 ? printf("0") : printf("1");
   }
   printf("\n");
  return; 
}	


// Question 3 e.
int mask_LSbits(int n) {
	
  // put your code here!
  int length = sizeof(int) * 8;
  int result = 0;

  if (n >= length) {
    return -1; // 111...111 (32 bits) == -1
  }

  if (n <= 0) {
    return 0;
  }

  // Flip 000...000 (32 bits) ---> 111...111
  // Left Shift 111...111 n times ---> 111...000 (with n 0's LSb)
  // Flip once again to get the answer
  return ~(~result << n);

}

void show_int(int x) {
  printf("\nival = %d\n", x); 
  show_bytes((byte_pointer) &x, sizeof(int)); 
  show_bytes_2((byte_pointer) &x, sizeof(int)); 
  return;	
}

void show_float(float x) {
  printf("fval = %f\n", x); 	
  show_bytes((byte_pointer) &x, sizeof(float));
  show_bytes_2((byte_pointer) &x, sizeof(float)); 
  return;	
}

void show_pointer(void *x) {
  printf("pval = %p\n", x); 
  show_bytes((byte_pointer) &x, sizeof(void *));
  show_bytes_2((byte_pointer) &x, sizeof(void *));
  return;	
}
