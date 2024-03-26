// ex75.c
#include <stdio.h>
#include "gfx.h"

int main()
{
  char c;
  gfx_open(400, 300, "something");

  gfx_color(100, 125, 140);
  gfx_circle(100, 150, 25);
  gfx_flush();

  while(1) {
    c = gfx_wait();
    printf("%d %c\n", c, c);

    if (c == 'q') break;
  }

  return 0;
}

