#include <stdio.h>
#include <stdlib.h>
#include "calcGrades.h"
/* This simple program demos passing in multiple arguments into the command line.
 * Created by Ryan Mechery (rmechery)
 * Usage:
 *   ./grades some_number1 ... some_number20
 * Example:
 *   ./grades 92 90 87 
 */


int main (int argc, const char* argv[]) {
  #define MAX_GRADES (20) 
  //cnst which determines max cmdline args
  #define NUM_GRADES (argc - 1) //cnst that holds number of grades

  if (argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }

  if(argc > MAX_GRADES + 1){// Check if too many arguments were entered.
    printf("Too many arguments entered!!\n");
    return 1; //Indicate failure
  }

  printf("The numbers entered were: ");
  int all_grades[MAX_GRADES]; // Define and allocate the array 
  int i;                      // Index into array

  // loops through all argv parameters which is termination cond.
  // prints out each grade entered.
  // Note: if there are more parameters than MAX_GRADES the cond.
  // before will catch that error before 
  for(i = 0; i < NUM_GRADES; i++){
    all_grades[i] = atoi(argv[i+1]); //get string from argv and convert to int
    printf("%d ", all_grades[i]);
  }

  printf("\n");
  calcGrades(NUM_GRADES, all_grades); //contained in calcGrades.c

  return 0; // Indicate success!
}