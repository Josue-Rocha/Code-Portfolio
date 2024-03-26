// ex77b.c (added post-class)
//   same as ex77.c, but allows a natural quit when the user presses 'q'
//     (and hence shows the need for gfx_event_waiting() )

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

  char c;  // for user event 

  while(1) {
    gfx_circle(xc, yc, radius);
    gfx_flush();

    xc += dx;  
    yc += dy; 

    // detect right wall collision
    if((xc + radius) >= wid) {
      dx = -dx; 
    }

    if (gfx_event_waiting()) { 
      c = gfx_wait();
      if (c == 'q') break;
    }

    usleep(pausetime);
    gfx_clear();
  }

  return 0;
}

