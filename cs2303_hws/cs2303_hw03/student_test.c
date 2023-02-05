/** struct_test.c
 *  @author Ryan Mechery
 *  Tests functionality of custom Student struct
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

typedef struct Student Student;

int main(int argc, char *argv[]){
	int wpi_size; //size of school
	if(argc == 2 && atoi(argv[1]) > 0){
		wpi_size = atoi(argv[1]);
	}
	else {
		printf("%d", wpi_size);
		wpi_size = 3; //default size of school
	}

	printf("I will first make a singular student with my info.\n");
	Student *ryan = make_student("Ryan Mechery", 18, 1, 4.0);
	print_student(ryan);
	printf("\n");
	free(ryan); //free from memory

	printf("Now I will test making an collection of students.\n");
	Student **wpi = make_random_structs(wpi_size); //make collection of students
	printf("\x1b[32mWPI School Students:\x1b[0m\n");
	print_students(wpi, wpi_size); //print them out
	
	printf("Now I will test making a shallow copy of the previous collection.\n");
	Student** wpi_shallow_copy = 
		make_shallow_copy(wpi, wpi_size); //shallow copy of wpi
		printf("\x1b[32mWPI_SHALLOW_COPY School Students:\x1b[0m\n");
	print_students(wpi_shallow_copy, wpi_size); //print out shallow copy

	printf("Now I will test making the deepest copy of the original collection.\n");
	Student** wpi_deep_copy = 
		make_deep_copy(wpi, wpi_size); //deep copy of wpi
		printf("\x1b[32mWPI_DEEP_COPY School Students:\x1b[0m\n");
	print_students(wpi_deep_copy, wpi_size); //print out deep copy

	printf("Now I will free all WPI struct pointers from memory.\n");
	free_students(wpi, wpi_size); //deallocate and assign pointers to null

	printf("The original struct with pointers should all point to null.\n");
	printf("\x1b[31mFREED WPI School Students:\x1b[0m\n");
	print_students(wpi, wpi_size); //should print out nothing

	printf("The deep copy should remain unaffected.\n");
	printf("\x1b[34mWPI_DEEP_COPY after freeing WPI\x1b[0m (should be same as before):\n");
	print_students(wpi_deep_copy, wpi_size); //print out deep copy

	free_students(wpi_deep_copy, wpi_size); //deallocate and assign pointers to null

	printf("I will end the testing by freeing all struct pointers from the deep copy.\n");
	printf("\x1b[31mFREED WPI_DEEP_COPY\x1b[0m:\n");
	print_students(wpi_deep_copy, wpi_size); //should be null
	
	return 0;
}
