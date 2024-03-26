/* Title: array-rotation.c
 * Abstract: This program will rotate an array to the left or right depending on user input.
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 1 hour [put your best guess]
 * Date: 01/31/2023
 */

#include <stdio.h>
#include<stdlib.h>

void rotate_left(int *arr, int size)
{
	int temp = arr[0];
	for (int i = 0; i < size -1; i++)
	{
		arr[i] = arr[i+1];
	}
	arr[size-1] = temp;
}

void rotate_right(int *arr, int size)
{
	int temp = arr[size -1];
	for (int i = size-1; i >0; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[0] = temp;
}
void print_arr(int *arr, int len)
{
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void){
	FILE* fp = fopen("input.txt", "r");

	// incase the file does not exist
	if (fp == NULL){
		printf("File does not exist!\n");
		return 1;
	}

	//declare variables
	int rotations;
	long unsigned int size;
	char dir;

	// read first line of file
	fscanf(fp, "%lu %d %c", &size, &rotations, &dir);

	// create dynamic array based on the number of elements
	int* arr = (int *)malloc(size * sizeof(int));

	int count = 0;
	// read the numbers and place into the dynamic array
	while(1)
	{
		if (feof(fp)) break;
		fscanf(fp, "%d", &arr[count]);
		count++;
	}

	count = count -1; // correct the counter

	//rotate and print the array
	if (dir == 'L'){
		for (int i = 0; i < rotations; i++){
			rotate_left(arr, count);
		}
		print_arr(arr, count);
	}else if (dir == 'R'){
		for (int i = 0; i < rotations; i++){
			rotate_right(arr, count);
		}
		print_arr(arr, count);
	}else{
		printf("error: proper direction\n");
		return 1;
	}

	fclose(fp);
	free(arr);
	return 0;
}

