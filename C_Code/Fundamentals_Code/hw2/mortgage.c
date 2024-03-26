// jrocha3 mortgage.c
#include<stdio.h>

int main(){

	float balance, percInt, princ, interestPay, interest, initialInterest, total, initialRate, initialPrinc, monthly, initialMonthly, years, finalMonths;

	int  monthCount = 0;

	printf("Enter the principal (initial amount): ");
	scanf("%f", &princ);

	printf("Enter the monthly payment: ");
	scanf("%f", &monthly);

	printf("Enter the interest rate: ");
	scanf("%f", &interest);

	
	initialMonthly = monthly;	


	while(interest < 0){
		printf("error: enter a valid interest rate\n");
		scanf("%f", &interest);
		}
	
	percInt = interest/(100*12);


	initialInterest = princ * percInt;

	if(monthly <= initialInterest){
		printf("error: your monthly payemnt is too low\n");
	}else{
		printf("Month   Payment   Interest      Balance \n");
		while(princ > 0){
			if(princ > monthly){
				interestPay = princ * percInt;
				princ  = (princ + interestPay) - monthly;
				monthCount++;
				printf("%3.2d     $%6.2f    $%6.2f    $%8.2f\n", monthCount, monthly, interestPay, princ);
			}else{
				monthly = princ + interestPay;
				interestPay = princ * percInt;
				princ = 0;
				monthCount++;
				printf("%3.2d     $%6.2f    $%6.2f    $%8.2f\n", monthCount, monthly, interestPay, princ);
				// calculating the total
				total = ((monthCount - 1) *initialMonthly) + monthly;
				years = monthCount/12;
				finalMonths = monthCount%12;
				printf("you paid a total of $%.2f over %g years and %g months\n", total, years, finalMonths);
			}
		}
	}

		
	return  0;

}

