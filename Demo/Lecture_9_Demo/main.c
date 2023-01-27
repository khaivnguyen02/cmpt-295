/*
 * Filename: main.c
 *
 * Purpose: Demo swap during Lecture 9
 * 
 * Date: Jan. 2023
 *
*/

#include <stdio.h>
#include <stdlib.h>

long swap(long *, long *);

int main(int argc, char *argv[]) {
	
  if ( argc == 3 ) {
    long x = atoi(argv[1]);
    long y = atoi(argv[2]);
    long result;
    
    printf("Before swap: x = %ld, y = %ld\n", x, y);
    result = swap(&x, &y);
    printf("After swap: x = %ld, y = %ld and result = %ld\n", x, y, result);
  }
  else printf("2 numbers required!\n");
  
  return 0;
}