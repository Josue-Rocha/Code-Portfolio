// pathfunc.h
typedef struct {
  float x;
  float y;
} Point;

int  readvalues(FILE *, Point []);

float get_distance(float, float, float, float);

float get_total(Point [], int);

void display_all(Point [], float, int);
