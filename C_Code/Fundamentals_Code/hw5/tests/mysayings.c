#include<stdio.h>
#include<stdbool.h>
#include<string.h>
// jrocha3
// ndfootball.c

// declare the arrays
#define MAX 256
void display_options();
void display_current_sayings(char[][MAX], int);
void enter_new_saying(char [][MAX], char[MAX], int);
void display_given_word(char [][MAX], char[MAX], int);
void save_new_file(char[][MAX], int);


int main()
{
	int choice;
	char sayings[50][MAX];
	char single_saying[MAX];
	char new_saying[MAX];
	char find_string[MAX];
	FILE *fp;
	char infile[20];
	int count = 0;

	printf("etner a file name: ");
	scanf("%s", infile);

	fp = fopen(infile, "r");
	if (!fp)
	{
		printf("file %s not found\n", infile);
		return 1;
	}

	while(true)
	{
		fgets(single_saying, MAX, fp);
		if (feof(fp)) break;
		strcpy(sayings[count], single_saying);
		count++;
	}
	while(true){
		display_options(); // inside the while loop so that it prints every time
		scanf("%d", &choice);

		if (choice == 5){
			printf("Goodbye!\n");
			break;// break the while loop if the user selects 5
		}else if (choice == 1){
			display_current_sayings(sayings, count);
		}else if (choice == 2){
			printf("enter your new saying:\n");
			getchar();
			fgets(new_saying, MAX, stdin);
			enter_new_saying(sayings, new_saying, count);
			count++;
		}else if (choice == 3){
			printf("enter a string: \n");
			getchar();
			//fgets(find_string, MAX, stdin);
			scanf("%s", find_string);
			printf("\n");
			display_given_word(sayings, find_string, count);
		}else if (choice == 4){
			save_new_file(sayings, count);
		}else{// in case they choose a number not between 1-5
			printf("You entered an invalid option, please try again\n");
		}
	}
		printf("\n");
	

	return 0;
}
// define the arrays
void display_options()
{
	printf(" 1. display all saings currently in the database\n 2. enter a new saying into the database\n 3. list sayings that contain a given string entered by the user\n 4. save all the sayings in a new text file\n 5. quit the program\n");
	printf("\n");
}
void display_current_sayings(char sayings[][MAX], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%s\n", sayings[i]);
	}
}
void enter_new_saying(char sayings[][MAX], char new_saying[], int sz)
{
	strcpy(sayings[sz], new_saying);
}
void display_given_word(char sayings[][MAX], char find_string[], int sz)
{
	char * ch;
	for (int i = 0; i <= sz; i++)
	{
		ch = strstr(sayings[i], find_string);
		if (ch){
			printf("%s\n", sayings[i]);
		}

	}
}
void save_new_file(char sayings[][MAX], int sz)
{
	FILE *fp;
	fp = fopen("new_file.txt", "w");
	for (int i = 0; i < sz; i++)
	{
		fputs(sayings[i], fp);
	}

}
