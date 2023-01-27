/*
 * Filename: swap.c
 *
 * Purpose: Demo swap during Lecture 9
 * 
 * Date: Jan. 2023
 *
*/

void swap(long *xp, long *yp) 
{
	long L1 = *xp;
	long L2 = *yp;
	*xp = L2;
	*yp = L1;
	return;
}