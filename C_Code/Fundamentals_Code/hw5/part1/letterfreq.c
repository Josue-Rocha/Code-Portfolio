#include<stdio.h>
#include<ctype.h>
#include<string.h>
// jrocha3
// letterfreq.c

// declare functions
void display_intro(char[], int, int);
void display_letters_count(int [], int);
void display_percent(int [], int, int);

#define MAX 26 // for the 26 letters in the alphabet
int main()
{
	// declare the necessary ints, floats, and file pointer
	FILE *fp;
	char infile[30];
	char ch;
	int char_count = 0;
	int letter_count = 0;
	int letters[MAX];


	printf("enter a file name: ");
	scanf("%s", infile);

	fp = fopen(infile, "r");
	if (!fp){ // check to see if file exists in the directory
		printf("file %s not found\n", infile);
		return 1;
	}

	for (int i = 0; i < MAX; i++)
	{
		letters[i] = 0; // initialize the arry to 0
	}

	while(1){
		ch = fgetc(fp); // ch equals each character in the text
		if (ch == EOF) break; // break the loop if ch reaches the end of the file

		char_count++; // tally up total number of characters

		if (isalpha(ch)) // check to see if ch is a letter
		{
			letter_count++; // tally up total number of letters
			
			letters[tolower(ch)-'a'] = letters[tolower(ch)-'a']+1; //convert ch to lowercase, subtract 'a' (to make the value match up with the according index of the letter) and increment the value of the index at that point
		}

	}

	printf("\n"); // print new line

	// call the functions
	display_intro(infile, char_count, letter_count);

	display_letters_count(letters, MAX);

	printf("\n");

	display_percent(letters, MAX, letter_count);


	return 0;
}
// define the functions
void display_intro(char infile[], int char_count, int letter_count)
{
	// print the name of the file being read, and the total number of characters and letters
	printf("General summary for %s:\n", infile);
	printf(" there were %d total characters\n", char_count);
	printf(" there were %d letters\n", letter_count);
	printf("\n");
}

void display_letters_count(int letters[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		if (i%6 == 0 && i != 0) printf("\n"); // print new line for every 5 characters
		char c = i + 97; // make the character c the corresponding letter for the index (add 97 because the ascii value for 'a' is 97)
		printf("%c: %6d ", c, letters[i]); // print results
	}
	printf("\n");

}

void display_percent(int letters[], int sz, int Max)
{
	for (int i = 0; i < sz; i++)
		{
			float num = ((float)letters[i]/(float)Max)*100; // calculate the percentage
			if (i%6 == 0 && i != 0) printf("\n");
			char c = i + 97; // same idea with the previous function
			char perc = 37; // ascii value for '%' because the program was being weird
			printf("%c: %5.1f%c  ", c, num, perc); // print results
		}
		printf("\n");
}
