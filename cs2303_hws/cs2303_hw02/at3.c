/** file at3.c
 * @author Ryan Mechery
 *
 * Program that generates an array of random integers,
 * prints it, sorts it, and prints it out again.
 */

#include <stdio.h>
#include <stdlib.h>
#include "print_arrays.h"
#include "array_sort.h"

/** Main program to generate random array and sort it.
 * @return 0, Indicating success.
 * @return 1, Indicating failure.
 */

int main(int argc, const char * argv[]) {
  if(argc < 2){
    printf("Enter an argument into the command line!\n");
    return 1; // indicate error
  }

  if(argc != 3){
    printf("You entered %d argument(s). This program requires exactly 2.\n", argc -1);
    return 1; // indicate error
  }

  int max_random = atoi(argv[1]);
  int num_randoms = atoi(argv[2]);
  int a[num_randoms]; //array to hold random ints

  fill_random(a, num_randoms, max_random); //populate with random ints

  printf("Before Sorting:\n");
  print_int_array(a, num_randoms); //print array before sorting

  sort_int_array(a, num_randoms); //sort a array in asc. order

  printf("After Sorting:\n");
  print_int_array(a, num_randoms); //print array after sorting

  return 0; // Success!
}


