#include<stdio.h>
// jrocha3
// prime.c
 
 int main()
 {
	 int arr[1000];

	 for (int i = 0; i < 1000; i++) // initialize the array to 1
	 {
		 arr[i] = 1;
		// printf("%d ", arr[i]);
	 }

	 for(int i = 2; i < 1000; i++) 
	 {
		 if (arr[i] == 1) // check too see if the array at i hasn't already been set to 0
		 {
			 int bound = 1000/i; // find the proper bound for specific value of i
			 for (int num = 2; num <= bound; num++) // inner for loop for all the multiples of i
			 {
				 int subscript = i * num; // go through all the multiples > 1000
				 arr[subscript] = 0; // change all the multiples to 0, this will will be how we know whether or not the number is prime
			 }
		 }
	 }
	//printf("%d\n", arr[80]);
	for (int j = 2; j < 1000; j++)
	{
		 if (arr[j] == 1){ // all non-prime numbers should have already been set to 0, so if the array at that number is 1, then it is prime
			 printf("%3d ", j); // print the prime numbers
		 }
	}

	 printf("\n");
	 return 0;
	 }
