#include<stdio.h>

#define MAX 40
int main()
{
	char arr[40][40];

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i == 0)
			{
				arr[i][j] = '_';
			}else if (i == MAX-1){
				arr[i][j] = '_';
			}else if (j == 0){
				arr[i][j] = '|';
			}else if (j == MAX -1){
				arr[i][j] = '|';
			}else{
				arr[i][j] = ' ';
			}
		}
	}
	for (int x = 0; x < MAX; x++)
	{
		for (int y = 0; y < MAX; y++)
		{
			printf("%c", arr[x][y]);
		}
		printf("\n");
	}
	return 0;
}
