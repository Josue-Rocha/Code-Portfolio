#include<stdio.h>
#include<math.h>

int main() {
	float a;
	float b;
	float c;
	float posx;
	float negx;

	printf("this is a program which will run the quadratic formula for you, you will have to enter the a,b and c values of your equation make sure that there will be no imaginary numbers (i.e that 4ac is smaller than b^2)\n");

	printf("enter a value for a: \n");
	scanf("%g", &a);

	printf("enter a value for b \n");
	scanf("%g", &b);

	printf("enter a value for c: \n");
	scanf("%g", &c);

	posx = (-b + sqrt((b*b) - (4*a*c)))/2*a;

	negx = (-b - sqrt((b*b) - (4*a*c)))/2*a;

	printf("the value of one of the zeros is: %g\n", posx);
	printf("the value of one of the other zero is: %g\n", negx);


	return 0;

}

