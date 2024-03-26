#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"gfx.h"

int main()
{
	char c;
	int wid = 700, ht = 500;
	int pausetime = 20000;
	srand(time(0));

	gfx_open(wid, ht, "funanim");
	gfx_flush();
	
	int xc = 350, yc = 250;
	int radius = 100;

	int x1, y1, x2, y2;
	x1 = xc + radius;
	x2 = xc - (radius/2);
	//y1 = yc;
	//y2 = yc;

	while(1)
	{
		gfx_circle(xc, yc, radius);
		gfx_line(xc, yc, x1, y1);
		gfx_flush;

		if (gfx_event_waiting()){
			c = gfx_wait();
			if (c == 'q'){
				break;
			}else if (c == ('1' || '2')){
				gfx_color(rand()%256, rand()%256, rand()%256);
			}
		}

		//usleep(pausetime);
		//gfx_clear();
	}
	return 0;
}
