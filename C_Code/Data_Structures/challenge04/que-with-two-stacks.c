/* Title: que-with-two-stacks.c
 * Abstract: Crete a que using two structs
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 3 hours
 * Date: 02/23/2023
 */

#include<stdio.h>
#include<stdlib.h>
typedef struct stack_node{
	int data;
	struct stack_node *next;
}stack_node;

typedef struct stack{
	struct stack_node *top;
}stack;

void push( stack* the_stack, int the_value ){
	// Create insert node
  	stack_node *insert_node = malloc(sizeof(stack_node));
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
int isEmpty(stack* the_stack){
	if(the_stack->top == NULL){
		return 1;
	}else{
		return 0;
	}
}
void enque(stack *the_stack, int value){
	push(the_stack, value);
}
void deque(stack *s1, stack *s2){
	if (isEmpty(s2)){
		while(!isEmpty(s1)){
			push(s2, s1->top->data);
			pop(s1);
		}
	}
	printf("\nDequed element: %d\n", s2->top->data);
	pop(s2);
}
// moves content from one que to another
void move_stack(stack* s1, stack *s2){
	while(!isEmpty(s1)){
		push(s2, s1->top->data);
		pop(s1);
	}
}

void display(stack* s1, stack *s2){
	printf ("\nQue front to back: ");
	stack_node *s2_ptr = s2->top;
	while(s2_ptr != NULL){
		printf("%d ", s2_ptr->data);
		s2_ptr = s2_ptr->next;
	}
	if (!isEmpty(s1)){
		stack *temp_stack = malloc(sizeof(stack));
		temp_stack->top = NULL;

		move_stack(s1, temp_stack);

		stack_node *curr_ptr = temp_stack->top;
		while(curr_ptr != NULL){
			printf("%d ", curr_ptr->data);
			curr_ptr = curr_ptr->next;
		}
		move_stack(temp_stack, s1);
	}
  	printf("\n\n");	
}

int main(void){
	stack *stack1 = malloc(sizeof(stack));
	stack *stack2 = malloc(sizeof(stack));

	stack1->top = NULL;
	stack2->top = NULL;

	int choice;
	printf("This is a list of operations on the que.\n\n	1. Enque\n	2. Deque\n	3. Display\n\n");

	while(1){
		printf("Enter your option: ");
		scanf(" %d", &choice);

		if (choice == 1){
			int value;
			printf("Enter value to enque: ");
			scanf(" %d", &value);
			enque(stack1, value);
			display(stack1, stack2);
		}else if (choice == 2){
			deque(stack1, stack2);
			display(stack1, stack2);
		}else if (choice == 3){
			display(stack1, stack2);
		}else{
			printf("Error, invalid option eneterd:\n");
		}
		char letter;
		printf("Countinue? (Y/N) ");
		scanf(" %c", &letter);
		if (letter == 'N'){
			break;
		}
	}
	free(stack1);
	free(stack2);

	return 0;
}

