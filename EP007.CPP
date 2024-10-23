#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
int main()
{
int choice = 0;
clrscr();
while(choice != 7)
{
printf("\n**********Main Menu**********\n");
printf("Choose one option from the following list...\n");
printf("\n===============================================\n");
printf("1.Insert in beginning\n2.Insert at last\n3.Delete from beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n\n");

printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1: beginsert();
break;
case 2: lastinsert();
break;
case 3: begin_delete();
break;
case 4: last_delete();
break;
case 5: search();
break;
case 6: display();
break;
case 7: exit(0);
break;
default: printf("Please Enter Valid Choice");
}
}
getch();
return 0;
}
void beginsert()
{
int item;
struct node *ptr,*temp;
ptr = (struct node *) malloc(sizeof(struct node));
if(ptr == NULL)
{
printf("OVERFLOW\n");
}
else
{
printf("Enter the node data : ");
scanf("%d",&item);
ptr->data = item;
if(head == NULL)
{
head = ptr;
ptr->next = head;
}
else
{
temp = head;
while(temp->next != head)
temp = temp->next;
ptr->next = head;
temp->next = ptr;
head = ptr;
}
printf("Node Inserted\n");
}
}
void lastinsert()
{
int item;
struct node *ptr,*temp;
ptr = (struct node *) malloc(sizeof(struct node));
if(ptr == NULL)
{
printf("OVERFLOW\n");
}
else
{
printf("Enter Data : ");
scanf("%d",&item);
ptr->data = item;
if(head == NULL)
{
head = ptr;
ptr->next = head;
}
else
{
temp = head;
while(temp->next != head)
{
temp = temp->next;
}
temp->next = ptr;
ptr->next = head;
}
printf("Node Inserted\n");
}
}
void begin_delete()
{
struct node *ptr;
if(head == NULL)
{
printf("UNDERFLOW\n");
}
else if(head->next == head)
{
head = NULL;
free(head);
printf("Node Deleted\n");
}
else
{
ptr = head;
while(ptr->next != head)
ptr = ptr->next;
ptr->next = head->next;
free(head);
head = ptr->next;
printf("Node Deleted\n");
}
}
void last_delete()
{
struct node *ptr,*preptr;
if(head == NULL)
{
printf("UNDERFLOW\n");
}
else if(head->next == head)
{
head = NULL;
free(head);
printf("Node Deleted\n");
}
else
{
ptr = head;
while(ptr->next != head)
{
preptr = ptr;
ptr = ptr->next;
}
preptr->next = ptr->next;
free(ptr);
printf("Node Deleted\n");
}
}
void search()
{
struct node *ptr;
int item,i = 0,flag = 1;
ptr = head;
if(ptr == NULL)
{
printf("Empty List\n");
}
else
{
printf("Enter item which you want to search : ");
scanf("%d",&item);
if(head->data == item)
{
printf("Item found at location %d\n",i+1);
flag = 0;
}
else
{
while(ptr->next != head)
{
if(ptr->data == item)
{
printf("Item found at location %d\n",i+1);
flag = 0;
break;
}
else
{
flag = 1;
}
i++;
ptr = ptr->next;
}
}
if(flag != 0)
{
printf("Item not found\n");
}
}
}
void display()
{
struct node *ptr;
ptr = head;
if(head == NULL)
{
printf("Nothing to Print\n");
}
else
{
printf("Printing Values...\n");
while(ptr->next != head)
{
printf("%d\n",ptr->data);
ptr = ptr->next;
}
printf("%d\n",ptr->data);
}
}