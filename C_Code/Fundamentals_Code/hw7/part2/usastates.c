#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"statesfunc.h"
//usastates.c
const int MAX = 100;
int main()
{
	char infile[20];
	FILE *fp;

	printf("Enter a file name: ");
	scanf("%s", infile);

	fp  = fopen(infile, "r");
	if (!fp)
	{
		printf("file %s not found\n", infile);
		return 1;
	}
	
	State st_arr[MAX]; // make an array of structs

	int count; // number of states in file
	count = readstates(fp, st_arr);
	//^^^ take in and read a file ^^^
	while(1)
	{
		int choice;
		display_options(); // right under the while loop so the menu prints every time
		scanf("%d", &choice); // picks up what the user wants to do
		if (choice == 6){
			printf("Goodbye!\n");
			break;// breaks the while loop if user inputs 6
		}else if (choice == 1){
			display_everything(st_arr, count); // displays all the data from the file in an organized way
		}else if (choice == 2){
			char state_choice[30];
			printf("Enter a state name or abbreviation: ");
			scanf("%s", state_choice); // collects the state name or abbreviation
			printf("\n");
			display_state(st_arr, state_choice, count);// displays all the information for a given state
		}else if (choice == 3){
			char state_choice[30];
			printf("Enter a state name or abbreviation: ");
			scanf("%s", state_choice); // collects the state name or abbreviation
			printf("\n");
			display_capital(st_arr, state_choice, count); // displays the capital for a given state
		}else if (choice == 4){
			char state_choice[30];
			printf("Enter a state name or abbreviation: "); // collects the state name or abbreviation
			scanf("%s", state_choice);
			printf("\n");
			display_year(st_arr, state_choice, count); // displays the year the state joined the union
		}else if (choice == 5){
			int year_choice;
			printf("Enter a year: ");
			scanf("%d", &year_choice); // collect the given year
			printf("\n");
			display_all_years(st_arr, year_choice, count); // displays which states joined the union that year
			printf("\n");
		}else{// in case user enters anoption that is not between 1 and 6
			printf("You entered an option that is not available, please try again\n");
		}
	}
	printf("\n");
	return 0;
}
