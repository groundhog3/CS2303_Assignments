/** file at2.c
 * @author Ryan Mechery
 *
 * Program to demonstrate populating fixed-size arrays in C 
 * using input from command line and sorting them.
 */

#include <stdio.h>
#include "print_arrays.h"
#include "array_sort.h"

#define DOUBLE_ARRAY_SIZE (10)


/** Main program for demonstrating arrays. 
 * Fills array contents from cmd line, prints it out, and sorts it.
 * @return 0, Indicating success.
 * @return 1, Indicating Error.
 */

int main(int argc, const char* argv[]) {
  double a[DOUBLE_ARRAY_SIZE]; //Array where cmd lines arguments are held
  int errno; //where error number can be stored

  // get_input() works like main. If it's able to store
  // contents into array it returns 1, else it prints an error message
  // and ends the program. 
  errno = get_double_input(argc, argv, a, DOUBLE_ARRAY_SIZE);
  if(errno){
    return 1; //failure (error message already printed)
  }

  int num_items = argc - 1; // number of contents in array
  
  // if there were no errors, print double array
  printf("Before Sorting:\n");
  print_double_array(a, num_items);

  // sort array
  sort_double_array(a, num_items);

  // print sorted array
  printf("After Sorting:\n");
  print_double_array(a, num_items);

  return 0; // Success!
}


