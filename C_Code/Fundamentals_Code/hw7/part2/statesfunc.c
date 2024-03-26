//statesfunc.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"statesfunc.h"
int readstates(FILE *fp, State arr[])// read the file and count how many states are in it
{
	int count = 0;
	char line[60];
	while(1) {
		fgets(line, 60, fp);
		if(feof(fp)) break;// break the loop if the end of the file is reached
		strcpy(arr[count].abv, strtok(line, ","));// collect the state abbreviation
		strcpy(arr[count].statename, strtok(NULL, ","));// collect the state name
		strcpy(arr[count].capital, strtok(NULL, ","));// collect the state's capital
		arr[count].year = atoi(strtok(NULL, "\n"));// collect the year the state joined the union

		count++;// increment for each state
	}
	return count;// return the total number of states in the file
}

void display_options()// print the menu of options and ask the user for their choice
{
	printf("Choose an option: \n");
	printf("Option 1: Display All the Information\nOption 2: See all of a State's Information\nOption 3: See a specific state's Capital\nOption 4: See when a specific state joined the Union\nOption 5: See which states joined the Union for a given year\nOption 6: Quit\n");
}

void display_everything(State arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("The state %s is abbreviated by %s, its Capital is %s and it joined the union in %d\n", arr[i].statename, arr[i].abv, arr[i].capital, arr[i].year);// print everything in the struct for every state in the file
	}
	printf("\n");
}

void display_state(State arr[], char choice[], int sz)
{
	int index;
	for (int i = 0; i < sz; i++)
	{
		if (strcmp(choice, arr[i].abv) == 0){// in case the user entered an abbreviation
			index = i;
			break;
		}else if(strcmp(choice, arr[i].statename) == 0){ // in case the user entered the state name
			index = i;
			break;
		}else{// incase the user enters something that doesn't match anything in the file
			index = sz + 1; // sz + 1 because it is guaranteed that there won't be a defined index at that point and we need the value index to equal something to check it later
		}
	}//print the appropiate message
	if (index == sz + 1){
		printf("The information does not match anything in the data, please try again\n");
	}else{
		printf("The state of %s is abbreviated by %s, its Capital is %s and it joined the union in %d\n", arr[index].statename, arr[index].abv, arr[index].capital, arr[index].year);
	}
	printf("\n");
}

void display_capital(State arr[], char choice[], int sz)
{
	int index;
	for (int i = 0; i < sz; i++)// same concept as the display_state function
	{
		if (strcmp(choice, arr[i].abv) == 0){
			index = i;
			break;
		}else if (strcmp(choice, arr[i].statename) == 0){
			index = i;
			break;
		}else{
			index = sz + 1;
		}
	}
	if (index == sz + 1){
		printf("The information you entered does not match anything in the data, please try again\n");
	}else{
		printf("%s's Capital is %s\n", arr[index].statename, arr[index].capital);
	}
	printf("\n");
}

void display_year(State arr[], char choice[], int sz)
{
	int index;
	for (int i = 0; i < sz; i++)//  same concept as the display_state function
	{
		if (strcmp(choice, arr[i].abv) == 0){
			index = i;
			break;
		}else if (strcmp(choice, arr[i].statename) == 0){
			index = i;
			break;
		}else{
			index = sz + 1;
		}
	}
	if (index == sz + 1){
		printf("The information you entered does not match anything in the data, please try again\n");
	}else{
		printf("%s joined the Union in %d\n", arr[index].statename, arr[index].year);
	}
	printf("\n");
}

void display_all_years(State arr[], int year, int sz)
{
	int check;
	for (int i = 0; i < sz; i++)// check to see if any states joined the union that year
	{
		if (arr[i].year == year){
			check = 1;
			break;
		}else{
			check = 0;
		}
	}
	if (check == 1)
	{
		printf("The states that joined the Union is %d are: ", year);
		for (int i = 0; i < sz; i++)
		{
			if (arr[i].year == year){
				printf("%s, ", arr[i].statename);// print the state's name if it joined in the given year
			}
		}
	}else{// print an according message incase no states joined the union that year
		printf("No states joined the Union in %d\n", year);
	}
	printf("\n");
}
