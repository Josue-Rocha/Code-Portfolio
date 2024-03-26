#include<stdio.h>
#include<math.h>

//int get_quadrant(double, double);
//double get_radius(double, double);
//double get_angle(double, double);
//void show_info(int, double, double);

int main()
{
	double  x,y;

	printf("Enter the x and y coordinates of a point in a Cartesian plane: \n");
	scanf("%lf %lf", &x, &y);

	printf("%lf %lf\n", x, y);



	if (x > 0 && y > 0){
		printf("the point is in the first quadrant\n");
	}else if (x < 0 && y > 0){
		printf("the point is in the second quadrant\n");
	}else if (x < 0 && y < 0){
		printf("the point is in the third quadrant\n");
	}else if (x > 0 && y < 0){
		printf("the point is in fourth quadrant\n");
	}else{
		printf("the point is at the origin\n");
	}
	return 0;
}	
