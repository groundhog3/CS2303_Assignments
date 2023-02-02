/** student.h
 * @author Ryan Mechery, Mike Ciaraldi, Blake Nelson
 * Header file for functions in student.c file
*/
#ifndef STUDENT_H		// Remember guard
#define STUDENT_H

// Function prototype(s):
struct Student* make_student(char* name, int age, int id, double gpa);
void print_student(struct Student* st);

#endif
