#include<stdio.h>
#include"lifefunc.h"
//lifefunc.c

const int MAX;
const char DEAD = ' ';

void init(char arr[][MAX])
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			arr[i][j] = DEAD;
}

void display_the_array(char arr[][MAX])
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

int check_scene(char arr[][MAX], int i, int j)
{
	int live_count = 0;

	if(arr[i-1][j] == 'X') live_count++;
	if(arr[i+1][j] == 'X') live_count++;
	if(arr[i][j-1] == 'X') live_count++;
	if(arr[i][j+1] == 'X') live_count++;
	if(arr[i-1][j+1] == 'X') live_count++;
	if(arr[i+1][j+1] == 'X') live_count++;
	if(arr[i-1][j-1] == 'X') live_count++;
	if(arr[i+1][j-1] == 'X') live_count++; 

	if (arr[i][j] == DEAD && live_count == 3){ 
		return 0;
	}else if ((arr[i][j] == 'X') && (live_count != 2) && (live_count != 3)){
		return 1;
	}
	
}

void apply_rules(char arr[][MAX], char temp_arr[][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			int check = check_scene(arr, i, j);
			if (check == 0){
				temp_arr[i][j] = 'X';
				}else if (check == 1){
					temp_arr[i][j] = DEAD;
					}
		}
	}
}

void set_equal(char first_arr[][MAX], char second_arr[][MAX])
{
	for(int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			first_arr[i][j] = second_arr[i][j];
}
