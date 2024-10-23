#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define n 5
int main()
{
int ch = 1,front = 0,rear = 0,i,j = 1,x = n,queue[n];
clrscr();
printf("Queue using Array : \n");
printf("1.Insertion \n2.Deletion \n3.Display \n4.Exit \n");
while(ch)
{
printf("Enter the choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: if(rear==x)
{
printf("Queue is Full\n");
}
else
{
printf("Enter no %d : ",j++);
scanf("%d",&queue[rear++]);
}
break;
case 2: if(front==rear)
{
printf("Queue is Empty\n");
}
else
{
printf("Deleted Element is %d\n",queue[front++]);
x++;
}
break;
case 3: printf("Queue Elements are : \n");
if(front==rear)
{
printf("Queue is Empty\n");
}
else
{
for(i = front;i < rear;i++)
{
printf("%d",queue[i]);
printf("\n");
}
}
break;
case 4: exit(0);
default: printf("\nWrong Choice : Please see the options\n");
}
}
getch();
return 0;
}
