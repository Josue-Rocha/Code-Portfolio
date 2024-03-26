#include<stdio.h>
#include<math.h>
#include"pathfunc.h"
//pathfunc.c
int readvalues(FILE *fp, Point arr[]) // read file and place the points into the corresponding locations in the struct array
{
	int count = 0;
	while(1){
		fscanf(fp, "%f %f", &arr[count].x, &arr[count].y);
		if(feof(fp)) break; // ends the loop if the end of the file is reached
		count++; // increments for each point
	}
	return count;
}

float get_distance(float x1, float y1, float x2, float y2) // calculates the distance between two points
{
	float distance;
	distance = sqrt(pow((x2-x1), 2)+pow((y2-y1), 2)); // distance formula
	return distance;
}
float get_total(Point arr[], int sz) // calculates total distance traveled for all the points
{
	float total = 0;
	for (int i = 0; i < sz-1; i++)
	{
		total = total + get_distance(arr[i].x, arr[i].y, arr[i+1].x, arr[i+1].y); // calls the get_distance function for each pair of points and adds that distance to the total
	}
	return total;
}
void display_all(Point arr[], float total, int sz) // display everying
{
	printf("There are %d points:\n\n", sz); // print the total number of points
	char x = 'x';
	char y = 'y';
	printf("%3c   |%3c\n", x, y); // top line of table
	for (int i = 0; i < 15; i++)// divider between top line and the actual data
	{
		if (i == 6){
			printf("+");
		}else{
			printf("-");
		}
	}
	printf("\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%5g |%7g\n", arr[i].x, arr[i].y); // prints each x and y coordinate
	}
	printf("\n");
	printf("The length of the path through them is %.2f\n", total); // print the total distance traveled
}
