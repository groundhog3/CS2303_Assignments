/** student.c
 *  @author Ryan Mechery
 *  Defines custom struct for a Student with a name, age, id, and grades[].
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystring.h"
#include "student.h"

#define MAX_NAME_SIZE (20) //contains max size of name string
#define HORZ_BAR ("―――――――――――――――――――――――――――――――――――――――\n") //just a horizontal bar

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
typedef struct Student {
	char name[MAX_NAME_SIZE];
	int age;
	int id;
	double gpa;
} Student;


/** Dynamically allocates and returns pointer to a student struct in the heap.
 * 	@param name c-string pointer for Student.name
 * 	@param age  int for Student.age
 * 	@param id int for Student.id
 * 	@param gpa double for Student.gpa
 * 	@return pointer to new Student struct
 * 	@warning If there is no space in memory, this method will return a null pointer.
 * 		Also, it is the user's responsibility to make sure name is null-terminated.
 * */
Student* make_student(char* name, int age, int id, double gpa){
	Student* st = malloc(sizeof(Student)); //create new student in heap

	//if no space in memory for st then just return a null ptr
	if(st == NULL)
		return NULL;

	//regardless of size of name, copies at most MAX_NAME_SIZE chars
	mystrncpy(st->name, name, MAX_NAME_SIZE); //assign name to struct
	st->age = age; //assign age to struct
	st->id = id; //assign id to struct 
	st->gpa = gpa; //assign gpa to struct

	return st; //return new student pointer
}

/** Prints fields of student struct with formatting
 * 	@param st pointer to Student struct
 * 	@warning Student pointer cannot be null!
 * */
void print_student(Student* st){
	printf(HORZ_BAR);
	printf("Student's name: %s\n", st->name);
	printf("Age: %d\tID#: %05d\n", st->age, st->id );
	printf("Current GPA: %.2f\n", st->gpa);
	printf("Memory Address: %p\n", st);
}

/** Use `make_student()` with random values to make random student struct
 * 	@return pointer to random Student struct
 * */
Student* make_random_student(){
	Student *st; //pointer for Student in heap

	char name[MAX_NAME_SIZE]; //temp array where random name will be held
	generate_random_name(name, MAX_NAME_SIZE); //store random name in name
	name[MAX_NAME_SIZE - 1] = '\0'; //null terminate just in case

	int age = rand() % (18 - 2 + 1) + 2; //age from [2,18]
	int id = rand() % 100000; //[0, 99999] 5 digit id
	double gpa = (rand() % 401)/100.0; //[0.00, 4.00] unweighted gpa

	st = make_student(name, age, id, gpa); //use random values to make random struct

	return st; //return pointer to random Student
}

/** This function returns an array of pointers to random student
    structs.
 * 	@param num_students number of students to be stored in array
 * 	@return array of student pointers
 * 	@warning this function will return null if there isn't enough space
 *  	in memory for specified student collection
 * */
Student** make_random_structs(int num_students){
	Student ** st = malloc(sizeof(Student*) * num_students);

	//if there isn't enough space in mem for st collection
	// just return null
	if(st == NULL)
		return NULL;

	srand(time(0)); //initialize random seed generator with cur time
	for(int i = 0; i < num_students; i++){
		st[i] = make_random_student();
	}

	return st;
}

/** This function prints out `num` Student structs with formatting.
 * 	@param st array of Student pointers
 * 	@param number of st structs to print out
 *  @warning If you pass in a null pointer, this function will catch it
 * 		but it will NOT stop the program.
 * */
void print_students(Student** st, int num){
	if(st == NULL){
		printf("Given struct is \x1b[31mNULL\x1b[0m. Memory may be full.\n");
	}
	//if st is not null print each struct out
	else {
		//loops until either prints `num` structs or hits null struct
		for(int i = 0; i < num; i++){
			if(st[i] == NULL){
				printf("Student %d of %d is \x1b[31mNULL\x1b[0m\n", i+1, num);
			}
			else
				print_student(st[i]);
		}
	}
	printf(HORZ_BAR);
	printf("\n");
}

/** Given an array of Student structs, return a shallow copy with an array of pointers
 * 	@param og_st array of Student structs
 * 	@param size number of structs in og_st
 * 	@return array of Student struct pointers
 *  @warning If there isn't enough space in memory, this function returns a NULL pointer.
 * */
Student** make_shallow_copy(Student** og_st, int size){
	Student** copy_st = malloc(sizeof(Student*) * size); //only allocate space for n pointers
	if(copy_st == NULL){
		return NULL;
	}

	//for each of the Students in og_st array, copy pointers 
	for(int i = 0; i < size; i++){
		copy_st[i] = og_st[i]; 
	}

	return copy_st;
}


/** Free all Structs in an array from the heap and set pointer to NULL
 * 	@param st array of Student structs
 * 	@size size number of structs in st
 * 	@warning By setting pointers to null <em>after</em> struct has been 
 * 		deallocated, it deletes memory addresses in original student struct. 
 * 		However if a shallow_copy was created, it won't delete those pointers 
 * 		from memory. User must keep this in mind. 
 * */
void free_students(Student** st, int size){
	for(int i = 0; i < size && st[i] != NULL; i++){
		free(st[i]); //deallocate mem
		st[i] = NULL; //after free sets pointer to NULL
	}
}

/** Return the deepest possible copy of Student struct collection
 * 	by allocating memory for copies of Student structs and copying in struct members.
 * 	@param og_st array of Student structs
 * 	@size size number of structs in st
 * 	@return pointer to deepest copy of og_st
 *  @warning This method should be null safe for structs only. May result
 *   in an error if pointers in struct members are null.
 * */
Student** make_deep_copy(Student** og_st, int size){
	Student** copy_st = malloc(sizeof(Student*) * size);
	if(copy_st == NULL)
		return NULL;

	//loop through struct members
	for(int i = 0; i < size; i++){
		// if non-null create a copy of struct
		// w/make_student which will allocate new memory in heap
		if(og_st[i] != NULL){
			Student *st = make_student(	og_st[i]->name, 
										og_st[i]->age, 
										og_st[i]->id, 
										og_st[i]->gpa);
			copy_st[i] = st;
		}
		//if null, set copy struct to NULL as well
		else {
			copy_st[i] = NULL;
		}
	}

	//return pointer to new copy
	return copy_st;
}

