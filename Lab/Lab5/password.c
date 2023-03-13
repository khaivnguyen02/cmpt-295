/* 
 * Filename: password.c
 *
 * Description: Demo the effect of buffer overflow.
 *
 * Last modified on: March 2023
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool IsPasswordOK() {
  bool retResult = 0;
  unsigned int aSize = 9;  // size of password including "\0"
	
  // This is the valid password.
  char goodpwd[] = "goodpass";  // goodpwd will include "\0"
	
  // Here is the "buf", i.e., memory storage for the password
  char password[aSize]; 

printf("Memory address of the first byte of the array password: %p\n", &password);
  // User enters password
  gets(password);  

  // Echo the password
  printf("You entered the password %s\n", password);
	
  // strcmp(str1,str2) returns a value < 0 if str1 < str2.
  // strcmp(str1,str2) returns a value > 0 if str1 > str2.
  // strcmp(str1,str2) returns a value = 0 if str1 is equal to str2.
  //   !(0) -> !(false) = true since password equal goodpwd
  //   !(anything but 0) -> !(true) = false since Password not equal goodpwd
  return !strcmp(password, goodpwd); 
}

int main() {
  int result = 0;

  puts("Enter your password:"); 
	
  // Get & check password
  if ( IsPasswordOK() )      // 1 -> true
    puts("Access granted");	
  else {					 // 0 -> false
    puts("Access denied"); 
    result = 1;
  }
	
  return result;
} 