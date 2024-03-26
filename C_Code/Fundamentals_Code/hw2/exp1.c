#include<stdio.h>
#include<math.h>

int main(){

	float balance, percInt, princ, interestPay, interest, initialInterest, total, initialRate, initialPrinc, monthly, initialMonthly, years, finalMonths;

	int  monthCount = 0;

	printf("Enter the principal (initial amount): ");
	scanf("%f", &princ);

	printf("Enter the monthly payment: ");
	scanf("%f", &monthly);

	printf("Enter the interest rate: ");
	scanf("%f", &interest);

	percInt = interest/(100*12);

	//printf("%f %f %d %f\n", princ, num, monthly, interest);

	printf("Month          Payment         Interest        Balance\n");
	
	initialMonthly = monthly;	

	while(interest < 0){
		printf("error: enter a valid interest rate\n");
		scanf("%lf", interest);}

	initialInterest = princ * percInt;

	if(monthly <= initialInterest){
		printf("error: your monthly payemnt is too low\n");
	}else{
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
			}
		}
	}

		
	total = ((monthCount - 1) * initialMonthly) + monthly;
	years = monthCount/12;
	finalMonths = monthCount%12;
	printf("you paid a total of $%.2f over %g years and %g  months\n", total, years, finalMonths);

	//printf("%f %f %d", initialPrinc, initialRate, monthCount);
	return  0;

}

