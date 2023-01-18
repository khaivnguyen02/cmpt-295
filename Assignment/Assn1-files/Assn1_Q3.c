/* 
 * Filename: Assn1_Q3.c
 *
 * Description:
 *
 * Auhtors: AL + <your name>
 * Student number: <your student number>
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

  return; 
}	


// Question 3 e.
int mask_LSbits(int n) {
	
  // put your code here!

  // feel free to modify this return statement
  return 0; 
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
