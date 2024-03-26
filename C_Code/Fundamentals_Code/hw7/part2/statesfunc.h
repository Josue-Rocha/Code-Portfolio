// statesfunc.h
// initialize the strcut
typedef struct {
	char abv[3];
	char statename[20];
	char capital[20];
	int year;
} State;

//initialize the functions
int readstates(FILE *, State []);

void display_options();

void display_everything(State [], int);

void display_state(State [], char [], int);

void display_capital(State [], char [], int);

void display_year(State [], char [], int);

void display_all_years(State [], int, int);
