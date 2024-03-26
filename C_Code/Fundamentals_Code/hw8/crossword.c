//crossword.c
#include<stdio.h>
#include<string.h>
#include"wordfunc.h"

const int MAX = 16;
int main(int argc, char *argv[])
{
	char sol_board[MAX][MAX];
	char puz_board[MAX][MAX];

	init(sol_board, puz_board);

	Words word_list[20];

	if (argc == 1){// interactive mode
		int count = 0;
		printf("Enter a list of words: \n");
		while (count <= 20){
			char word[100];
			scanf("%s", word);
			if (strcmp(word, ".") == 0)
			{
				break;
			}else{
				int check;
				check = check_word(word);
				if (check){
					lower_to_upper(word, check);
					strcpy(word_list[count].word, word);
					word_list[count].length = check;
					count++;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			sort_list(word_list, count);
		}
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", word_list[i].word);
		}
		place_longest_word(sol_board, puz_board, word_list);
		display_board(puz_board);
		display_board(sol_board);
		place_all_words(word_list, count, sol_board, puz_board);
		display_board(puz_board);
		display_board(sol_board);
		display_clues(word_list, count);
			
	}else if (argc == 2){
		FILE *fp;
		fp = fopen(argv[1], "r");
		if (!fp){
			printf("file %s not found\n", argv[1]);
			return 1;
		}
		char word[100];
		int count = 0;
		while(1){
			fgets(word, 100, fp);
			int n = 0;
			while (word[n] != '\0')
			{
				if (word[n] == '\n') word[n] = '\0';
				n++;
			}
			if (feof(fp)){
				break;
			}else if (count == 15){
				break;
			}else{
				int check = check_word(word);
				if (check){	
					lower_to_upper(word, check);
					strcpy(word_list[count].word,word);
					word_list[count].length = check;
				}
			}
			count++;
		}
		for (int i = 0; i < count; i++)
		{
			sort_list(word_list, count);
		}
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", word_list[i].word);
		}
		printf("\n");
		place_longest_word(sol_board, puz_board, word_list);
		place_all_words(word_list, count, sol_board, puz_board);
		display_board(puz_board);
		display_board(sol_board);
		display_clues(word_list, count);
	}else if (argc == 3){
		FILE *fp;
		fp = fopen(argv[1], "r");
		if (!fp){
			printf("file %s not found\n", argv[1]);
			return 1;
		}
		char word[100];
		int count = 0;
		while(1){
			fgets(word, 100, fp);
			int n = 0;
			while (word[n] != '\0')
			{
				if (word[n] == '\n') word[n] = '\0';
				n++;
			}
			if (feof(fp)){
				break;
			}else if (count == 15){
				break;
			}else{
				int check = check_word(word);
				if (check){	
					lower_to_upper(word, check);
					strcpy(word_list[count].word,word);
					word_list[count].length = check;
				}
			}
			count++;
		}
		for (int i = 0; i < count; i++)
		{
			sort_list(word_list, count);
		}
		FILE *pFILE;
		pFILE = fopen(argv[2], "a");

		place_longest_word(sol_board, puz_board, word_list);
		place_all_words(word_list, count, sol_board, puz_board);
		file_display_board(puz_board, pFILE);
		file_display_board(sol_board, pFILE);
		//file_display_clues(word_list, count, pFILE);
		fclose(pFILE);
	}else{
		printf("you entered too many arguments\n");
		return 2;
	}
	return 0;
}
