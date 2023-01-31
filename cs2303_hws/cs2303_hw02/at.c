/** file at.c
 * @author Ryan Mechery
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include <stdio.h>
#include "print_arrays.h"

#define INT_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 * @return 1, Indicating failure.
 */

int main(int argc, const char* argv[]) {
  if(argc > 1){
    printf("This program requires no inputs. Try again!\n");
    return 1; // indicate error
  }

  int i; // Loop counter
  int a[INT_ARRAY_SIZE]; //array holding cons. integers

  // Fill the array with consecutive integers
  for (i = 0; i < INT_ARRAY_SIZE; i++) {
    a[i] = i;
  }

  // Now print it out
  print_int_array(a, INT_ARRAY_SIZE);

  return 0; // Success!
}
