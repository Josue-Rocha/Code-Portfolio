/* Title: struct-search.c
 * Abstract: This program finds a customer's information from a bank data
 * Author: Josue Rocha
 * Email: jrocha3@nd.edu
 * Estimate: 1 hour
 * Date: 02/07/2023
 */

#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct bank{
	char name[20];
	int id;
	double balance;
} bank;

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

	bank arr[30];
	fscanf(fp, "%d", &num);

	while(!feof(fp)){
		fscanf(fp, "%s %d %lf", arr[count].name, &arr[count].id, &arr[count].balance);
		count++;
	}
	int choice = 0;
	char c;
	while(1){
		if(choice == 1) break;
		char input_name[30];
		printf("\n-------------------------------------------\n");
		printf("Record Finder  Enter a customer name: ");
		scanf("%s", input_name);
		printf("\n-------------------------------------------\n");
		int counter = 0;
		for (int i = 0; i < num; i++){
			int result = strcmp(arr[i].name, input_name);
			if (result == 0){
				printf("Name: %s\n", arr[i].name);
				printf("Account: %d\n", arr[i].id);
				printf("Balance: %lf\n", arr[i].balance);
				printf("\n");
			}else{
				counter++;
			}
		}
		if (counter == num) printf("Fail, %s doesn't exist\n", input_name);
		//char c;
		printf("Do you want to continue? (y/n) ");
		fscanf(stdin, "%c", &c);
		if (c == 'n'){
			choice = 1;
			break;
		}
	}


	fclose(fp);

	return 0;
}

