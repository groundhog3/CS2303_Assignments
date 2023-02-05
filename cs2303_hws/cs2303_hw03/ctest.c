#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

/** ctest.c
* Program to demonstrate character arrays and dynamically-allocated memory.
* @author Ryan Mechery, Mike Ciaraldi, Blake Nelson
*/

const int MAX_CHARS = 20;    // Maximum number of characters in array


int main()
{
  char a1[MAX_CHARS + 1]; 	 // Character array--initially empty
  char a2[] = "Hello"; 		   // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	 // Character array--we will underfill it
  const char *p1 = "Hello";  // Pointer to constant string
  char *p2;           		   // Will be a pointer to dynamically-allocated string
  int copy_limit;     		   // Maximum characters to copy.

  char b[MAX_CHARS];         // Character array -- initially empty
  const char *b_part = "345"; // Contains string which part will be copied to b;

  char c[MAX_CHARS];         // Character array -- initially empty
  char *c_copy;              // Will be a pointer to dynamically-allocated string
  const char *c_part="123456789"; // Pointer to constant string



  /* Print the pointers.
  Note: this example prints
  the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p, b: %p\n", a1, a2, a3, b);
  printf("Pointers: p1: %p, p2: %p, c_copy: %p \n", p1, p2, c_copy);

  mystrcpy(a1, "Hi"); 		// Initialize character array a1 with some text
  mystrcpy(a3, "Hello, also");    // Initialize uinderfilled character array
  mystrcpy(b, "012"); //Initialize b with 4 chars
  mystrcpy(c, "ABCDEFG"); //Initialize c with 8 chars


  // Print the values of the C-style strings
  printf("\n");
  printf("C-string values:\n");
  printf("a1:\t%s\n", a1);
  printf("a2:\t%s\n", a2);
  printf("a3:\t%s\n", a3);
  printf("b:\t%s\n", b);
  printf("b_part:\t%s\n", b_part);
  printf("c:\t%s\n", c);

  /* Concatenate two character arrays, then print.
  *  Terminator character in the last element of the array as well as after "Hi"
  */
  a1[MAX_CHARS] = '\0';		
  mystrcat(a1, a2);
  printf("\n");
  printf("After concatenating a2 to the end of a1\n");
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?

  printf("\n");
  printf("Concatenating a2 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
    mystrncat(a1, a2, copy_limit);

    printf("a1: %s\n", a1);
  }

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?
  printf("\n");
  printf("Concatenating a3 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
    mystrncat(a1, a3, copy_limit);

    printf("a1: %s\n", a1);
  }

  //--------------------------------------------------------
  //mystrncat() Test 1: length of string is shorter than src
  copy_limit = 3; // copy_limit < src
  printf("\nmystrncat() Test #1: copy_limit < src\n");
  printf("Concatenating %d char(s) of b_part to b\n", copy_limit);

  mystrncat(b, b_part, copy_limit);
  printf("b: %s\n", b);

  //mystrncat() Test 2: length of string is equal to src
  copy_limit = mystrlen(b_part) + 1; //copy_limit = src
  printf("\nmystrncat() Test #2: copy_limit = n\n");
  printf("Concatenating %d char(s) of b_part to b\n", copy_limit);

  mystrncat(b, b_part, copy_limit);
  printf("b: %s\n", b);

  //mystrncat() Test 3: length of string is greater than src
  copy_limit = mystrlen(b_part) + 5; //copy_limit > src
  printf("\nmystrncat() Test #3: copy_limit > n\n");
  printf("Concatenating %d char(s) of b_part to b\n", copy_limit);

  mystrncat(b, b_part, copy_limit);
  printf("b: %s\n", b);

  //--------------------------------------------------------
  // Test mystrncpy()
  //mystrncpy() Test 1: length of string is shorter than n
  copy_limit = 3; // copy_limit < n
  printf("\nmystrncpy() Test #1: copy_limit < n\n");
  printf("Copying %d char(s) of c_part to c\n", copy_limit);

  mystrncpy(c, c_part, copy_limit);
  printf("c: %s\t size: %lu\n", c, mystrlen(c));
  mystrcpy(c, "ABCDEFG"); //reset C

  //mystrncpy() Test 2: length of string is equal to n
  copy_limit = mystrlen(c) + 1; //copy_limit = n
  printf("\nmystrncpy() Test #2: copy_limit = n\n");
  printf("Copying %d char(s) of c_part to c\n", copy_limit);
  printf("\x1B[31mNot NULL terminated\x1B[0m\n");

  mystrncpy(c, c_part, copy_limit);
  printf("c: %s\t size: %lu\n", c, mystrlen(c));
  mystrcpy(c, "ABCDEFG"); //reset C

  //mystrncpy() Test 3: length of string is equal to src
  copy_limit = mystrlen(c_part) + 5; //copy_limit > n && copy_limit > src
  printf("\nmystrncpy() Test #3: copy_limit > n && copy_limit > src\n");
  printf("Copying %d char(s) of c_part to c\n", copy_limit);
  printf("\x1B[32mWill be NULL terminated\x1B[0m\n");
  
  mystrncpy(c, c_part, copy_limit);
  printf("c: %s\t size: %lu\n", c, mystrlen(c));
  mystrcpy(c, "ABCDEFG"); //reset C


  //--------------------------------------------------------
  // Duplicate a string, using my function, then print
  printf("\n");
  printf("Before dup, array a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 =  %p, contents = %s\n", p2, p2);


  //Test partial Duplication
  copy_limit = 3;
  printf("\nBefore dup, array c = %p, contents = %s\n", c, c);
  c_copy = mystrndup(c, copy_limit);
  printf("After dup, pointer c_copy to b[0:%d] =  %p, contents = %s\n", copy_limit, c_copy, c_copy);
   printf("\x1B[32mWill be NULL terminated\x1B[0m\n");

  //Free the memory allocated on our behalf by mystrdup()
  free(p2);
  free(c_copy);

  return 0;
}
