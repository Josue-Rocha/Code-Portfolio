#include<stdio.h>

int main()
{
	int i, j;
	char choice;
	char choice_str[6];
	char c[2];

	printf("enter the action and point: ");
	fgets(choice_str, 6, stdin);


	if (choice_str[0] == 'a'){
		sscanf(choice_str, "%s %d %d", c, &i, &j);
		printf("the number values (a) are: %d and %d\n", i, j);
	}else if (choice_str[0] == 'r'){
		sscanf(choice_str, "%s %d %d", c, &i, &j);
		printf("the number values of (r) are: %d and %d\n", i, j);
	}else{
		printf(":(\n");
	}
	return 0;
}
