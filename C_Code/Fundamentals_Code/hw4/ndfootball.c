#include<stdio.h>
#include<stdbool.h>
// jrocha3
// ndfootball.c

// declare the arrays
void display_options();
void year_record(int [], int [], int);
void get_loss(int[], int, int);
void get_wins(int[], int, int);
void loss_years(int [], int [], int);
void win_years(int [], int[], int);


int main()
{
	int wins[] =
	{ 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
	6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
	8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
	3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
	8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
	8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
	9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
	11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
	12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
	5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
	8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 10, 11 };
	
	int losses[] =
	{ 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
	0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
	1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
	5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
	2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
	2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
	0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
	1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
	0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
	7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
	5, 5, 1, 4, 5, 3, 8, 3, 1, 2, 2, 2 };

	int size = sizeof(wins)/sizeof(int); // get the size of the arrays, they shouold
	int choice;
	while(true){
		display_options(); // inside the while loop so that it prints every time
		scanf("%d", &choice);

		if (choice == 6){
			printf("Goodbye!\n");
			break;// break the while loop if the user selects 6
		}else if (choice == 1){
			int year;
			printf("Enter the year: \n");
			scanf("%d", &year);
			year_record(wins, losses, year); // call the year_records function
		}else if (choice == 2){
			int num_loss;
			printf("Enter miminum number of losses\n");
			scanf("%d", &num_loss);
			get_loss(losses, num_loss, size); // call the get_loss function
		}else if (choice == 3){
			int num_wins;
			printf("Enter minimum number of wins\n");
			scanf("%d", &num_wins);
			get_wins(wins, num_wins, size); // call the get_wins functions
		}else if (choice == 4){
			loss_years(wins, losses, size); // call the loss_years functions
		}else if (choice == 5){
			win_years(wins, losses, size); // call the win_years functions
		}else{// in case they choose a number not between 1-6
			printf("You entered an invalid option, please try again\n");
		}
		printf("\n");
	}

	return 0;
}
// define the arrays
void display_options()
{
	printf("What would you like to see?\n");
	printf(" 1: display the record for a given year.\n 2: display years with at least \"n\" losses. \n 3: display years with at least \"n\" wins. \n 4: display years with a winning record. \n 5: display years with a losing record\n 6: exit\n");
}

void year_record(int wins[], int losses[], int year)
{
	int win, loss, year_index;
	year_index = year - 1900;// convert the year into the corresponding index
	win = wins[year_index];
	loss = losses[year_index];
	printf("Wins: %d, Losses: %d\n", win, loss);
}
void get_loss(int losses[], int num_loss, int size)
{
	printf("Years with at least %d losses: ", num_loss);
	for (int i = 0; i < size; i++)
	{
		if (losses[i] >= num_loss) // check to see if the loss count of a certain year is at least the number provded by the user
			printf("%d ", i + 1900); // print and adjust index so the year matches
	}
	printf("\n");
}
void get_wins(int wins[], int num_wins, int size)
{
	printf("Years with at least %d wins: ", num_wins);
	for (int i = 0; i < size; i++)
	{
		if (wins[i] >= num_wins) // same concept as get_loss just in reverse
			printf("%d ", i + 1900);
	}
	printf("\n");
}

void loss_years(int wins[], int losses[], int size)
{
	printf("The years ND Footbal had a losing record are: ");
	for (int i = 0; i < size; i++)
	{
		if (losses[i] > wins[i]) // go through both arrays and print the year anytime the number of losses is greater than the number of wins for a certain index (i.e. a certain year) 
			printf("%d ", i + 1900);
	}
	printf("\n");
}

void win_years(int wins[], int losses[], int size)
{
	printf("The years ND Football had a winning record are: ");
	for (int i = 0; i < size; i++)
	{
		if (wins[i] > losses[i]) // same concept as loss_years but in reverse
			printf("%d ", i + 1900);
	}
	printf("\n");
}
