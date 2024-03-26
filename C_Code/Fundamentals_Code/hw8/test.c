#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define _GNU_SOURCE
int main()
{
	/*char test[10];
	printf("enter a word\n");
	fgets(test, 10, stdin);
	printf("you entered %s\n", test);
	for (int i = 0; i < 10; i ++)
	{
		test[i] = toupper(test[i]);
	}
	printf("you entered %s\n", test);*/
	//char test[30];
	//int i = 0;
	/*while (i < 15)
	{
		printf("%c\n", test[i]);
		i++;
	}*/
	/*printf("enter word: ");
	fgets(test, 15, stdin);
	//scanf("%s", test);
	while(test[i] != '\0')
	{
		printf("%c\n", test[i]);
		i++;
	}
	int length = strlen(test);
	printf("strlen is: %d\n", length);
	printf("enter word: ");
	fgets(test, 30, stdin);
	char check[] = "check\n";
	if (strcmp(test, check) == 0){
		printf(":)\n");
	}else{
		printf(":(\n");
	}
	char c;
	printf("enter char: ");
	scanf("%c", &c);
	if (isalpha(c) == 0){
		printf(":)\n");
	}else{
		printf(":(\n");
	}*/
	char test[] = "Fighting";
	printf("%s\n", strfry(test));
	return 0;
}
