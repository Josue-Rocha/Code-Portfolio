#include<stdio.h>

int main(){
	int numTouch;
	int numEP;
	int numFG;
	int numSafety;
	printf("enter the number of touchdowns\n");
	scanf("%d", &numTouch);

	printf("enter the number of extra points\n");
	scanf("%d", &numEP);

	printf("enter the number of field goals\n");
	scanf("%d", &numFG);

	printf("enter the number of safeties\n");
	scanf("%d", & numSafety);

	printf("the total points is: %d\n", ((numTouch *6)+(numEP)+(numFG*3)+(numSafety*2)));

	return 0;


}

