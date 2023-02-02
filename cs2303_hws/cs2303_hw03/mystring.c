/** mystring.c
 * @author Ryan Mechery, Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"
#include "student.h"

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
  const char *ptr = s; //this is the pointer to mem which will hold string chars

  // This loops through ptr until it reaches the null character.
  // each time, it increments the pointer to reach the next substring
  while(*ptr != '\0'){
    ptr++;
  }
  return &ptr - &s; 
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


/**  The  strcat() function appends the `n` characters from src string to the 
     dest string. Doesn't need to be null-terminated if it contains `n` or more bytes. 
     If src contains n or more bytes, strncat() writes n+1 bytes to dest  (n
     from  src plus the terminating null byte).  Therefore, the size of dest
     must be at least strlen(dest)+n+1.

 * @param dest c-string pointer to be concatenated to
 * @param src c-string pointer to concatenate from 
 * @param n number of chars to copy
 * @return pointer to dest
 * */
char *mystrncat(char *dest, const char *src, size_t n){
  size_t s; //counter to hold idxs of src
  size_t d; //counter to hold idxs of dest

  d = mystrlen(dest); //d is initalized to index of '\0'

  //loops through characters of src until it hits n
  // or hits a null character
  for (s = 0; s < n && src[s] != '\0'; s++){
    dest[d++] = src[s];
  }

  //null-terminates last character 
  dest[d] = '\0';

  return dest;
}

/** copies at most `n` bytes from src to dest
 * @param dest c-string pointer to copy to
 * @param src c-string pointer to copy from
 * @return pointer to dest
 * @warning If there is no null byte among the first n  bytes
   of src, the string placed in dest will not be null-terminated.
 * */
char *mystrncpy(char *dest, const char *src, size_t n){
  size_t i; //counter for dest[]

  // loops through src until it hits n chars
  // or it reaches end of src
  for(i = 0; i < n && src[i]!= '\0'; i++)
    dest[i] = src[i];

  // if there are still n chars to fill
  // fill it with null chars
  for(i; i < n; i++)
    dest[i] = '\0';

  return dest;
}

/** Copies at most `n` bytes to a new string which is a partial duplicate
    of `s`
 * @param src Pointer to string to be copied
 * @param n number of bytes 
 * @return Pointer to freshly-allocated string containing a `n` length duplicate of 
        src or null if no memory is available
 * */
char *mystrndup(const char *s, size_t n){
  char* newstr; // Pointer to memory which will hold new string

  newstr = (char*) malloc(n);  // free space of n size

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
    return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrncpy(newstr, s, n);
  return newstr;
}

/** This code returns a random ASCII character depending on type inputted.
 *  1. If type is 0, return any ascii character [A-Z, a-z, 0-9].
 *  2. If type is 1, return an upper case character [A-Z]
 *  3. If type is 2, return a lower case character [a-z]
 *  4. If type is 3, return a random digit [0-9]
 * @param type integer within range [0-3]
 * @return random character (in case of error return '\0')
 * @warning Make sure time seed generator is initialized once before using
 *  this function.
 * */
char  get_random_char(int type){
  const int num_digits = 10; //prevent using magic numbers
  const int num_letters = 26; //prevent using magic numbers
  const int start_0 = 48; //ascii code of '0'
  const int start_A = 65;  //ascii code of 'A'
  const int start_a = 97;  //ascii code of 'a'

  //if user wants any ascii character in range [A-Z, a-z, 0-9]
  if(type == 0){
    // generate a random number from [0, 62) 
    int r = rand() % (num_digits + num_letters*2);

    //if r is in [0, 10) then return a random digit
    if(r < num_digits){
      return r + start_0;
    }

    //if r is in [10, 36) then return a random upcase letter
    else if(r < num_digits + num_letters){
      //convert int from [0, 26) then cast to ASCII
      return r - num_digits + start_A; 
    }

    //if r is in [36, 62) then return a random lowercase letter
    else {
      //convert int from [0, 26) then cast to ASCII
      return r - num_letters - num_digits + start_a;
    }
  }

  //else if user wants any ascii character in range [A-Z]
  else if(type == 1){
    return rand() % num_letters + start_A;
  }

  //else if user wants any ascii character in range [a-z]
  else if(type == 2){
    return rand() % num_letters + start_a;
  }

   //else if user wants any ascii character in range [0-9]
  else if(type == 3){
    return rand() % num_digits + start_0;
  }


  // if type not in [0,3] then return null char
  return '\0';
}

void generate_random_name(char * og_name, int MAX_CHARS){
  const int min = 3;
  const int max = 10;
  const int f_name_size = rand() % (max - min + 1)+ min;
  const int l_name_size = rand() % (max - min + 1)+ min;
  const int name_size = f_name_size + l_name_size + 2;

  char* name =  (char*) malloc(name_size);
  
  int i;
  for(i = 0; i < name_size - 1; i++ ){
    if(i == f_name_size)
      name[i] = ' ';
    else if(i == 0 || i == f_name_size + 1)
      name[i] = get_random_char(1);
    else
      name[i] = get_random_char(2);
  }

  name[i] = '\0';

  mystrncpy(og_name, name, MAX_CHARS);
  free(name);
}





