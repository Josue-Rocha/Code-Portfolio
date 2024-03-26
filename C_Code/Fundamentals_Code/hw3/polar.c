//jrocha3
//polar.c
#include<stdio.h>
#include<math.h>

int get_quadrant(double, double);
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);

int main()
{
	double x,y;
	double radius, angle;
	int quad; 

	printf("Enter the x and y coordinates of a point in a Cartesian plane: \n");
	scanf("%lf %lf", &x, &y);
	printf("(%g, %g)\n", x, y);

	quad = get_quadrant(x, y);


	radius = get_radius(x, y);

	angle = get_angle(x, y);
	
	show_info(quad, radius, angle);



	return 0;
}

int get_quadrant(double x, double y)
 {
	int num;
	if (x > 0 && y > 0){
		num = 1;
	}else if (x < 0 && y > 0){
		num = 2;
	}else if (x < 0 && y < 0){
		num = 3;
	}else if (x > 0 && y < 0){
		num  = 4;
	}else{
		num = 0;
	}

	return num;
	
}

double get_radius(double x, double y)
{
	float radius, abs_x, abs_y;
	abs_x = fabs(x);
	abs_y = fabs(y);

	radius = sqrt((abs_x * abs_x) + (abs_y * abs_y));


	return(radius); 
	
}

double get_angle(double x, double y)
{
	double rad, deg;
	rad = atan2(y, x);


	deg = (rad/M_PI) * 180;
	return deg;
}


void show_info(int quad, double radius, double angle)
{
	if (quad == 1){
		printf("The point is in the first quadrant\n");
	}else if (quad == 2){
		printf("The point is in the second quadrant\n");
	}else if (quad == 3){
		printf("The point is in the third quadrant\n");
	}else if (quad ==4){
		printf("The point is in the fourth quadrant\n");
	}else{
		printf("The point is not in a quadrant\n");
	}

	printf("The radius of the point is: %.2lf\n", radius);

	printf("The angle of the point is: %.2lf\n", angle);

}
