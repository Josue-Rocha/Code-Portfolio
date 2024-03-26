#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include "gfx.h"

int main()
{
	int wid = 700, ht = 500;
	int pausetime = 20000;

	gfx_open(wid, ht, "bounce");

	float xc = 50, yc = 50;
	int radius = 15;
	float dx = 9, dy = 3;

	int min = 5;
	int max = 30;

	char c;
	while (1)
	{
		gfx_circle(xc, yc, radius);
		gfx_flush();

		xc += dx;
		yc += dy;

		// detect right wall collision
		if ((xc + radius) >= wid) dx = -dx;

		// detect left wall collision
		if ((xc - radius) <= 0) dx = -dx;

		 //detect top wall collinsion
		if ((yc - radius) <= 0) dy = -dy;
		// detect bottom wall collision
		if ((yc + radius) >= ht) dy = -dy;

		if (gfx_event_waiting()){
			c = gfx_wait();
			if (c == 'q'){
				break;
			}else if (c == ('1'||'2')){
				gfx_clear();
				 xc = gfx_xpos();
				 yc = gfx_ypos();
				 srand(time(0));
				 dx = min + rand()%(max - min);
			}
		}
		usleep(pausetime);
		gfx_clear();
	}
	return 0;
}
