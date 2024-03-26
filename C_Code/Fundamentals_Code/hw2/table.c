// jrocha3 table.c
#include<stdio.h>

int main(){
	int a, b, x, y, z;
	printf("enter a value for the x axis: \n");
	scanf("%d", &x);

	printf("enter the a value for the  y axis: ");
	scanf("%d", &y);


	printf("%5c", ' ');
	for(a=1; a<=x; a=a+1){
		
		printf("%6d", a);
	}

	printf("\n");
	
	printf("      ");
	for(z=1; z<=x; z++){
		printf("______");
	}

	printf("\n");

	for(a=1; a<=y; a=a+1){
		printf("%5d|", a);
		for(b=1; b<=x; b=b+1){
		
			printf("%5d ", a*b);
		}
		printf("\n");
	}

	return 0;
}
