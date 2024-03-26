#include <stdio.h>
#include <math.h>
// jrocha3
// grades.c

// declare functions
float get_avg(int [], int);
float get_stan_div(int [], int, float);
int main()
{
  int grades[] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79 };

      int size = sizeof(grades)/sizeof(int); // get the size of the array

      float avg = get_avg(grades, size); // call the function that gets average grade
      printf("The average grade is: %.2f\n", avg);

      float stan_div = get_stan_div(grades, size, avg); // call the function that gets the standard deviation
      printf("The standard deviation is: %.2f\n", stan_div);
  // rest of program goes here ...
  
  return 0;
}

// define the functions
float get_avg(int grad[], int sz)
{
	// define local variables
	float count = 0;
	float avg;
	for (int i = 0; i < sz; i++)
	{
		count = count + grad[i]; // get the summation of all of the grades
	}
	avg = count/sz; // calculate the average
	return avg;
}
float get_stan_div(int grad[], int sz, float avg)
{
	float count = 0;
	for (int i = 0; i <sz; i++)
	{
		count = count + pow((grad[i] - avg), 2); // calculate part of the standard deviation using the formula
	}
	float stan_div = sqrt(count/sz); // calculate the rest of the standard deviationn using the formula
	return stan_div;
}
