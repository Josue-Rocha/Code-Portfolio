#include<stdio.h>
#include"pathfunc.h"
// path.c

int main()
{
	char infile[20];
	FILE *fp;
	
	printf("enter a file name: "); // prompt user for file name
	scanf ("%s", infile);
	
	fp = fopen(infile, "r"); // open the file
	if (!fp) // in case the file is not in the directory
	{
		printf("file %s not found\n", infile);
		return 1;
	}
	Point pt_arr[30]; // create an array of structs assuming there will be no more than 30 points
	int count;
	count = readvalues(fp, pt_arr); // reads the values putting them into pt_arr and returns the total number of points

	float total = get_total(pt_arr, count); // calculates the total distance traveled between points
	display_all(pt_arr, total, count); // displays everything
	return 0;
}
