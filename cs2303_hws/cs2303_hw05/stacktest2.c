/** stacktest2.c
 * The stacktest2 program will reverse the order of characters in a string using a stack. 
 * @author Ryan Mechery
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "stack.h"

#define MAXLINE (4096) 

/** main function to demonstrate use of stack
 *  @return 0 on success
 *  @return 1 on invalid parameters or invalid stack size
 */
int main (int argc, char *argv[]) {
	if(argc != 2){
		printf ("Enter exactly 1 argument into the command line!\n");
		return 1;
	}
	int user_size = atoi(argv[1]);  //get user_size from first arg input
	if(user_size < 0){
		printf ("Entered %d but max_elements must be >= 0!\n", user_size);
		return 1;
	}

	Stack *main_stack; // Create a stack that holds a set of stacks
  	main_stack = create( user_size ); //set size of stack to user_def size

  	if(main_stack == NULL){
      printf("Not enough space to create main_stack.\n");
      return 1;
 	}

  	#ifdef DEBUG_TEST
  		printf("Enter lines of strings into stack. Press CTRL+D to stop.\n");
  	#endif

  	ssize_t buff_size = MAXLINE; //max size of line in unix terminal
  	char ** buffers = calloc(user_size, buff_size); 
    //array that holds dyn. allocated array of strings

  	if(buffers == NULL){
  		printf("Not enough space to create buffers array.\n");
  		return 1;
  	}

  	size_t buff_idx; //counter for loop
  	ssize_t buff_line_sz; //contains actual line size of each line

  	Stack *sub_stack[user_size]; // contains pointers to stacks in the_stack


  	// this loop terminates either when either:
  	// a) getline is null
  	// b) max elements in stack reached
	for(buff_idx = 0; 
		(buff_line_sz = getline(&buffers[buff_idx], &buff_size, stdin)) != -1 
		&& buff_idx < user_size; buff_idx++){
		
		#ifdef DEBUG_TEST
		  printf("pushing element \"%s\"\n", buffers[buff_idx]);
		#endif

		sub_stack[buff_idx] = create (buff_line_sz); //create sub_stack

		if(sub_stack[buff_idx] == NULL){
			printf("Not enough space to create sub_stack[%ld]\n", buff_idx);
  			return 1;
		}

		int i; //temp counter
		//this loop pushes all characters to sub stack except '\n' and '\0'
		for(i = 0; i < buff_line_sz; i++){
			if(buffers[buff_idx][i] != '\0' && buffers[buff_idx][i] != '\n'){
				push(sub_stack[buff_idx], &buffers[buff_idx][i]);
			}
		}
	
		push(main_stack, sub_stack[buff_idx]); //push substack into stack

		#ifdef DEBUG_TEST
		  printf("top of stack now \"%s\"\n", (char *) peek(main_stack));
		#endif
	}

 	// Now pop the substacks off the stack
	while (!isempty(main_stack)) {
		Stack *sub = (Stack *) pop(main_stack);
		//Pop each character off each sub stack
		while(!isempty(sub)){
			char *element = (char *) pop(sub);
			printf("%c", *element);
		}
		printf("\n");
		destroy(sub); //free sub_stack
	}
	
	destroy(main_stack); //free main_stack
	free(buffers);  //free buffer array
}