 /* 
 * Filename: Lecture_5_Demo.c
 *
 * Description: Demo impact of fixed-size memory 
 *              on arithmetic operators (e.g., + )
 *              and on relational operators (e.g., > and < ).
 *
 * Author:
 * Modification date: Jan. 2023
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Practice Problem 2.27 */
/* Description: Returns 1 if arguments x and y can be added without causing overflow.*/
/* Precondition: Arguments x and y are unsigned 8 bit integral value. */
int uadd_ok(unsigned char x, unsigned char y) {

  unsigned char sum = x + y;
  int result = 0;

  if ( sum >= x ) result = 1;

  return result;
  
}

int main(int argc, char *argv[]) {
 
  printf("\nUnsigned addition - no overflow:\n");
  unsigned char ux = 90;
  unsigned char uy = 45;

  unsigned char usum = ux + uy;
  unsigned short uSsum = ux + uy; 

  printf("Prediction: will adding %hhu and %hhu create an overflow? %s\n", ux, uy, 
         (uadd_ok(ux, uy)==1? "no":"yes"));
  printf("\tActual sum: %hhu + %hhu = %hhu\n", ux, uy, usum);
  printf("\tTrue sum: %hhu + %hhu = %hu\n\n", ux, uy, uSsum);

  printf("Unsigned addition - overflow:\n");
  ux = 255;

  usum = ux + uy;
  uSsum = ux + uy; 

  printf("Prediction: will adding %hhu and %hhu create an overflow? %s\n", ux, uy, 
         (uadd_ok(ux, uy)==1? "no":"yes"));
  printf("\tActual sum: %hhu + %hhu = %hhu\n", ux, uy, usum);
  printf("\tTrue sum: %hhu + %hhu = %hu\n\n", ux, uy, uSsum);

  printf("Signed addition - no overflow - Part 1:\n");
  signed char x = -90;
  signed char y = 45;

  signed char sum = x + y;
  signed short Ssum = x + y; 

  printf("\tActual sum: %hhi + %hhi = %hhi\n", x, y, sum);
  printf("\tTrue sum: %hhi + %hhi = %hi\n\n", x, y, Ssum);
 
  printf("Signed addition - no overflow - Part 2:\n");
  x = 90;
  y = -45;

  sum = x + y;
  Ssum = x + y; 

  printf("\tActual sum: %hhi + %hhi = %hhi\n", x, y, sum);
  printf("\tTrue sum: %hhi + %hhi = %hi\n\n", x, y, Ssum);

  printf("Signed addition - overflow - Part 1:\n");
  y = 45;

  sum = x + y;
  Ssum = x + y; 

  printf("\tActual sum: %hhi + %hhi = %hhi\n", x, y, sum);
  printf("\tTrue sum: %hhi + %hhi = %hi\n\n", x, y, Ssum);

  printf("Signed addition - overflow - Part 2:\n");
  x = -90;
  y = -45;

  sum = x + y;
  Ssum = x + y; 

  printf("\tActual sum: %hhi + %hhi = %hhi\n", x, y, sum);
  printf("\tTrue sum: %hhi + %hhi = %hi\n\n", x, y, Ssum);

  // Impact of fixed-size memory on comparison
  printf( "Impact of fixed-size memory on comparison\n" );
  unsigned int ui = 0xBEEF0000;      // in binary => 0b10111110111011110000000000000000
  unsigned short us = 0b1011111011101111;  // in hex => 0xBEEF

  if ( ui > us ) 
    printf( "ui (0x%x) > us (0x%x)\n", ui, (unsigned int) us );
  // 1. us is promoted from 16 bits to 32 bits => 00000000000000001011111011101111 => 0x0000BEEF
  // 2. It is true that 0xBEEF0000 (interpreted as an unsigned) is > 0x0000BEEF (interpreted as an unsigned)
  //  Why "interpreted as an unsigned"? Because ui is an unsigned. See top of page 150 in our textbook.

  if ( ui < ( signed short ) us ) {
    // Use the format specifier "%u" to print the unsigned interpretation of the bit patterns stored in ui and us.
    printf( "ui (ui as an unsigned int => %u) (0x%x) < ( signed short ) us (%u) (0x%x) \n",    
             ui, ui, ( unsigned int )( ( signed short ) us ), ( unsigned int )( ( signed short ) us ));
    // (us cast to signed short then promoted to an unsigned int => %u)          
    // Use the format specifier "%i" to print the signed interpretation of the bit patterns stored in ui and us.
    // NOTE: The bit patterns stored in ui and us have not changed. Our interpretation of them has!
    printf( "ui (ui as an signed int => %i) (0x%x) < ( signed short ) us (%i) (0x%x) \n", 
             ui, ui, ( unsigned int )( ( signed short ) us ), ( unsigned int )( ( signed short ) us ));
    // (us cast to signed short then promoted to an unsigned int which is interpreted as a signed int => %i)          
  }
  // 1. us is cast to a signed short. 
  //  This means that us (1011111011101111) is now interpreted as a negative value since its MSb is 1
  // 2. us is promoted from 16 bits to 32 bits => 11111111111111111011111011101111 => 0xFFFFBEEF (not 0x1111BEEF)
  //  (remember, we pad using the sign bit: 0 when the value is unsigned or positive (signed) OR 1 when the value is negative (signed))
  // 3. It is true that 0xBEEF0000 (interpreted as an unsigned) is < xFFFFBEEF (interpreted as an unsigned)
  //  Why "interpreted as an unsigned"? Because ui is an unsigned. See top of page 150 in our textbook.
  
  if ( ( unsigned char ) ui > us ) 
    printf( "( unsigned char ) ui (0x%.2x) > us (0x%x)\n", ( unsigned short )( ( unsigned char ) ui ),  us );
  // The above condition is false. Can you see why?
  printf( "( unsigned char ) ui (0x%.2x) < us (0x%x)\n", ( unsigned short )( ( unsigned char ) ui ),  us );
  
  return 0;
  
}