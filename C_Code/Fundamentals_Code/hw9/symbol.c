#include<stdio.h>
#include<math.h>
#include"gfx.h"
//symbol.c
const int MAX = 50;

void place_circle(int, int, int);
void place_tri(int, int, int);
void place_square(int, int, int);
void place_shape(int, int, int, int);

int main()
{
	char c;
	int wid = 700, ht = 500;

	gfx_open(wid, ht, "symbol.c");
	gfx_flush();

	while(1)
	{
		c = gfx_wait();
		if (c == 'c'){
			gfx_color(250, 250, 250);
			int x, y, radius;
			x = gfx_xpos();
			y = gfx_ypos();
			radius = MAX/2;
			place_circle(x, y, radius);
		}else if (c == 't'){
			int x, y;
			gfx_color(100, 250, 50);
			x = gfx_xpos();
			y = gfx_ypos();
			place_tri(x, y, MAX);
		}else if (c == ('1' || '2')){
			int x, y;
			x = gfx_xpos();
			y = gfx_ypos();
			gfx_color(50, 50, 250);
			place_square(x, y, MAX);
		}else if (c >= '3' && c <= '9'){
			int x, y;
			int sides = c - '0';
			gfx_color(100, 25, 150);
			x = gfx_xpos();
			y = gfx_ypos();
			place_shape(x, y, MAX, sides);
		}else if (c == 27){
			gfx_clear();
		}else if (c == 'q'){
			break;
		}
	}
	return 0;
}

void place_circle(int x, int y, int radius)
{
	gfx_circle(x, y, radius);
}

void place_tri(int x, int y, int size)
{
	int len = (size/2);
	gfx_line(x, y - len, x + len, y + len);
	gfx_line(x, y - len, x - len, y + len);
	gfx_line(x - len, y + len, x + len, y + len);
}
void place_square(int x, int y, int size)
{
	int len = size/2;
	gfx_line(x - len, y - len, x - len, y + len);
	gfx_line(x + len, y - len, x + len, y + len);
	gfx_line(x - len, y - len, x + len, y - len);
	gfx_line(x + len, y + len, x - len, y + len);
}
void place_shape(int x, int y, int size, int sides)
{
	int len = size/2;
	double angle = (2 * M_PI)/sides;
	int x1, x2, y1, y2;
	for (double i = 0; i < (2 * M_PI); i += angle)
	{
		x1 = x + (len * cos(i));
		y1 = y + (-len * sin(i));
		x2 = x + (len * cos(i + angle));
		y2 = y + (-len * sin(i + angle));
		gfx_line(x1, y1, x2, y2);

	}
}
