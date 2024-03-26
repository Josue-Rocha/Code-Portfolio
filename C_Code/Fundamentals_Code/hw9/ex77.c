// ex77.c (update to ex76.c)
//  setting up a 'velocity vector'
//  detecting collision with one wall
//   (note: no need for stdio.h here! )
#include <unistd.h>
#include "gfx.h"

int main()
{
  int wid = 700, ht = 500;
  int pausetime = 20000;

  gfx_open(wid, ht, "snowy day");

  float xc = 50, yc = 50;  // center's coordinates
  int radius = 15;  
  float dx = 4, dy = 1;    // horiz, vert step sizes 

  while(1) {
    gfx_circle(xc, yc, radius);
    gfx_flush();

    // change circle's position
    xc += dx;  
    yc += dy; 

    // detect right wall collision
    if((xc + radius) >= wid) {
      dx = -dx; 
    }

    usleep(pausetime);
    gfx_clear();
  }

  return 0;
}

