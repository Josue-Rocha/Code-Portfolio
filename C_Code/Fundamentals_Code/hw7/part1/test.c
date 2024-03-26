#include<stdio.h>

int main()
{
	char a = 'x';
	char b = 'y';
	printf("%3c   |%3c\n", a, b);
	//printf(" %c  | %c\n", a, b);
	for (int i = 0; i < 15; i++)
	{
		if (i == 6){
			printf("+");
		}else{
			printf("-");
		}
	}
	printf("\n");
	float x = 3;
	float y = 5;
	printf("%5g |%7g\n", x, y);
	return 0;
}


