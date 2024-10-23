#include <stdio.h>
#include <conio.h>
int i,n,x,top,choice,stack[100];
void push(void);
void pop(void);
void display(void);
int main()
{
clrscr();
top=-1;
printf("Enter the size of STACK [MAX = 100] : ");
scanf("%d",&n);
printf("STACK OPERATIONS USING ARRAY \n");
printf("1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT \n");
do
{
printf("Enter the Choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: printf("\nEXIT POINT \n");
break;
default: printf("\nPlease Enter a Valid Choice : (1/2/3/4)");
}
}
while(choice != 4);
getch();
return 0;
}
void push()
{
if(top >= n - 1)
{
printf("\nSTACK is Overflow\n");
}
else
{
printf("Enter a value to be pushed : ");
scanf("%d",&x);
top++;
stack[top] = x;
}
}
void pop()
{
if(top <= -1)
{
printf("\nSTACK is Underflow\n");
}
else
{
printf("\nThe popped element is : %d\n",stack[top]);
top--;
}
}
void display()
{
if(top >= 0)
{
printf("\nThe elements in STACK are : \n");
for(i = top;i >= 0;i--)
{
printf("%d\n",stack[i]);
}
printf("\nPress Next Choice\n");
}
else
{
printf("\nThe STACK is empty\n");
}
}