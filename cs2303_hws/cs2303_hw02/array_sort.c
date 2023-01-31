/** File array_sort.c
 * @author Ryan Mechery
 *
 * Functions for sorting arrays and generating random numbers.
 */

#include <stdlib.h>
#include <time.h>

/** Sort int arr in place using bubbleSort.
 * 	@param arr array to be sorted
 *	@param size size of arr array
 */
void sort_int_array(int arr[], int size){
	int i; //main counter [0, size)
	int j; //secondary counter [0, size - i - 1)

	//loops through arr in O(n^2) time complexity
	for(i = 0; i < size; i++){
		for(j = 0; j < size - i - 1; j++){
			// if cur elem is greater than next, swap
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

/** Sort double arr in place using bubbleSort.
 * 	@param arr array to be sorted
 *	@param size size of arr array
 */
void sort_double_array(double arr[], int size){
	int i; //main counter [0, size)
	int j; //secondary counter [0, size - i - 1)

	//loops through arr in O(n^2) time complexity
	for(i = 0; i < size; i++){
		for(j = 0; j < size - i - 1; j++){
			// if cur elem is greater than next, swap
			if(arr[j] > arr[j+1]){
				double temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

/** function returns a (pseudo) random integer from zero to 
 * 	max, <u>inclusive</u>
 * 	@param max max number in range <u>inclusive</u>
 * 	@return random integer from [0, max]
 * 	@warning Initialize seed generator BEFORE using this function
 */
int get_random(int max){
	return rand() % (max + 1);
}

/** function that uses get_random() to populate arr
 *  with random integers
 * 	@param arr array to be populated
 * 	@param size size of arr array
 * 	@param max max number in range <u>inclusive</u>
 */
void fill_random(int arr[], int size, int max){
	srand(time(0));  //use current time as seed for seed generator
	for(int i = 0; i < size; i++){
		arr[i] = get_random(max);
	}
}