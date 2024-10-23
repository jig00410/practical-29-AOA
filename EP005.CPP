#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
int front,rear;
void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();
int pri_que[MAX];
int main()
{
int n,ch;
clrscr();
printf("1 - Insert an element into Queue\n");
printf("2 - Delete an element from Queue\n");
printf("3 - Display queue elements\n");
printf("4 - Exit\n");
create();
while(1)
{
printf("Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter value to be inserted : ");
scanf("%d",&n);
insert_by_priority(n);
break;
case 2: printf("Enter value to delete : ");
scanf("%d",&n);
delete_by_priority(n);
break;
case 3: display_pqueue();
break;
case 4: exit(0);
default: printf("\nChoice is Incorrect : Enter a correct choice\n");
}
}
}
void create()
{
front = rear = -1;
}
void insert_by_priority(int data)
{
if(rear >= MAX - 1)
{
printf("\nQueue Overflow : No more elements can be inserted\n");
return;
}
if((front == -1) && (rear == -1))
{
front++;
rear++;
pri_que[rear] = data;
return;
}
else
{
check(data);
rear++;
}
}
void check(int data)
{
int i,j;
for(i = 0;i <= rear;i++)
{
if(data >= pri_que[i])
{
for(j = rear + 1;j > i;j--)
{
pri_que[j] = pri_que[j - 1];
}
pri_que[i] = data;
return;
}
}
pri_que[i] = data;
}
void delete_by_priority(int data)
{
int i;
if((front==-1) && (rear==-1))
{
printf("\nQueue is Empty : No elements to delete\n");
return;
}
for(i = 0;i <= rear;i++)
{
if(data == pri_que[i])
{
for(;i < rear;i++)
{
pri_que[i] = pri_que[i + 1];
}
pri_que[i] = -99;
rear--;
if(rear == -1)
{
front = -1;
}
return;
}
}
printf("\n%d not found in queue to delete\n",data);
}
void display_pqueue()
{
if((front == -1) && (rear == -1))
{
printf("Queue is empty\n");
return;
}
for(;front <= rear;front++)
{
printf(" %d ",pri_que[front]);
}
printf("\n");
front = 0;
}