// DRAW MAN WALKING IN THE RAIN WITH AN UMBRELLA

#include<stdio.h>
#include<graphics.h>

#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.75

int ldisp=0;

void DrawManAndUmbrella(int x,int ldisp)
{

	circle(x,GroundY-90,10);
	line(x,GroundY-80,x,GroundY-30);

	line(x,GroundY-70,x+10,GroundY-60);//hand
	line(x,GroundY-65,x+10,GroundY-55);//hand

	line(x+10,GroundY-55,x+20,GroundY-70);//elbow-hand

	line(x,GroundY-30,x+ldisp,GroundY);//leg
	line(x,GroundY-30,x-ldisp,GroundY);//leg




 pieslice(x + 20, GroundY - 120, 180, 360, 40);
    line(x + 20, GroundY - 120, x + 20, GroundY - 70);

}

void Rain(int x)
{
	int i,rx,ry;
	for(i=0;i<400;i++)
	{
		 rx=rand() % ScreenWidth;
		 ry=rand() % ScreenHeight;
		 if(ry<GroundY-4)
		 {
		  if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
		  line(rx,ry,rx+0.5,ry+4);
	 }
	}
}
int main()
	{
	  int gd=DETECT,gm,x=0;

	  initgraph(&gd,&gm,NULL);
	  while(true)
	  {

	   line(0,GroundY,ScreenWidth,GroundY);
	   Rain(x);
	   ldisp=(ldisp+2)%20;
	   DrawManAndUmbrella(x,ldisp);
	   delay(20);
	   cleardevice();
	   x=(x+2)%ScreenWidth;
	}
 	 getch();
}


