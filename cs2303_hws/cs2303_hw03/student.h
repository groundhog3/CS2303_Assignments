/** student.h
 * @author Ryan Mechery
 * Header file for functions in student.c file
*/
#ifndef STUDENT_H		// Remember guard
#define STUDENT_H

// Function prototype(s):

typedef struct Student Student;

Student* make_student(char* name, int age, int id, double gpa);
Student* make_random_student();
void print_student(Student* st);
void print_students(Student** st, int num);
Student** make_shallow_copy(Student** og_st, int size);
Student** make_deep_copy(Student** og_st, int size);
Student** make_random_structs(int num_students);
void free_students(Student** st, int size);

#endif
