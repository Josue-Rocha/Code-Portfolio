// jrocha3
// quadratics.c
#include<stdio.h>
#include<math.h>

float get_disc(int, int, int);

int main()
{
	float a, b, c, disc;
	float x1, x2;
	printf("Enter the coefficients (a,b,c) of a quadratic function: \n");
	scanf("%f %f %f", &a, &b, &c);


	while (a != 0)
	{
		disc = get_disc(a, b, c);

		if (disc > 0){
			x1 = (-b + disc)/(2*a);
			x2 = (-b - disc)/(2*a);
			printf("the roots are: %g and %g\n", x1, x2);
		}else if (disc = 0) {
			x1 = -b/(2*a);
			printf("the single root of the function is: %f\n", x1);
		}else{
			printf("this equation has no real roots\n");
		}
		printf("Enter a new set of coefficients: \n");
		scanf("%f %f %f", &a, &b, &c);
	}
	return 0;
}

float get_disc(int a, int b, int c)
{
	float num;
	num = sqrt((b*b)-(4*a*c));
	return num;
}

