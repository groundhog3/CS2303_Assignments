#include <stdio.h>
#include <stdlib.h>
#include "calcGrades.h"

/* This program contains code for calculating the avg, min, & max
 * from a list of grades.
 * Created by Ryan Mechery (rmechery)
 */


#define INT_MAX (2147483647)      //from <limits.h>
#define INT_MIN (-2147483647 - 1) //from <limits.h>


/* This function takes in an array of grades and it's size
 * and prints the mean, min, and max.
 */
void calcGrades(int num_grades, int all_grades[]){
  int avg = 0;        
  int min = INT_MAX;  //init. to INT_MAX to reduce code for finding min
  int max = INT_MIN;  //init. to INT_MIN to reduce code for finding max

  //This for loop loops through indexes of initialized nums in all_grades
  // termination event is i >= num_grades
  for(int i = 0; i < num_grades; i++){
    int n = all_grades[i]; //temp variable that stores cur value
    avg += n;           
    if(n < min) min = n; //make n new min if it n less than min
    if(n > max) max = n; //make n new max if it n greater than max
  }
  avg /= num_grades; //calculate average
  printf("Average Grade is = %d\tLowest Grade = %d\tHighest Grade = %d\n", avg, min, max);

}