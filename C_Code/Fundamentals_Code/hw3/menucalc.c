// jrocha3
// menucalc.c
#include<stdio.h>
#include<stdbool.h>

float get_add(float, float);
float get_sub(float, float);
float get_mult(float, float);
float get_div(float, float);
void print();

int main()
{
	int choice;
	float value1, value2;

	while (true){
		printf("What would you like to do?\n");
		printf(" 1 for adddition\n 2 for subtraction\n 3 for multiplication \n 4 for division \n 5 to exit\n");
		printf("\n");
		printf("Enter your choice: \n");
		scanf("%d", &choice);

		if (choice == 5){
			printf("Goodbye!\n");
			break;
		}else if (choice == 1){
			print();
			scanf("%f" "%f", &value1, &value2);
			get_add(value1, value2);
		}else if (choice == 2){
			print();
			scanf("%f" "%f", &value1, &value2);
			get_sub(value1, value2);
		}else if (choice == 3){
			print();
			scanf("%f" "%f", &value1, &value2);
			get_mult(value1, value2);
		}else if (choice == 4){
			print();
			scanf("%f" "%f", &value1, &value2);
			if (value2 == 0){
				printf("You cannot divide by zero, please try again\n");
			}else{
			get_div(value1, value2);
			}
		}else{
			printf("The number you entered is not an option, please try again \n");
		}
		printf("\n");

	}
	return 0;
}

float get_add(float value1, float value2)
{
	float result;
	result = value1 + value2;
	printf("(%g) + (%g) = %g\n", value1, value2, result);
}

float get_sub(float value1, float value2)
{
	float result;
	result = value1 - value2;
	printf("(%g) - (%g) = %g\n", value1, value2, result);
}
float get_mult(float value1, float value2)
{
	float result;
	result = value1 * value2;
	printf("(%g) * (%g) = %g\n", value1, value2, result);
}
float get_div(float value1, float value2)
{
	float result;
	result = value1/value2;
	printf("(%g)/(%g) = %g\n", value1, value2, result);
}

void print()
{
	printf("Enter two numbers: \n");
}
