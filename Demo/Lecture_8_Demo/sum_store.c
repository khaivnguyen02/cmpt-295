/*
 * Filename: sum_store.c
 *
 * Purpose: Lecture 8 demo
 * 
 * Last Modified: Jan. 2023
 *
 */

#include <stdlib.h>

long plus(long x, long y) {
  return x + y;
}

void sum_store(long x, long y, long *dest) {
  long sum = plus(x, y);
  *dest = sum;
  return;
}