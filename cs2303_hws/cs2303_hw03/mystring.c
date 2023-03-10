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


/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		  // Leave space for the terminator
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
 * @return the number of bytes in the string pointed
       to by s as an unsigned integer
 * */
size_t mystrlen(const char *s){
  const char *ptr = s; //this is the pointer to mem which will hold string chars

  // This loops through ptr until it reaches the null character.
  // each time, it increments the pointer to reach the next substring
  while(*ptr != '\0'){
    ptr++;
  }
  return ptr - s; 
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
 * @bug If the destination string of a strcpy() is not large enough, then any???
     thing  might  happen.  Overflowing fixed-length string buffers is a fa???
     vorite cracker technique for taking complete control  of  the  machine.
     Any  time  a  program  reads  or copies data into a buffer, the program
     first needs to check that there's enough space.  This may  be  unneces???
     sary  if you can show that overflow is impossible, but be careful: pro???
     grams can get changed over time, in ways that may make  the  impossible
     possible.
 * */
char* mystrcpy(char *dest, const char *src){
  // loop through src characters and copy all 
  // characters from  src[0] to '\0' to dest

  //do while allows '\0' to be copied as well
  do{
    *dest = *src;
    dest++;
    src++;
  } while(*(src - 1) != '\0');

  return dest;
}

/**
 * The  strcat() function appends the src string to the dest string, over???
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

  // this will loop through src[0] to src[mystrlen(src) + 1]
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
  char* d = dest + mystrlen(dest); //pointer for dest initialized to '\0'
  int i = 0; //counter for n

  //loops until end of src or it hits n chars
  while(*src != '\0' && i < n){
    *d++ = *src++;
    i++;
  }

  *d = '\0'; 
  //regardless of what happened prior, dest should be null terminated

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

  newstr = (char*) malloc(n + 1);  // free space for n chars and '\0'

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
    return NULL;
  }

  // Otherwise, copy the string and return pointer to new string
  strncpy(newstr, s, n); //copies s[0:n] chars to newstr
  *(newstr + n) = '\0'; //terminate last idx with null character

  return newstr;
}


/** Returns a random alphanumeric. 
 *  @return random alphanumeric character (in case of error return '\0')
 *  @warning Make sure time seed generator is initialized once before using
 *  this function.
 * */
char get_any_alphanumeric(){
  const int num_digits = 10; //prevent using magic numbers
  const int num_letters = 26; //prevent using magic numbers

  // generate a random number from [0, 62) 
  int r = rand() % (num_digits + num_letters*2);

  //if r is in [0, 10) then return a random digit
  if(r < num_digits)
    return r + '0'; 

  //if r is in [10, 36) then return a random upcase letter
  else if(r < num_digits + num_letters)
    return r - num_digits + 'A'; //convert int from [0, 26) then cast to ASCII
  
  //if r is in [36, 62) then return a random lowercase letter
  else 
    return r - num_letters - num_digits + 'a'; //convert int from [0, 26) then cast to ASCII
  

  return '\0'; // in case of error
}

/** Works like get_any_alphanumeric() but with type can get more specific
 *  characters. Needed to make a random name.
 *  1. If type is 0, return any ascii character [A-Z, a-z, 0-9].
 *  2. If type is 1, return an upper case character [A-Z]
 *  3. If type is 2, return a lower case character [a-z]
 *  4. If type is 3, return a random digit [0-9]
 * @param type integer within range [0-3]
 * @return random character (in case of error return '\0')
 * @warning Make sure time seed generator is initialized once before using
 *  this function.
 * */
char  get_alphanum(int type){
  const int num_digits = 10; //prevent using magic numbers
  const int num_letters = 26; //prevent using magic numbers

  switch(type){
    case 0:
      return get_any_alphanumeric(); //use previous function
      break;
    case 1:
      return rand() % num_letters + 'A';
      break;
    case 2:
      return rand() % num_letters + 'a';
      break;
    case 3:
      return rand() % num_digits + '0';
      break; 
  }

  // if type not in [0,3] then return null char
  return '\0';
}


/** This function uses `get_alphanum()` to generate a random name
 *  of min length 5 and max length `n` for the student struct. This 
 *  function will null terminate og_name regardless of length of name.
 *  @param og_name this is the destination string pointer
 *  @param max_chars maximum size of og_name pointer
 *  @return pointer to source string `og_name`
 * */
char* generate_random_name(char * og_name, int max_chars){
  const int min = 3; //min length of f_name and l_name
  const int max = 13; //max length of f_name and l_name
  const int f_name_size = rand() % (max - min + 1)+ min; //[3,13]
  const int l_name_size = rand() % (max - min + 1)+ min; //[3,13]
  const int name_size = f_name_size + l_name_size + 2;
  //allocates space for f_name, space, l_name , & '\0'

  char* name =  (char*) malloc(max_chars); //creates temp pointer
  
  int i; //counter for loop below

  //this loops through name pointer and adds f_name, ' ', & l_name
  // based on current index until it hits max_chars
  for(i = 0; i < max_chars; i++ ){
    if(i == f_name_size)
      name[i] = ' ';
    else if(i == 0 || i == f_name_size + 1)
      name[i] = get_alphanum(1); //get random upper case char
    else if(i < name_size - 1)
      name[i] = get_alphanum(2); //get random lower case char
    else { //break if name_size <= i < max_chars 
      name[i] = '\0';
      break;
    }
  }

  mystrncpy(og_name, name, max_chars); //copies at most max_chars to og_name
  og_name[max_chars - 1] = '\0'; //null terminate if name is too long

  free(name); //since name was temporary it frees it from memory

  return og_name;
}





