/** sort.h
 * @author Ryan Mechery
 * This file lists an enum and function prototypes for sort.c
 * */

#ifndef SORT_H
#define SORT_H

// data structures

/** An enum for the type of sort functions available.
 */
enum sort_functions{
	SORT_DESCENDING,  /**< default bubble sort using indexes */
	ALT_SORT_DESCENDING /**< optimized bubble sort using pointers */
};

// Function prototypes:
void timesort (int a[], int count, int sort_type);
void print_int_array(int nums[], int count);
void sort_descending(int nums[], int count);
void alt_sort_descending(int nums[], int count);
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);

#endif
