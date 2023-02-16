/** stacktest2.c
 * The stacktest2 program will reverse the order of characters in a string using a stack. 
 * @author Ryan Mechery
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * main
 * 
 * */
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

	Stack *main_stack;
  	// Create a stack to hold our test data
  	main_stack = create( user_size );

  	#ifndef DEBUG_TEST
  		printf("Enter lines of strings into stack. Press CTRL+D to stop.\n");
  	#endif

  	ssize_t buff_size = 4096; //max size of line in unix terminal
  	char ** buffers = calloc(user_size, buff_size);
  	size_t buff_idx;
  	ssize_t buff_line_sz;

  	Stack *sub_stack[max_elements];

	for(buff_idx = 0; stdin != NULL && buff_idx < user_size; buff_idx++){
		buff_line_sz = getline(&buffers[buff_idx], &buff_size, stdin);

		#ifdef DEBUG_TEST
		  printf("pushing element \"%s\"\n", buffers[buff_idx]);
		#endif

		sub_stack[buff_idx] = create (buff_line_sz);
		int i; //temp counter 
		for(i = 0; i < buff_line_sz; i++){
			push(sub_stack[buff_idx], buffers[buff_idx][i]);
		}

		push(main_stack, buffers[buff_idx]);

		#ifdef DEBUG_TEST
		  printf("top of stack now \"%s\"\n", (char *) peek(main_stack));
		#endif
	}

		// Now pop the elements off the stack
	#ifdef DEBUG_TEST
	    printf("Output: \n");
	#endif

	while (!isempty(main_stack)) {
		char *element = (char *) pop(main_stack);
		#ifdef DEBUG_TEST
		  printf("popped element \"%s\"\n", element);
		#endif
		#ifndef DEBUG_TEST
		  printf("%s", element);
		#endif
	}

	destroy(main_stack);
	destroy(sub_stack);
	free(buffers);
}