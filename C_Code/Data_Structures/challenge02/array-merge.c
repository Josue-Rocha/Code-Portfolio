/* Title: array-merge.c
 * Abstract: This program will read a file and create and append an array depending on the input
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 3 hours
 * Date: 02/07/2023
 */

#include<stdio.h>
#include<stdlib.h>

void initial(int *arr, int *new_arr, int len)
{
	if (len == 0){
		return;
	}else{
		for (int i = 0; i < len; i++){
			new_arr[i] = arr[i];
		}
	}
}
void combine(int *new, int *this, int this_sz, int total){
	if (total == 0){
		for (int i = 0; i < this_sz; i++){
			new[i] = this[i];
		}
	}else{
		int j = 0;
		for (int i = total; i < total + this_sz; i++){
			new[i] = this[j];
			j++;
		}
	}
}
void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void sort_arr( int *arr, int size)
{
	int temp;
	for (int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++){
			if (arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main(void){

	char infile[20];
	printf("Enter filename: ");
	scanf("%s", infile);

	FILE* fp = fopen(infile, "r");

	// incase the file does not exist
	if (fp == NULL){
		printf("File does not exist!\n");
		return 1;
	}
	// declare variables
	int count = 1;
	int total = 0;
	long unsigned int length = 10;

	int* arr = (int *)malloc(length * sizeof(int));

	while(1)
	{
		if (feof(fp)) {
			 break;
		}else{
			int size;
			long unsigned int this_len, new_len;
			fscanf(fp, "%d", &size);

			if (feof(fp)) break;

			this_len = (unsigned int) size; 
			new_len = (unsigned int)total + (unsigned int)size;
			printf("Array%d: ", count);

			int *this_arr = (int *)malloc(this_len * sizeof(int));
			int *new_arr = (int *)malloc(new_len * sizeof(int));

			initial(arr, new_arr, total);

			for (int i = 0; i < size; i++){
				fscanf(fp, "%d", &this_arr[i]);
				printf("%d ", this_arr[i]);
			}

			combine(new_arr, this_arr, size, total);
			free(arr);
			arr = new_arr;
			printf("\nArray%d size: %d\n", count, size);
			printf("\n");

			total += size;
			count++;
		}
	}
	sort_arr(arr, total);
	printf("Combined array: ");
	for (int i = 0; i < total; i++){
		printf("%d ", arr[i]);
	}
	printf("\nCombined array size: %d", total);

	fclose(fp);
	printf("\n");
	return 0;
}

