/* Title: struct-array.c
 * Abstract: Store student information into an array of structs and calculate average quiz scores
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 1 hour
 * Date: 02/07/2023
 */

#include <stdio.h>
#include<stdlib.h>


typedef struct student{
	char name[20];
	int id;
	float grade1;
	float grade2;
	float grade3;
	float grade4;
	float grade5;
	float avg;
} student;

void calc_avg(student arr[], int size)
{
	for (int i = 0; i < size; i++){
		arr[i].avg = (arr[i].grade1 + arr[i].grade2 + arr[i].grade3 + arr[i].grade4 + arr[i].grade5)/5;
	}
}

int main(void){
	char infile[20];
	int num;
	int count = 0;

	printf("Enter a file name: ");
	scanf("%s", infile);

	FILE* fp = fopen(infile, "r");

	if (fp == NULL){
		printf("File does not exist!\n");
		return 1;
	}
	student arr[30];
	fscanf(fp, "%d", &num);
	while(!feof(fp)){
		fscanf(fp, "%s %d %f %f %f %f %f", arr[count].name, &arr[count].id, &arr[count].grade1, &arr[count].grade2, &arr[count].grade3, &arr[count].grade4, &arr[count].grade5);
		count++;
	}
	calc_avg(arr, num);
	printf("\n-------------------------------------------\n");
	printf("Course Report: Quiz Average");
	printf("\n-------------------------------------------\n");

	for (int i = 0; i < num; i++){
		printf("%s (%d) : %g\n", arr[i].name, arr[i].id, arr[i].avg);
	}

	printf("\n-------------------------------------------\n");

	fclose(fp);

	return 0;
}

