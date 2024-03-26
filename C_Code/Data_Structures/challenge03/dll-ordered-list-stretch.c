/* Title: dll-ordered-list-stretch.c
 * Abstract: This program displays defines a struct named OrderedList to store integers in ascending order and has 11 functions relating to that list. The last function reverses the list.
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 2 hours
 * Date: 02/16/2023
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}Node;

typedef struct OrderedList{
	struct Node *head;
  	struct Node *tail;

}OrderedList;

void insert_node(OrderedList* the_list, int the_value ){
	Node *insert_node = malloc (sizeof (Node));
	insert_node->data = the_value;
	insert_node->prev = NULL;
	insert_node->next = NULL;

	if (the_list->tail == NULL) {
		the_list->head = insert_node;
		the_list->tail = insert_node;
		return;
	}
	Node *reference = the_list->tail;
	the_list->tail = insert_node;
  	insert_node->prev = reference;
  	reference->next = insert_node;
}
void displayAll(Node* curr_ptr){
	printf("\nDisplaying all nodes:\n    ");
	while (curr_ptr != NULL) {
		printf ("%d", curr_ptr->data);
		if (curr_ptr->next != NULL) printf(" -> "); // print the ' -> ' after every number except for the last one
		curr_ptr = curr_ptr->next;
	}
	printf("\n");
}
void displayNth(OrderedList* the_list){
	int num, val;
	printf("Enter n to display nth node: ");
	scanf(" %d", &num);
	Node* curr_ptr = the_list->head;
	// move pointer to correct position
	for (int i = 0; i < num-1; i++){
		curr_ptr = curr_ptr->next;
	}
	val = curr_ptr->data;
	printf("\nDisplaying node %d:\n%d\n", num, val);
}
// appends to  the head of the list (makes the appendHeadOrTail function cleaner)
void add_to_head(OrderedList *list, int num){
	Node* insert_node = (Node*)malloc(sizeof(Node));
	insert_node->data = num;
	insert_node->prev = NULL;
	insert_node->next = NULL;

	Node *reference = list->head;
	list->head = insert_node;
  	insert_node->next = reference;
  	reference->prev = insert_node;
}
// appends to  the tail of the list (makes the appendHeadOrTail function cleaner)
void add_to_tail(OrderedList *list, int num){
	Node* insert_node = (Node*)malloc(sizeof(Node));
	insert_node->data = num;
	insert_node->prev = NULL;
	insert_node->next = NULL;

	Node *reference = list->tail;
	list->tail = insert_node;
  	insert_node->prev = reference;
  	reference->next = insert_node;
}
void appendHeadOrTail(OrderedList *list, int check){
	int num;
	char append;
	printf("Append to head or tail? (H/T): ");
	scanf(" %c", &append);
	if (append == 'H'){
		printf("Node at the head of the list is %d\n", list->head->data);
		if(check == 0){
			printf("Enter an integer less than %d to append to list: ", list->head->data);
			scanf(" %d", &num);

			while(num >= list->head->data){
				printf("Enter an integer less than %d to append to list: ", list->head->data);
				scanf(" %d", &num);
			}
		}else{ // in case list has been reveresed
			printf("Enter an integer greater than %d to append to list: ", list->head->data);
			scanf(" %d", &num);

			while(num <= list->head->data){
				printf("Enter an integer greater than %d to append to list: ", list->head->data);
				scanf(" %d", &num);
			}
		}
		add_to_head(list, num);
	}else if (append == 'T'){
		printf("Node at the tail of the list is %d\n", list->tail->data);
		if(check == 0){
			printf("Enter an integer greater than %d to append to list: ", list->tail->data);
			scanf( "%d", &num);

			while(num <= list->tail->data){
				printf("Enter an integer greater than %d to append to list: ", list->tail->data);
				scanf( "%d", &num);
			}
		}else{ // in case list has been reveresed
			printf("Enter an integer less than %d to append to list: ", list->tail->data);
			scanf( "%d", &num);

			while(num >= list->tail->data){
				printf("Enter an integer less than %d to append to list: ", list->tail->data);
				scanf( "%d", &num);
			}
		}
		add_to_tail(list, num);
	}else{
		printf("Error: invalid option\n");
	}
	displayAll(list->head);
}
// find the position of a certain node but not print it (makes the appendNthPosition function cleaner)
int find_nth(OrderedList *list, int num){
	Node* curr_ptr = list->head;
	for (int i = 0; i < num-1; i++){
		curr_ptr = curr_ptr->next;
	}
	return curr_ptr->data;
}
void appendNthPosition(OrderedList *list, int check){
	Node* before_ptr = list->head;
	int pos, before, after, new_val;
	printf("Append node at which position?: ");
	scanf(" %d", &pos);
	before = find_nth(list, pos-1);
	after = find_nth(list, pos);
	printf("Node at position %d: %d\n", pos-1, before); 
	printf("Node at position %d: %d\n", pos, after); 
	if (check == 0){
		while(1){
			printf("Enter an integer between %d and %d: ", before, after);
			scanf(" %d", &new_val);
			if ((new_val > before) && (new_val < after)) break;
		}
	}else{ // in case list has been reversed
		while(1){
			printf("Enter an integer between %d and %d: ", before, after);
			scanf(" %d", &new_val);
			if ((new_val < before) && (new_val > after)) break;
		}
	}
	Node* after_ptr = list->head;
	Node* insert_node = (Node*)malloc(sizeof(Node));

	insert_node->data = new_val;
	insert_node->prev = NULL;
	insert_node->next = NULL;
	// set pointers to the appropiate positions
	for (int i = 0; i < pos-2; i++){
		before_ptr = before_ptr->next;
	}
	for (int i = 0; i < pos-1; i++){
		after_ptr = after_ptr->next;
	}
	before_ptr->next = insert_node;
	insert_node->prev = before_ptr;
	after_ptr->prev = insert_node;
	insert_node->next = after_ptr;

	displayAll(list->head);
}
// deletes the head node of the list (makes the deleteHeadOrTail function cleaner)
void delete_head(OrderedList *list){
	Node* curr_ptr = list->head->next;
	Node* tmp = list->head;
	curr_ptr->prev = NULL;
	free(tmp);
	list->head = curr_ptr;
}
// deletes the head node of the list (makes the deleteHeadOrTail function cleaner)
void delete_tail(OrderedList *list){
	Node* curr_ptr = list->tail->prev;
	Node* tmp = list->tail;
	curr_ptr->next = NULL;
	free(tmp);
	list->tail = curr_ptr;
}
void deleteHeadOrTail(OrderedList *list){
	char del;
	printf("Delete from head or tail? (H/T): ");
	scanf(" %c", &del);
	if ( del == 'H'){
		delete_head(list);
	}else if (del == 'T'){
		delete_tail(list);
	}else{
		printf("Error, invalid input\n");
	}
	printf("\n");
	displayAll(list->head);
}
void deleteNthNode(OrderedList *list){
	int num;
	printf("Delete node at which position?: ");
	scanf(" %d", &num);

	Node* curr_ptr = list->head->next;
	// get to the desired node
	for (int i = 1; i < num-1; i++){
		curr_ptr = curr_ptr->next;
	}

	Node* before = curr_ptr->prev;
	Node* after = curr_ptr->next;
	before->next = after;
	after->prev = before;
	free(curr_ptr);

	displayAll(list->head);
}
void find(OrderedList * list){
	int num;
	printf("Enter an integer to find in the list: ");
	scanf(" %d", &num);

	Node* curr_ptr = list->head->next;
	int count = 1;
	while(1){
		if (curr_ptr->data == num) break;
		curr_ptr = curr_ptr->next;
		count++;
		if (curr_ptr->next == NULL){ // in case user input is not in the list
			printf("Error: %d is not in the list\n", num);
			return;
		}
	}
	count++;
	printf("\n%d found at position %d in the list.\n", num, count);
	printf("Previous node of %d is %d.\n", num, curr_ptr->prev->data);
	printf("Next node of %d is %d.\n", num, curr_ptr->next->data);

	displayAll(list->head);
}
void getNumberOfnodes(OrderedList *list){
	int count = 0;
	Node* curr_ptr = list->head;
	while(curr_ptr->next != NULL){
		curr_ptr = curr_ptr->next;
		count++; // counts how many nodes there are
	}
	count++;
	printf("Number of nodes in the list: %d\n", count);
	displayAll(list->head);
}
void displayEven(OrderedList *list){
	Node* curr_ptr = list->head;
	printf("Displaying even numbered nodes:\n");
	int i = 1;
	while(curr_ptr != NULL){
		if(i % 2 == 0){ // checks if the position is even
			printf("%d ", curr_ptr->data);
		}
		curr_ptr = curr_ptr->next;
		i++;
	}
	displayAll(list->head);
}
void displayOdd(OrderedList *list){
	Node* curr_ptr = list->head;
	printf("Displaying odd numbered nodes:\n");
	int i = 1;
	while(curr_ptr != NULL){
		if(i % 2 != 0){ // checks if the position is odd
			printf("%d ", curr_ptr->data);
		}
		curr_ptr = curr_ptr->next;
		i++;
	}
	displayAll(list->head);
}
// reverses the list
void reverseList(OrderedList *list){
	Node* curr_ptr = list->head;
	Node* tmp;
	while(curr_ptr != NULL){
		// replace the prev and next of the current pointer
		tmp = curr_ptr->next;
		curr_ptr->next = curr_ptr->prev;
		curr_ptr->prev = tmp;
		// move curr_ptr
		curr_ptr = tmp;
	}
	// replace the head and tail pointers
	tmp = list->head;
	list->head = list->tail;
	list->tail = tmp;
	printf("\nList Reversed");

	displayAll(list->head);
}
void destructor(Node* curr_ptr){
	Node *tmp;
	while(curr_ptr != NULL) {
		tmp = curr_ptr;
		curr_ptr = curr_ptr->next;
		free(tmp);
	}
}

int main(){
	OrderedList *list = malloc (sizeof(OrderedList));

	list->head = NULL;
  	list->tail = NULL;

  	int numValues, value;
 	FILE *fp = fopen("input.txt", "r");
 	 if (fp == NULL) {
    	printf("Couldn't open file...");
    		return 0;
  	}

  	fscanf (fp, "%d", &numValues);

  	for (int i = 0; i < numValues; i++) {
    		fscanf(fp, "%d", &value);
		insert_node(list, value);
  	}
	printf("Nodes entered into a doubly linked list.\nThis is a list of operations on the doubly linked list.\n\n1. Display all nodes\n2. Display nth node\n3. Append a new node - Head or Tail? (H/T)\n4. Append a new node in the Nth position\n5. Delete a node - Head or Tail? (H/T)\n6. Delete Nth node\n7. Find a node\n8. Get number of nodes\n9. Dispay even numbered nodes\n10. Display odd numbered nodes\n11. Reverse the list\n\n\n");

	int choice, check = 0;
	char c = 'c';
	while(1){
		if (c == 'N') break;
		printf("Enter your option: ");
		scanf(" %d", &choice);
		if (choice == 1){
			displayAll(list->head);
		}else if (choice == 2){
			displayNth(list);
		}else if (choice == 3){
			numValues++;
			appendHeadOrTail(list, check);
		}else if (choice == 4){
			appendNthPosition(list, check);
		}else if (choice == 5){
			numValues--;
			deleteHeadOrTail(list);
		}else if (choice == 6){
			deleteNthNode(list);
		}else if (choice == 7){
			find(list);
		}else if (choice == 8){
			getNumberOfnodes(list);
		}else if (choice == 9){
			displayEven(list);
		}else if (choice == 10){
			displayOdd(list);
		}else if (choice == 11){
			reverseList(list);
			// keep track of whether or not list has been reversed
			if (check == 0){
				check = 1; // list has been reversed (numbers arranged from biggest to smallest)
			}else{
				check = 0; // list has been reset (number arranged from smallest to biggest)
			}
		}else{
			printf("The choice you entered is invalid\n");
		}
		printf("\nContinue? (Y/N): ");
		scanf(" %c", &c);
		if (c == 'N'){
			break;
		}else{
			while (c != 'Y'){
				printf("Continue? (Y/N); ");
				scanf(" %c", &c);
				if (c == 'N') break;
			}
		}

	}
	destructor(list->head);
	free (list);

	return 0;
}
