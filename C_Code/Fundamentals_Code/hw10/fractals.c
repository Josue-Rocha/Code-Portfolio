// includes
// fractals.c
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<math.h>
#include"gfx.h"

// function prototypes
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void draw_tri(int x1, int y1, int x2, int y2, int x3, int y3);
void shrink_sq(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int mrgn);
void draw_sq(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
//void spiral_sq(int x, int y, float r);
void spiral_sq(int x, int y, float angle, int r1, int r2, int variable);
void draw_spiral_sq(int x, int y, float r);
void circ_lace(int x, int y, float r);
void draw_circle(int x, int y, float r);
void snowflake(int x, int y, int len);
void tree(int x, int y, int len, float angle);

int main() 
{
	// variable declarations
	int width = 700, height = 700;
	bool loop = true;
	char c;
	
	gfx_open(width, height, "fractals");
	
	while (1) {
		c = gfx_wait();
		gfx_clear();
		if (c == '1') { // Sierpinski's Triangle
			gfx_clear();
			int mrgn = 20;
			sierpinski(mrgn, mrgn, width - mrgn, mrgn, width/2, height - mrgn);
		}else if (c == '2'){ // Shrinking Squares
			gfx_clear();
			int mrgn = 200;
			int a, b, c, d, e, f, g, h, temp1;
			temp1 = (width - (2*mrgn))/5;
			shrink_sq(mrgn, mrgn, width - mrgn, mrgn, mrgn, height - mrgn, width - mrgn, height - mrgn, temp1);
		}else if (c == '3'){ // spiral of squares
			float angle = (M_PI/3);
			int val1 = 5;
			int val2 = 1;
			float val = 0;
			int x = width/2, y = height/2;
			spiral_sq(x, y, angle, val1, val2, val);
		}else if (c == '4'){
			int x = width/2, y = height/2;
			float r = 200;
			gfx_circle(x, y, r);
			circ_lace(x, y, r);
		}else if (c == '5'){ // snowflake
			int x = width/2, y = height/2, len = 200;
			snowflake(x, y, len);
		}else if (c == '6'){
			int x = width/2;
			int y = height;
			int len = 250;
			float angle = M_PI/4;
			gfx_line(x, y, x, y - len);
			tree(x, y - len, len/2, angle);
		}else if (c == '7'){
		}else if (c == '8'){
		}else if (c == 'q'){ 
			break;
		}else {
		}
	}
	return 0;
}

// all functions go here
//  (or placed in a separate file if you wish to split)

void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3)
{
	// base case
	if (abs(x2-x1) < 5) return;

	// Draw a triangle
	draw_tri(x1, y1, x2, y2, x3, y3);

	//Recursive calls
	sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
	sierpinski((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
	sierpinski((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}
void draw_tri(int x1, int y1, int x2, int y2, int x3, int y3)
{
	gfx_line(x1, y1, x2, y2);
	gfx_line(x2, y2, x3, y3);
	gfx_line(x3, y3, x1, y1);
}

void shrink_sq(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int mrgn)
{
	// Base Case
	if (mrgn < 1) return;

	// Draw a Square
	draw_sq(x1, y1, x2, y2, x3, y3, x4, y4);
	mrgn = (x2 - x1)/5;

	// Recursing calls
	shrink_sq((x1 - mrgn), (y1 + mrgn), (x1 + mrgn), (y1 + mrgn), (x1 - mrgn), (y1 - mrgn), (x1 + mrgn), (y1 - mrgn), mrgn); // top left
	shrink_sq((x2 - mrgn), (y2 + mrgn), (x2 + mrgn), (y2 + mrgn), (x2 - mrgn), (y2 - mrgn), (x2 + mrgn), (y2 - mrgn), mrgn); // top right
	shrink_sq((x3 - mrgn), (y3 + mrgn), (x3 + mrgn), (y3 + mrgn), (x3 - mrgn), (y3 - mrgn), (x3 + mrgn), (y3 - mrgn), mrgn); // bottom left
	shrink_sq((x4 - mrgn), (y4 + mrgn), (x4 + mrgn), (y4 + mrgn), (x4 - mrgn), (y4 - mrgn), (x4 + mrgn), (y4 - mrgn), mrgn); // bottom right
}
void draw_sq(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	gfx_line(x1, y1, x2, y2);
	gfx_line(x1, y1, x3, y3);
	gfx_line(x3, y3, x4, y4);
	gfx_line(x2, y2, x4, y4);

}
void spiral_sq(int x, int y, float angle, int r1, int r2, int variable)
{
	// base case
	if ( angle >= (2 * M_PI)) return;
	// draw square
	draw_spiral_sq(x, y, angle);
	// recursive call
	spiral_sq(x + (r1 * cos(angle)), y + (r1 * sin(angle)), angle + (M_PI/3), pow(2.5, variable), r2 + 1, variable + (M_PI/3));
}
void draw_spiral_sq(int x, int y, float r)
{
	gfx_line(x - r, y + r, x + r, y + r);
	gfx_line(x + r, y + r, x + r, y - r);
	gfx_line(x + r, y - r, x - r, y - r);
	gfx_line(x - r, y - r, x - r, y + r);
}
void draw_circle(int x, int y, float r)
{
	gfx_circle(x, y, r);
}
void circ_lace(int x, int y, float r)
{
	// base case
	if (r <= 1) return;
	// draw circles
	gfx_circle(x, y, r);
	// recursive calls
	circ_lace(x - r, y, r/3);
	circ_lace(x + r, y, r/3);
	circ_lace(x - (r/2), y - ((r*sqrt(3))/2), r/3);
	circ_lace(x - (r/2), y + ((r*sqrt(3))/2), r/3);
	circ_lace(x + (r/2), y - ((r*sqrt(3))/2), r/3);
	circ_lace(x + (r/2), y + ((r*sqrt(3))/2), r/3);
}
void snowflake(int x, int y, int len)
{
	// base case
	if (len < 1) return;
	//draw lines
	gfx_line(x, y, x, y + len);
	gfx_line(x, y, x - ((len*sqrt(2))/2), y - ((len*sqrt(2))/2));
	gfx_line(x, y, x + ((len*sqrt(2)/2)), y - ((len*sqrt(2))/2));
	gfx_line(x, y, x - ((len*sqrt(3))/2), y + len/2);
	gfx_line(x, y, x + ((len*sqrt(3))/2), y + len/2);
	/*gfx_line(x, y, x - (len*cos((2*M_PI)/5)), y - (len*sin((2*M_PI)/5)));
	gfx_line(x, y, x + (len*cos((2*M_PI)/5)), y - (len*sin((2*M_PI)/5)));
	gfx_line(x, y, x - (len*cos((M_PI)/5)), y + (len*sin((M_PI)/5)));
	gfx_line(x, y, x + (len*cos((M_PI)/5)), y + (len*sin((M_PI)/5)));*/

	// recursive call
	snowflake(x, y + len, len/3);
	snowflake(x - ((len*sqrt(2))/2), y - ((len*sqrt(2))/2), len/3);
	snowflake(x + ((len*sqrt(2))/2), y - ((len*sqrt(2))/2), len/3);
	snowflake(x - ((len*sqrt(3))/2), y + len/2, len/3);
	snowflake(x + ((len*sqrt(3))/2), y + len/2, len/3);
}
void tree(int x, int y, int len, float angle)
{
	// base case
	if (len <= 1) return;

	// print line
	gfx_line(x, y, x - (len*cos(angle)), y - (len*sin(angle)));
	gfx_line(x, y, x + (len*cos(angle)), y - (len*sin(angle)));

	// recursive call
	tree(x - (len*cos(angle)), y - (len*sin(angle)), len/2, angle - (M_PI/3));
	tree(x + (len*cos(angle)), y - (len*sin(angle)), len/2, angle - (M_PI/3));
}
