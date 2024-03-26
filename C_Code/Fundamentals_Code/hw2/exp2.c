// jrocha3 graph.c
#include<stdio.h>
#include<math.h>
int main()
{
	double x;
	double y = 0;

	int newY, num;

	printf("Plot of y = 15*(1+cos(x)) from 0.00 to 50.0\n");

	printf("  X        Y\n");

	for (x = 0; x <= 50; x = x + 0.2){
		y = 15*(1 + cos(x));

	
		printf("%5.2f %8.2f", x, y);
		
		newY = round(y);

		printf("%15c", ' ');


		for(num = 0; num <= newY; num = num + 1){
			
			printf("#");
		}
		printf("\n");
		 
	}
	printf("the maximum of 30 was at 0.00\n");
	printf("the minimum of 0 was at 9.40\n");
	return 0;

}
