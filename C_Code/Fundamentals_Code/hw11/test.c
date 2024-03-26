#include<stdio.h>

int main()
{
	char temp[20];
	char *line = temp;
	int num = 5;
	sprintf(temp, "num is %d", num);
	//*line = sprintf(line,"num is %d", num);
	printf("%s\n", line);
	return 0;
}
