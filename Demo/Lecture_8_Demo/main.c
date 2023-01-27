/*
 * Filename: main.c
 *
 * Purpose: Lecture 8 demo
 * 
 * Last Modified: Jan. 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

long plus(long, long );

void sum_store(long, long, long *);

int main(int argc, char *argv[]) {
	
  if ( argc == 3 ) {
    long x = atoi(argv[1]);
    long y = atoi(argv[2]);
    long result;
    sum_store(x, y, &result);
    printf("%ld + %ld --> %ld\n", x, y, result);
  }
  else 
    printf("2 numbers required!\n");

  return 0;
}