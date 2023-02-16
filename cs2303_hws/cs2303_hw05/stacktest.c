/** short program to demonstrate use of stack
 *
 * @author Blake Nelson
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** main function to demonstrate use of stack
 *
 */
int main (int argc, char *argv[]) {
  if(argc != 2){
    printf ("Enter exactly 1 argument into the command line!\n");
    return 1;
  }
  int user_size = atoi(argv[1]);
  if(user_size <= 0){
    printf ("Entered %d but max_elements must be >= 0!\n", user_size);
    return 1;
  }

  Stack *the_stack;
  // Create a stack to hold our test data
  the_stack = create( user_size );

  #ifndef DEBUG_TEST
    printf("Enter lines of strings into stack. Press CTRL+D to stop.\n");
  #endif

  ssize_t buff_size = 4096; //max size of line in unix terminal
  char ** buffers = calloc(user_size, buff_size);
  size_t buff_idx;

  for(buff_idx = 0; stdin != NULL && buff_idx < user_size; buff_idx++){

    getline(&buffers[buff_idx], &buff_size, stdin);

    #ifdef DEBUG_TEST
      printf("pushing element \"%s\"\n", buffers[buff_idx]);
    #endif

    push(the_stack, buffers[buff_idx]);

    #ifdef DEBUG_TEST
      printf("top of stack now \"%s\"\n", (char *) peek(the_stack));
    #endif
  }

  // Now pop the elements off the stack
  while (!isempty(the_stack)) {
    char *element = (char *) pop(the_stack);
    #ifdef DEBUG_TEST
      printf("popped element \"%s\"\n", element);
    #endif
    #ifndef DEBUG_TEST
      printf("%s", element);
    #endif
  }
 
  destroy(the_stack);
  free(buffers);

  return 0;
}

  
  
