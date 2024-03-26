//playlife.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"lifefunc.h"
const int MAX = 40;

int main(int argc, char *argv[])
{
	char arr[MAX][MAX];
	char temp_arr[MAX][MAX];

	init(arr);
	display_the_array(arr);
	if (argc == 1){// interactive mode
		display_the_array(arr);
		while(1){
			char choice_str[10];
			int i, j;
			char c[2];
			printf("COMMAND: ");
			fgets(choice_str, 10, stdin);

			if (choice_str[0] == 'q'){
				break;
			}else if (choice_str[0] == 'a'){
				sscanf(choice_str, "%s %d %d", c, &i, &j);
				arr[i][j] = 'X';
				display_the_array(arr);
			}else if (choice_str[0] == 'r'){
				sscanf(choice_str, "%s %d %d", c, &i, &j);
				if (arr[i][j] == 'X'){
					arr[i][j] = ' ';
				}
				display_the_array(arr);
			}else if (choice_str[0] == 'n'){
				set_equal(temp_arr, arr);
				apply_rules(arr, temp_arr);
				set_equal(arr, temp_arr);
				display_the_array(arr);
			}else if (choice_str[0] == 'p'){
				while(1){
					set_equal(temp_arr, arr);
					apply_rules(arr, temp_arr);
					set_equal(arr, temp_arr);
					system("clear");
					display_the_array(arr);
					usleep(75000);
					system("clear");
				}
			}else{
				printf("error\n");
			}
		}
	}else if (argc == 2){// bash mode

		FILE *fp;
		fp = fopen(argv[1], "r");
		if (!fp){
			printf("file %s not found\n", argv[1]);
			return 1;
		}
		char bash_arr[MAX][10];
		char get_str[6];
		int i, j;
		char c[2];
		int count = 0;
		while(1){
			fgets(get_str, 10, fp);
			if (get_str[0] == 'p') break;
			sscanf(get_str, "%s %d %d", c, &i, &j);
			arr[i][j] = 'X';
		}

		//set_equal(temp_arr, arr);
		while(1){
			set_equal(temp_arr, arr);
			apply_rules(arr, temp_arr);
			set_equal(arr, temp_arr);
			system("clear");
			display_the_array(arr);
			usleep(75000);
			system("clear");
		}
	}else {
		printf("you entered too many arguments\n");
		return 2;
	}
	printf("\n");
	return 0;
}
