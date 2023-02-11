/** sorttest2.c
 * @author Ryan Mechery
 * */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "string.h"

/** Program which reads one number from the command line,
 * allocate an array sufficient to store the specified number of integers,
 * fills the array with specified number of random integers,
 * sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number string
 * Example:
 *         ./sorttest 3 sort_descending
 *         ./sorttest 10 alt_sort_descending
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

#define MAX_RANDOM (2147483647)

int main (int argc, const char* argv[]) {
  // Check that there are exactly two numbers
  if (argc != 3) { 
    printf("Must exacly two arguments on the command line! Exiting.\n");
    return 1; // Indicate failure
  }

  int *nums; // space to store numbers entered from the command line.

  int next_num; // Integer read from the command line goes here.
  int i; // array index 
  int size; // size of array
  int sort_type = 0;

  size = atoi(argv[1]);

  //if third argument matches valid enum type, set it that way
  // or return an error
  if(strcmp(argv[2], "sort_descending") == 0)
    sort_type = SORT_DESCENDING;
  else if(strcmp(argv[2], "alt_sort_descending") == 0)
    sort_type = ALT_SORT_DESCENDING;
  else{
    printf("\"%s\" is not a valid sort type!\n", argv[2]);
    printf("Only \"sort_descending\" and \"alt_sort_descending\" are allowed.\n");
    return 1;
  }

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(size, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
    return 1;
  }

  /* Generate random ints and put them into nums array */
  fill_random(nums, size, MAX_RANDOM);

  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, size, sort_type);

  return 0; // Indicate success!
}
