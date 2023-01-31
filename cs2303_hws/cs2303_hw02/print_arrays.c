/** file print_arrays.c
 * @author Ryan Mechery
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include "print_arrays.h"

/** Print an array of ints, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array
*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  for (i = 0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}

/** Print an array of doubles, one per line.
 *  @param a Array to print
 *  @param num_entries Number of entries in the array
 * */
void print_double_array(double a[], int num_entries) {
  int i; // Loop counter

  //prints out each element of a
  for (i = 0; i < num_entries; i++) {
    printf("%f\n", a[i]);
  }
}

/** Store arguments from command line into integer array
 *  @param argc number of arguments on the command line (including program name)
 *  @param argv array of C-style strings from cmd line
 *  @param arr array for cmd line arguments to be stored
 *  @param size size of the arr array
 *  @return 0, if Success
 *  @return 1, if no arguments entered
 *  @return 2, if too many arguments entered
 * */
int get_double_input(int argc, const char* argv[], double arr[], int size ){
  if(argc < 2){
    printf("No arguments were entered. Try again.\n");
    return 1; //failure
  }

  int num_entries = argc - 1; //var that stores num_entries from cmd line

  if(num_entries > size){
    printf("The array can only hold %d elements. You entered %d elements.\n", size, num_entries);
    printf("Try again with fewer parameters.\n");
    return 2; //failure
  }
  
  int i = 1; //argv counter - skip argv[0]
  int j = 0; //arr counter - start of arr array

  //loop casts and stores entries from argv into arr
  while(i < argc && j < size){
      arr[j] = atof(argv[i]); 
      i++;
      j++;
  }

  return 0; //Success
}
 