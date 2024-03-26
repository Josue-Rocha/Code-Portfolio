//wordfunc.h
typedef struct {
	char word[16];
	int length;
	int index;
	int constant;
	int common;
	char direction;
	int check;
} Words;
const int MAX;

void init(char [][MAX], char [][MAX]);
void display_board(char [][MAX]);
void lower_to_upper(char [], int);
int check_word(char []);
void sort_list(Words [], int);
void place_longest_word(char [][MAX], char[][MAX], Words []);
void place_all_words(Words [], int, char [][MAX], char [][MAX]);
int place_new_word(Words [], int, char [][MAX], char [][MAX]);
int compare(Words [], int, int);
void display_clues(Words [], int);
void file_display_board(char [][MAX], FILE *);
//void file_display_clues(Words [], int, FILE *);

