#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm,i;
float x,y,dx,dy,step;
int x1,x0,y1,y0;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("Enter the value of first co-ordinates point:");
scanf("%d%d",&x0,&y0);
printf("Enter the value of second co-ordinates point:");
scanf("%d%d",&x1,&y1);
dx=(x1-x0);
dy=(y1-y0);
if (dx>=dy)
{
step=dx;
}

else
{
step=dy;
}
dx=dx/step;
dy=dy/step;
x=x0;
y=y0;
i=1;
while(i<=step)
{
putpixel(x,y,BLUE);
x+=dx;
y+=dy;
i=i+1;
}
getch();
closegraph();
}