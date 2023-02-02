// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and dynamically-allocated memory.
 * @author Ryan Mechery, Mike Ciaraldi, Blake Nelson
 */

const int MAX_CHARS = 20;       // Maximum number of characters in array


int main()
{
  char a1[MAX_CHARS + 1]; 	// Character array--initially empty
  char a2[] = "Hello"; 		// Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	// Character array--we will underfill it
  char b[MAX_CHARS];             // Character array -- initially empty
  const char *p1 = "Hello";     // Pointer to constant string
  char *p2;           		// Will be a pointer to dynamically-allocated string
  int copy_limit;     		// Maximum characters to copy.


  char *b_copy;           // Pointer to partial copy of b
  const char *part_string = "7890123";  // Contains string which part will be copied to b;
  const size_t s = 3;          // size of chars to copy from b


  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p, b: %p\n", a1, a2, a3, b);
  printf("Pointers: p1: %p, p2: %p, b_copy: %p \n", p1, p2, b_copy);

  mystrcpy(a1, "Hi"); 		// Initialize character array a1 with some text
  mystrcpy(a3, "Hello, also");    // Initialize uinderfilled character array
  mystrcpy(b, "123456");


  // Print the values of the C-style strings
  printf("\n");
  printf("C-string values:\n");
  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);
  printf("a3: %s\n", a3);
  printf("b: %s\n", b);

  /* Concatenate two character arrays, then print.
  *  Terminator character in the last element of the array as well as after "Hi"
  */
  a1[MAX_CHARS] = '\0';		
  mystrcat(a1, a2);
  printf("\n");
  printf("After concatenating a2 to the end of a1\n");
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); 	// How much space is left?
  
  printf("\n");
  printf("Concatenating a2 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
   mystrncat(a1, a2, copy_limit);

   printf("a1: %s\n", a1);
  }

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); 	// How much space is left?
  printf("\n");
  printf("Concatenating a3 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
   mystrncat(a1, a3, copy_limit);

   printf("a1: %s\n", a1);
  }


 // Test partial copy
   printf("\nBefore adding partial string, \n");
   printf("b: %s\n", b);
   mystrncpy(b, part_string, s);
   printf("After adding first %lu char(s) of  \"%s\",\n", s, part_string);
   printf("b: %s\n", b);

  // Duplicate a string, using my function, then print
   printf("\n");
   printf("Before dup, array a2 = %p, contents = %s\n", a2, a2);
   p2 = mystrdup(a2);
   printf("After dup, pointer p2 =  %p, contents = %s\n", p2, p2);

 //Test partial Duplication
   printf("\nBefore dup, array b = %p, contents = %s\n", b, b);
   b_copy = mystrndup(b, s);
   printf("After dup, pointer b_copy to b[0:%lu] =  %p, contents = %s\n", s, b_copy, b_copy);

   srand(time(0));
   char random_name[MAX_CHARS];
   for(int i = 0; i < 10; i++){
    generate_random_name(random_name, MAX_CHARS);
    printf("%s\n", random_name);
   }

  // Free the memory allocated on our behalf by mystrdup()
   free(p2);
   free(b_copy);

   return 0;
 }
