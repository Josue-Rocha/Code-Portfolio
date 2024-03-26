#include<stdio.h>
#include<string.h>

int main()
{
	char word1[30] = "Virginia";
	char word2[15] = "Virginia";
	if (strcmp(word1, word2) == 0){
		printf("yay\n");
	}else{
		printf(":(\n");
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		if (i == 7){
			break;
		}else{
			printf("%d\n", i);
		}
	}
	return 0;
}
