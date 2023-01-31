/** mystring.c
 * @author Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		// Leave space for the terminator
  newstr = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/**  The strlen() function calculates the length of the string pointed to by
       s, excluding the terminating null byte ('\0').
 * @param s pointer to source string
 * @return returns the number of bytes in the string pointed
       to by s as an unsigned integer
 * */
size_t mystrlen(const char *s){
  char * beg = (char *) s; // contains the memory address of s[0]
  char *ptr = (char *) s; //this is the pointer to mem which will hold string chars

  // This loops through ptr until it reaches the null character.
  // each time, it increments the pointer to reach the next substring
  while(*ptr != '\0'){
    ptr++;
  }
  return &ptr - &beg; 
  //by returning the difference in mem addresses you get the size
}

/** 
 * The  strcpy()  function  copies the string pointed to by src, including
   the terminating null byte ('\0'), to the buffer  pointed  to  by  dest.
   The  strings  may  not overlap, and the destination string dest must be
   large enough to receive the copy.  
 * @param src string to be copied
 * @param dest string you want src to be copied to
 * @return Returns a pointer to  the  destination string dest.
 * @warning Beware  of  buffer  overruns!   
 * @bug If the destination string of a strcpy() is not large enough, then any‐
     thing  might  happen.  Overflowing fixed-length string buffers is a fa‐
     vorite cracker technique for taking complete control  of  the  machine.
     Any  time  a  program  reads  or copies data into a buffer, the program
     first needs to check that there's enough space.  This may  be  unneces‐
     sary  if you can show that overflow is impossible, but be careful: pro‐
     grams can get changed over time, in ways that may make  the  impossible
     possible.

 * */
char* mystrcpy(char *dest, const char *src){
  // loop through src characters and copy all 
  // characters from  src[0] to '\0' to dest
  do{
    *dest = *src;
    dest++;
    src++;
  } while(*(src - 1) != '\0');

  return dest;
}

/**
 * The  strcat() function appends the src string to the dest string, over‐
   writing the terminating null byte ('\0') at the end of dest,  and  then
   adds  a  terminating  null  byte.
 *
 * @param dest c-string pointer you want src to be concatenated to
 * @param src c-string pointer to concatenate from
 * @return pointer to dest containing dest + src
 * @warning  The strings may not overlap, and the dest string must have enough 
 *  space for the  result.   If  dest  is  not large  enough, program behavior 
 *  is unpredictable; buffer overruns are a favorite avenue for attacking secure 
 *  programs.

 * */
char* mystrcat(char *dest, const char *src){
  //this loops through dest until it reaches '\0'
  while(*dest != '\0'){
    dest++;
  }

  //*dest now equals '\0' which will be overridden

  // this will loop through src from src[0] to 
  // src[mystrlen(src) + 1]
  // final character of dest should be '\0' if
  // src contains '\0'
  do{
    *dest = *src;
    dest++;
    src++;
  } while(*(src - 1) != '\0');

  return dest;
}

char *mystrncat(char *dest, const char *src, size_t n){
  size_t i;
  size_t d;

  d = mystrlen(dest); //d is initalized to index to index of '\0'

  for (i = 0; i < n && src[i] != '\0'; i++){
    dest[d] = src[i];
    d++;   
  }

  for (; i < n; i++){
    dest[d] = '\0';
    d++;
  }

  return dest;
}


