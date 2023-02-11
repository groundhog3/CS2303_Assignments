/** sort.c
 * @author Ryan Mechery
 * This file lists implementation for sort funcs and related printing funcs
 * defined in sort.h
 * */

#include <stdio.h>
#include <sys/time.h>
#include "sort.h"

/** Prints an array of integers, one per line.
 * @param nums Array to print
 * @param count Number of elements to print
 */

void print_int_array(int nums[], int count) {
  int i; // Loop counter
  for (i = 0; i < count; i++) {
    printf("%d\n", nums[i]); // Print each array element in turn
  }
}

/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to print
 * @param count Number of elements to print
 */

void sort_descending(int nums[], int count) {
  int round;     // How many times left to go through the outer loop.
  int i;         // Loop counter for the inner loop
  int inorder;   // Used as a boolean (logical). 1 = array is in correct order.
  int temp;      // Temporary variable used while swapping array elements

  inorder = 0;   // Assume not sorted at the beginning

  // Repeat outer loop, one time less than the size of the array.
  // Terminate early if array is in correct order.
  for(round = count - 1; (round > 0) && (!inorder); round--) {
    inorder = 1;  // Assume in correct order, until found otherwise.

    // Repeat inner loop, testing array elements 0 through round
    // Compare two adjacent elements of the array and swap if wrong order
    for (i = 0; i < round; i++) {
      if (nums[i] < nums[i+1]) {
      	inorder = 0;      // At least one pair had to be swapped
      	temp = nums[i];
      	nums[i] = nums[i+1];
      	nums[i+1] = temp;
      }
    }
  }
}

/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm w/pointers.
 *
 * @param nums Array to print
 * @param count Number of elements to print
 */

void alt_sort_descending(int nums[], int count) {
  int round;     // How many times left to go through the outer loop.
  int i;         // Loop counter for the inner loop
  int inorder;   // Used as a boolean (logical). 1 = array is in correct order.
  int temp;      // Temporary variable used while swapping array elements
  int* ptr;

  inorder = 0;   // Assume not sorted at the beginning

  // Repeat outer loop, one time less than the size of the array.
  // Terminate early if array is in correct order.
  for(round = count - 1; (round > 0) && (!inorder); round--) {
    inorder = 1;  // Assume in correct order, until found otherwise.
    ptr = &nums[0];

    // Repeat inner loop, testing array elements 0 through round
    // Compare two adjacent elements of the array and swap if wrong order
    for (i = 0; i < round; i++) {
      if (*ptr < *(ptr+1)) {
        inorder = 0;      // At least one pair had to be swapped
        temp = *(ptr+1);
        *ptr = *(ptr+1);
        *(ptr +1) = temp;
      }
      ptr++;
    }
  }
}

/** Prints the contents of a timeval struct.
 * @param t Struct to print.
 */
void print_timeval(struct timeval t) {
  printf("Seconds %ld,\tMicroseconds:%ld\n", t.tv_sec, t.tv_usec);
}

/** Calculates difference between two timestamps. 
 * Note that this takes structs as parameters and returns a struct;
 * it does not use pointers.
 * @param time1 A time stamp
 * @param time2 another timestamp (assumed same as or later than time 1)
 * @return A timeval struct representing time2 - time1
 */
struct timeval timediff(struct timeval time1, struct timeval time2) {
  struct timeval diff;

  //to substract evenly, just substract one second 
  // from time2's second member and add it to the micros. member
  while(time1.tv_usec > time2.tv_usec){
    time2.tv_sec--;
    time2.tv_usec += 1000000;
  }

  //now that there won't be a buffer overflow
  //second and microsecond can safely be subtracted
  diff.tv_sec =  time2.tv_sec  - time1.tv_sec;
  diff.tv_usec = time2.tv_usec - time1.tv_usec;

  return diff; //return struct
}

/** function returns a (pseudo) random integer from zero to 
 *  max, <u>inclusive</u>
 *  @param max max number in range <u>inclusive</u>
 *  @return random integer from [0, max]
 *  @warning Initialize seed generator BEFORE using this function
 */
int get_random(int max){
  return rand() % (max + 1);
}

/** function that uses get_random() to populate arr
 *  with random integers
 *  @param arr array to be populated
 *  @param size size of arr array
 *  @param max max number in range <u>inclusive</u>
 */
void fill_random(int arr[], int size, int max){
  int i; //loop counter
  srand(time(0));  //use current time as seed for seed generator
  for(i = 0; i < size; i++){
    arr[i] = get_random(max);
  }
}