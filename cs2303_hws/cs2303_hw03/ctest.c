// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and dynamically-allocated memory.
 * @author Mike Ciaraldi, Blake Nelson
 */

const int MAX_CHARS = 20;       // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; 	// Character array--initially empty
  char a2[] = "Hello"; 		// Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	// Character array--we will underfill it
  const char *p1 = "Hello";     // Pointer to constant string
  char *p2;           		// Will be a pointer to dynamically-allocated string
  int copy_limit;     		// Maximum characters to copy.
  char a4[MAX_CHARS]; // Character array--initially empty
  char *p4;               // Will be a pointer to dynamically-allocated string


  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p, a4: %p\n", a1, a2, a3, a4);
  printf("Pointers: p1: %p, p2: %p, p4: %p\n", p1, p2, p4);

  mystrcpy(a1, "Hi"); 		// Initialize character array a1 with some text
  mystrcpy(a3, "Hello, also");    // Initialize uinderfilled character array
  mystrcpy(a4, "David, additionally");    // Initialize character array with MAX_CHARS - 1 chars


  // Print the values of the C-style strings
  printf("\n");
  printf("C-string values:\n");
  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);
  printf("a3: %s\n", a3);
  printf("a4: %s\n", a4);

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
 }
 printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?
  printf("\n");
  printf("Concatenating a3 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
   mystrncat(a1, a3, copy_limit);
 }
 printf("a1: %s\n", a1);

  // Duplicate a string, using my function, then print
 printf("\n");
 printf("Before dup, array a2 = %p, contents = %s\n", a2, a2);
 p2 = mystrdup(a2);
 printf("After dup, pointer p2 =  %p, contents = %s\n\n", p2, p2);

  // Free the memory allocated on our behalf by mystrdup()
 free(p2);

  // Test mystrncpy
 copy_limit = 3;
 mystrncpy(a4, "Hello", copy_limit);
 printf("After strncpy-ing 'Hello' to a4 with a copy_limit = %d\n", copy_limit);
 printf("a4: %s\n", a4);

 printf("\n");
 printf("Before mystrndup with copy_limit = %d, array a4 = %p, contents = %s\n", copy_limit, a4, a4);
 p4 = mystrndup(a4, copy_limit);
 printf("Size: %lu\n", strlen(p4));
 printf("After mystrndup with copy_limit = %d, pointer p4 =  %p, contents = %s\n\n", copy_limit, p4, p4);
 printf("\n");

  // Free the memory allocated on our behalf by mystrdup()
 free(p4);

 copy_limit = 10;
 printf("Before mystrndup with copy_limit = %d, array a4 = %p, contents = %s\n", copy_limit, a4, a4);
 p4 = mystrndup(a4, copy_limit);
 printf("After mystrndup with copy_limit = %d, pointer p4 =  %p, contents = %s\n\n", copy_limit, p4, p4);
 printf("\n");

 copy_limit = mystrlen(a4);
 printf("Before mystrndup with copy_limit = %d, array a4 = %p, contents = %s\n", copy_limit, a4, a4);
 p4 = mystrndup(a4, copy_limit);
 printf("After mystrndup with copy_limit = %d, pointer p4 =  %p, contents = %s\n\n", copy_limit, p4, p4);
 printf("\n");


 return 0;
}

