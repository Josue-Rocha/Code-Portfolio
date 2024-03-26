#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("hello world\n");
	usleep(750000);
	system("clear");
	printf("bye world\n");
	return 0;
}
