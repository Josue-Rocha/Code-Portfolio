// includes
// fractals.c
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

// function prototypes
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

int main() 
{
	// variable declarations
	int width = 700, height = 700, mrgn = 20;
  bool loop = true;

  gfx_open(width, height, "fractals" );

  while (loop) {
    c = gfx_wait();
    gfx_clear();
    switch (c) {
      case '1': // Sierpinski Triangle   
        break;
      case '2': // Shrinking Squares  
        break;
      case '3':
        break;
      case '4':
      
      case '8': // Spiral of Spirals 
        ... set up some variables
        ...
        ... call a recursive function  
        break;
      case 'q':
        loop = false;
      default:
        break;
    }
  }

  return 0;
}

// all functions go here
//  (or placed in a separate file if you wish to split)


