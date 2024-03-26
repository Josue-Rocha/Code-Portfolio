#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"wordfunc.h"
//workfunc.c
const int MAX;

void init(char sol_board[][MAX], char puz_board[][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			sol_board[i][j] = '.';
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			puz_board[i][j] = '#';
	}
}

void display_board(char arr[][MAX])
{
	int i, j, m;
	printf("+");
	for (j = 0; j < MAX; j ++) printf("-");
	printf("+");
	printf("\n");

	for (i = 0; i < MAX; i++)
	{
		printf("|");
		for (j = 0; j < MAX; j++) printf("%c", arr[i][j]);
		printf("|");
		printf("\n");
	}
	printf("+");
	for (m = 0; m < MAX; m++) printf("-");
	printf("+");
	printf("\n");
}

void lower_to_upper(char word[], int sz)
{
	for (int i = 0; i < sz; i++)
		word[i] = toupper(word[i]);
}

int check_word(char word[])
{
	int word_length = strlen(word);
	if ((word_length > 16) || (word_length < 2))
	{
		printf("the word you entered is not the correct length\n");
		return 0;
	}
	for (int i = 0; i < word_length; i++)
	{
		if(isalpha(word[i]) == 0){
			printf("the word must contain only letters\n");
			return 0;
		}
	}
}

void sort_list(Words arr[], int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		int temp_len;
		char temp_str[16];
		if (arr[i+1].length > arr[i].length){
			temp_len = arr[i].length;
			strcpy(temp_str, arr[i].word);
			strcpy(arr[i].word, arr[i+1].word);
			arr[i].length = arr[i+1].length;
			arr[i+1].length = temp_len;
			strcpy(arr[i+1].word, temp_str);

		}
	}
}
void place_longest_word(char sol_board[][MAX], char puz_board[][MAX], Words arr[])
{
	int index = ((15 - arr[0].length)/2)+1;
	arr[0].index = index;
	for (int i = 0; i < arr[0].length; i++)
	 {
		 puz_board[7][index] = ' ';
		 sol_board[7][index] = arr[0].word[i];
		 index++;
	 }
	 arr[0].direction = 'a';
	 arr[0].constant = 7;
	 arr[0].check = 1;
}

int compare(Words arr[], int check, int index)
{
	int i = 0;
	while (i < arr[check].length)
	{
		for (int j = 0; j < arr[index].length; j++)
		{
			if (arr[check].word[i] == arr[index].word[j])
			{
				if (arr[check].direction == 'a')
				{
					arr[index].direction = 'd';
					arr[index].constant = arr[check].index + i;
					arr[index].index = (arr[check].constant);
					arr[index].common = j;
					if (check == 0) arr[check].common = i;
				}else if(arr[check].direction == 'd'){
					arr[index].direction = 'a';
					arr[index].constant = arr[check].index + i;
					arr[index].index = (arr[check].constant);
					arr[index].common = j;
					if (check == 0) arr[check].common = i;
				}
				return 1;
			}
		}
		i++;
	}
	return 0;
}

int place_new_word(Words arr[], int index, char sol_board[][MAX], char puz_board[][MAX])
{
	for (int i = index - 1; i >= 0; i--)
	{
		int capt = i;
		int val = compare(arr, i, index);
		if (val == 0)
		{
			return 0;
		}else{
			for (int j = 0; j < index -1; j++)
			{
				if ((arr[index].direction == arr[j].direction) && (arr[index].constant == arr[j].constant - 1)){
					return 0;
				}else if ((arr[index].direction == arr[j].direction) && (arr[index].constant == arr[j].constant - 1)){
					return 0;
				}else if (arr[index].index == arr[j].constant){
					return 0;
				}else if (arr[index].constant == arr[j].constant){
					return 0;
				}else if ( arr[index].constant == arr[j].constant + 1) {
					return 0;
				}else if ( arr[index].constant == arr[j].constant - 1) {
					return 0;
				}
			}
			arr[index].check = 1;
			int i = arr[index].common;
			int n = arr[index].index;
			int c = arr[index].constant;
			int length = arr[index].length;
			if (arr[index].direction == 'a'){
				for (i; i < length; i++)
				{
					sol_board[c][n] = arr[index].word[i];
					puz_board[c][n] = ' ';
					n++;
				}
				i = arr[index].common;
				n = arr[index].index;
				for (i; i >= 0; i--)
				{
					sol_board[c][n] = arr[index].word[i];
					puz_board[c][n] = ' ';
					n--;
				}
			}else if (arr[index].direction == 'd'){
				for (i; i < length; i++)
				{
					sol_board[n][c] = arr[index].word[i];
					puz_board[n][c] = ' ';
					n++;
				}
				i = arr[index].common;
				n = arr[index].index;
				for (i; i >= 0; i--)
				{
					sol_board[n][c] = arr[index].word[i];
					puz_board[n][c] = ' ';
					n--;
				}
			}
			arr[index].index = arr[capt].constant - arr[index].common;
			return 1;
		}
	}
}

void place_all_words(Words arr[], int count, char sol_board[][MAX], char puz_board[][MAX])
{
	int index = 1;
	while (index < count)
	{
		int check = place_new_word(arr, index, sol_board, puz_board);
		if (check == 0) printf ("%s does not work with the given rules\n", arr[index].word);
		index++;
	}
}

void display_clues(Words arr[], int count)
{
	printf("\nClues: \n");
	for (int i = 0; i < count; i++)
	{
		if (arr[i].check == 1){
			printf("%d, %d  ", arr[i].index, arr[i].length);
			if (arr[i].direction == 'd'){
				printf("Down   ");
			}else{
				printf("Across ");
			}
			int low = 0;
			int high = arr[i].length -1;
			while (low <= high){
				printf("%c", arr[i].word[low]);
				if (low != high) printf("%c", arr[i].word[high]);
				++low;
				--high;
			}
			printf("\n");
		}
	}
}
void file_display_board(char arr[][MAX], FILE *file)
{
	int i, j, m;
	fputs("+", file);
	for (j = 0; j < MAX; j ++) fputs("-", file);
	fputs("+", file);
	fputs("\n", file);

	for (i = 0; i < MAX; i++)
	{
		fputs("|", file);
		for (j = 0; j < MAX; j++) printf("%c", arr[i][j]);
		fputs("|", file);
		fputs("\n", file);
	}
	fputs("+", file);
	for (m = 0; m < MAX; m++) fputs("-", file);
	fputs("+", file);
	fputs("\n", file);
}

/*void file_display_clues(Words arr[], int count, FILE *file)
{
	fputs("\nClues: \n", file);
	for (int i = 0; i < count; i++)
	{
		if (arr[i].check == 1){
			fputs("%d, %d  ", arr[i].index, arr[i].length, file);
			if (arr[i].direction == 'd'){
				fputs("Down   ", file);
			}else{
				fputs("Across ", file);
			}
			int low = 0;
			int high = arr[i].length -1;
			while (low <= high){
				fputc(arr[i].word[low], file);
				if (low != high) fputc(arr[i].word[high], file);
				++low;
				--high;
			}
			fputs("\n", file);
		}
	}
}*/

