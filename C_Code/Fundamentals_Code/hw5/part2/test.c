#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	char infile[20];
	char sayings[50][256];
	char single_saying[256];
	int count = 0;
	char find_string[256];
	char str1[] = "hello there, how are you?";
	char str2[] = "there";
	//char * ch;

	printf("enter name: \n");
	scanf("%s", infile);

	fp = fopen(infile, "r");
	if (!fp)
	{
		printf("file not found\n");
		return 1;
	}

	while (1)
	{
		fgets(single_saying, 256, fp);
		if(feof(fp)) break;
		strcpy(sayings[count], single_saying);
		count++;
	}

	char test[256] = "goofy";

	printf("enter string\n");
	//getchar();
	//fgets(find_string, 256, stdin);

	scanf("%s", find_string);

	/*char* ch;
	ch = strstr(sayings[0], find_string);
	if (ch){
		printf("found it\n");
	}else{
		printf(":(\n");
	}*/

	for (int i = 0; i < count; i++)
	{
		char * ch;
		ch = strstr(sayings[i], find_string);
		if (ch){
			printf("%s", sayings[i]);
		}else{
			printf("error\n");
		}
	}


	/*char *ch;
	ch = strstr(str1, str2);
	if (ch){
		printf("%s\n", str1);
	}else{
		printf("doesn't work :(\n");
	}*/
	return 0;
}
