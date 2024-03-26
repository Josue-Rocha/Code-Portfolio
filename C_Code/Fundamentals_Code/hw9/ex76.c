// ex76.c
#include <stdio.h>
#include <unistd.h>
#include "gfx.h"

int main()
{
  char c;
  gfx_open(700, 400, "something");

  int xc = 50, yc = 50;
  int dx = 1;  // horizontal step size 

  while(1) {
    gfx_circle(xc, yc, 15);
    gfx_flush();

    xc += dx;  // move the circle center's x coord.

    usleep(10000);
    gfx_clear();
  }

  return 0;
}

