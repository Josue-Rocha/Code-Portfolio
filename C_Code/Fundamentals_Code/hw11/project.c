#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "gfx2.h"
// project.c
// Josue Rocha
// jrocha3
typedef struct {
	float xc;
	float yc;
	float radius;
	float dx;
	float dy;
	int value;
} Circle;

float get_distance(int x1, int y1, int x2, int y2); // declare the function

int main()
{
	// declare variables
	int wid = 800, ht = 800;
	int pausetime = 10000;

	Circle circle_list[4];

	int change = 4;
	int radius = 100;
	int location = wid/2;
	int value = 100;

	// initialize the array of structs
	for (int i = 0; i < 4; i++)
	{
		circle_list[i].xc = location + 50;
		circle_list[i].yc = location - 50;
		circle_list[i].dx = change;
		circle_list[i].dy = change - 2;
		circle_list[i].radius = radius;
		circle_list[i].value = value;
		radius = radius/2;
		change += 2;
		location += 100;
		value += 150;
	}
	circle_list[0].xc = 150;

	gfx_open(wid, ht, "bounce");
	
	// declare more variables	
	int score = 0;
	char temp[20];
	char *line = temp;
	char c;
	int x, y, dist1, dist2, dist3, dist4;
	float dist[4];
	// strings for the intro page
	char intro1[] = "Welcome! click each circle to earn points!";
	char intro2[] = "(hint: the smaller the circle, the more points you get)";
	char intro3[] = "Enter a number to start:";
	char intro4[] = "Choose your level: 1: Easy 2: Medium 3: Hard";
	char intro5[] = "Press 'Q' to end once you're done";
	char *intro_p1 = intro1;
	char *intro_p2 = intro2;
	char *intro_p3 = intro3;
	char *intro_p4 = intro4;
	char *intro_p5 = intro5;

	gfx_color(10, 50, 250);
	// intro page
	while(1)
	{
		gfx_text(250, 385, intro_p1);
		gfx_text(250, 400, intro_p2);
		gfx_text(250, 415, intro_p3);
		gfx_text(250, 430, intro_p4);
		gfx_text(250, 445, intro_p5);
		if (gfx_event_waiting()){
			c = gfx_wait();
			// change the change in x and y coordinates of the ciricles depending on the level chosen
			if (c == '1'){
				break;
			}else if (c == '2'){
				for (int i = 0; i < 4; i++)
				{
					circle_list[i].dx += 4;
					circle_list[i].dy += 4;
				}
				break;
			}else if (c == '3'){
				for (int i = 0; i < 4; i++)
				{
					circle_list[i].dx += 8;
					circle_list[i].dy += 8;
				}
				break;
			}
		}
	}
	// circle game
	while (1)
	{
		sprintf(temp, "Your Score is: %d", score); // display the score
		gfx_text(400, 400, line);
		for (int i = 0; i < 4; i++)
		{
			gfx_fill_circle(circle_list[i].xc, circle_list[i].yc,  circle_list[i].radius);
			gfx_flush();
			circle_list[i].xc += circle_list[i].dx;
			circle_list[i].yc += circle_list[i].dy;
			if ((circle_list[i].xc + circle_list[i].radius) >= wid) circle_list[i].dx = -circle_list[i].dx;// detect right wall collision
			if ((circle_list[i].xc - circle_list[i].radius) <= 0) circle_list[i].dx = -circle_list[i].dx;// detect left  wall collision
			if ((circle_list[i].yc + circle_list[i].radius) >= ht) circle_list[i].dy = -circle_list[i].dy;// detect top wall collision
			if ((circle_list[i].yc - circle_list[i].radius) <= 0) circle_list[i].dy = -circle_list[i].dy;// detect bottom wall collision
		}



		if (gfx_event_waiting()){
			c = gfx_wait();
			if (c == 'q'){
				break;
			}else if (c == ('1'||'2'))
			{
				x = gfx_xpos();
				y = gfx_ypos();
				for (int i = 0; i < 4; i++)
				{
					dist[i] = get_distance(circle_list[i].xc, circle_list[i].yc, x, y);
					if (dist[i] <= circle_list[i].radius) score += circle_list[i].value; // adds to score if click is withing the circle
				}
			}
		}
		usleep(pausetime);
		gfx_clear();
	}
	printf("your final score is: %d!\n", score);
	return 0;
}
// write the function(s)

float get_distance(int x1, int y1, int x2, int y2)
{
	float distance;
	distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); // distance formula
	return distance;
}
