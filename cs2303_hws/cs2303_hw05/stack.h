/** Header file for stack data structure implementation
 *
 * @author Blake Nelson
 *
 */
#ifndef STACK_H
#define STACK_H

#define SZ_STACK (120)      // Number of elements to hold in stack

typedef struct stack {
  int num_elements;         /**< Num elements in the stack - 0 when empty */
  int max_elements;         /**< Size of elements array */
  void **top;               /**< Ptr to empty slot at current top of stack */
  void **base;              /**< Ptr to bottom (base) of the stack */
  void *elements[];          /**< These are the elements stored in the stack */
} Stack;

/** Function prototypes for stack operations 
 */

void * peek (Stack *stack);
void * pop (Stack *stack);
void * push (Stack *stack, void *element);
int isempty (Stack *stack);
int numelements (Stack *stack);
int maxelements (Stack *stack);
Stack * create (int max_elements);
void destroy (Stack *stack);


#endif


