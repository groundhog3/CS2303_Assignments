
#include <stdio.h>
#include <stdlib.h>
/* Program that takes in a year from the cmdline and prints out if it's a leap
 * or not.
 * Created by Ryan Mechery (rmechery)
 *
 * Usage:
 *   ./leap some_year_number
 * Example:
 *   ./leap 2303
 *
 */
int main (int argc, const char* argv[]) {
  #define START_YEAR (1752)

  int yr; // Integer read from the command line goes here.
  if (argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }
  else if(argc > 2){
    printf("Too many arguments entered!\n");
    return 1; //Indicate failure
  }

  yr = atoi(argv[1]); // Get string from command line; convert to int

  //Check if this year is within the range which this program is designed to handle.
  if(yr < START_YEAR){
    printf("This program cannot test the year %d. It only handles the year %d and after.\n", \
     yr, START_YEAR);
    return 1; //failure
  }

  //If it's a valid year then this conditional will return true under two cases
  // a) if the year is divisible by 4 and not by 100
  //               OR
  // b) if the year is divisible by 100
  if((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0){
    printf("The number you entered, %d, is a leap year.\n", yr);
  }
  else {
    printf("The number you entered, %d, is a common year.\n", yr);
  }

  return 0; // Indicate success!
}