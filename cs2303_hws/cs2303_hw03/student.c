/** student.c
 *  @author Ryan Mechery
 *  Defines custom struct for a Student with a name, age, id, and grades[].
*/

#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
#include "student.h"
#include <time.h>

#define MAX_NAME_SIZE (30) //contains max size of name string

/** @struct Student
 *  @brief This structure represents a student object in school.
 *  @var Student.name
 *  Member 'name' contains a string for f_name & l_name of max size 30
 *  @var Student.age
 *  Member 'age' contains age of student.
 *  @var Student.id
 *  Member 'id' contains 5 digit id of student.
 *  @var Student.gpa
 *  Member 'gpa' contains grade point average out of 4.0
 */
struct Student {
	char name[MAX_NAME_SIZE];
	int age;
	int id;
	double gpa;
};

typedef struct Student Student; 



/** Dynamically allocates and returns pointer to a student struct in the heap.
 * 	@param name c-string pointer for Student.name
 * 	@param age  int for Student.age
 * 	@param id int for Student.id
 * 	@param gpa double for Student.gpa
 * 	@warning If there is no space in memory, this method will return a null pointer.
 * */
Student* make_student(char* name, int age, int id, double gpa){
	Student* st = malloc(sizeof(Student)); //pointer to student in heap

	//if no space in memory for st then just return null
	if(st == NULL)
		return NULL;

	//regardless of size of name, copies at most MAX_NAME_SIZE chars
	mystrncpy(st->name, name, MAX_NAME_SIZE); //assign name to struct
	st->age = age; //assign age to struct
	st->id = id; //assign id to struct 
	st->gpa = gpa; //assign gpa to struct

	return st; //return new student pointer
}

/** Prints student struct with formatting
 * 	@param st pointer to Student struct
 * */
void print_student(Student* st){
	printf("========================\n");
	printf("Student's name: %s\n", st->name);
	printf("Age: %d\tID#: %05d\n", st->age, st->id );
	printf("Current GPA: %.2f\n\n", st->gpa);
}

/** Use `make_student()` with random values to make random student struct
 * 	@return pointer to random Student struct
 * */
Student* make_random_student(){
	Student *st; //pointer for Student in heap
	char name[MAX_NAME_SIZE]; //array where random name will be held

	generate_random_name(name, MAX_NAME_SIZE); 
	int age = rand() % (18 - 2 + 1) + 2; //[2,18]
	int id = rand() % 100000; //[0, 99999]
	double gpa = (rand() % 401)/100.0; //[0.00, 4.00]

	st = make_student(name, age, id, gpa); //use random values to make random struct

	return st; //return pointer to random Student
}

/** This function returns an array of pointers to random student
 *  structs.
 * 	@param num_students number of students to be stored in array
 * 	@return array of student pointers
 * 	@warning this function will return null if there isn't enough space
 *  	in memory for specified student collection
 * */
Student** make_students(int num_students){
	srand(time(0)); //initialize random seed generator with cur time
	Student ** st = malloc(sizeof(Student) * num_students);

	//if there isn't enough space in mem for st collection
	// just return null
	if(st == NULL)
		return NULL;

	for(int i = 0; i < num_students; i++){
		st[i] = make_random_student();  
	}

	return st;
}

/** This function prints out `num` Student structs with formatting.
 * 	@param st array of Student pointers
 * 	@param number of 
 * */
void print_students(Student** st, int num){
	if(st == NULL){
		printf("Not enough space in memory to create %d Student structs.\n", num );
		printf("Try again.\n");
	}
	else {
		for(int i = 0; i < num && st[i] != NULL; i++){
			print_student(st[i]);
		}
	}
}


int main(){
	int wpi_size = 10;
	Student ** wpi = make_students(wpi_size);
	print_students(wpi, wpi_size + 10);

	return 0;
}
