// jrocha3 graph.c
#include<stdio.h>
#include<math.h>
int main()
{
	float x;
	float y = 0;

	float maxX = 0;
	float maxY = 0;
	float minX = 0;
	float minY = 100;

	int newY, num;

	printf("Plot for  y = 15*(1+cos(x)) from 0.00 to 30.0\n");

	printf("   X        Y\n");

	for (x = 0; x <= 30; x = x + 0.2){
		y = 15*(1 + cos(x));

	
		printf("%5.2f %8.2f", x, y);
		
		newY = round(y);

		printf("%10c", ' ');



		for(num = 0; num <= newY; num = num + 1){
			
			printf("#");
		}
		printf("\n");

		if(y > maxY){
			maxY = y;
			maxX = x;
		}else if (y < minY){ 
			minY = y;
			minX = x;
		}
		 
	}
	printf("The maximum of %.2f was at %.2f\n", maxX, maxY);
	printf("The minimum of %.2f was at %.2f\n", minX, minY);

	return 0;

}
