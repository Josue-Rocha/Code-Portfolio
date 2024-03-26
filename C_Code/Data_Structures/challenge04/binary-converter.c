/* Title: binary-converter.c
 * Abstract: Converts a number inputed by the user into binary
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 2 hours
 * Date: 02/23/2023
 */

#include <stdio.h>
#include <stdlib.h>

//Create stack node struct
typedef struct stack_node{
	int data;
  	struct stack_node *next;
}stack_node;

//Create stack struct
typedef struct stack{
	struct stack_node *top;
}stack;

//Push into stack
void push( stack* the_stack, int the_value ){
	// Create insert node
  	stack_node *insert_node = malloc (sizeof(stack_node));
  	insert_node->data = the_value;
  	insert_node->next = NULL;

	// Check if the list is empty
  	if (the_stack->top == NULL){
    		the_stack->top = insert_node;
    	//return
    	return;
  	}

	//Otherwise add insert_node to the top of the stack
  	insert_node->next = the_stack->top;
  	the_stack->top = insert_node;
}

//Print the Singly Linked List 
void print_stack( stack_node* curr_ptr, int num){
	printf("%d => ", num);
  	while (curr_ptr != NULL) {
    	printf("%d", curr_ptr->data);
    	curr_ptr = curr_ptr->next;
  	}
	printf("\n");
}	
//Free all the elements 
void destructor( stack_node* curr_ptr ){
	// Create a tmp pointer
  	stack_node *tmp;
  	// Check if curr_ptr is NULL
 	 while(curr_ptr != NULL) {
   	// Set tmp to point to curr_ptr
    	tmp = curr_ptr;
    	//Advance curr_ptr
    	curr_ptr = curr_ptr->next;
    	//free tmp
    	free(tmp);
  	}
}
//Pop the top node
void pop(stack* the_stack ){
	// Check if the list is not empty
	if(the_stack->top == NULL) {
    		return;
  	}
	// Otherwise, move the top node to next and free old top node
 	stack_node *tmp = the_stack->top;
  	the_stack->top = the_stack->top->next;
  	free(tmp); 
}

int main(){
	//Dynamically allocate a stack 
	stack *the_stack = malloc (sizeof(stack));
	// Set the top to NULL 
  	the_stack->top = NULL;

	int remainder, choice, value, count;
	while(1){
		count = 0;
		printf("Enter a number: ");
		scanf(" %d", &choice);
		if(choice == 0){
			printf("Exiting\n");
			break;
		}else{
			value = choice;
			while(value != 0){
				remainder = value%2;
				if(remainder == 1){
					push(the_stack, 1);
				}else if(remainder == 0){
					push(the_stack, 0);
				}
				count++;
				value = value/2;
			}
			print_stack(the_stack->top, choice);
			for (int i = 0; i < count; i++){
				pop(the_stack);
			}
			
		}
	}

	//Call the destructor
	destructor(the_stack->top);
	
	//Free the stack 
  	free (the_stack);
	
	
	return EXIT_SUCCESS;
}
