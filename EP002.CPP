#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int top = -1;
char stack[100];
void push(char);
char pop();
int priority(char);
int main()
{
char *e,x,exp[100];
clrscr();
printf("Enter the expression : ");
scanf("%s",exp);
printf("Postfix Expression is : \n\t\t");
e = exp;
while(*e != '\0')
{
if(isalnum(*e))
{
printf("%c ",*e);
}
else if(*e == '(')
{
push(*e);
}
else if(*e == ')')
{
while((x = pop()) != '(')
{
printf("%c ", x);
}
}
else
{
while(priority(stack[top]) >= priority(*e))
{
printf("%c ",pop());
}
push(*e);
}
e++;
}
while(top != -1)
{
printf("%c ",pop());
}
getch();
return 0;
}
void push(char x)
{
stack[++top] = x;
}
char pop()
{
if(top == -1)
{
return -1;
}
else
{
return stack[top--];
}
}
int priority(char x)
{
if(x == '(') return 0;
if(x == '+' || x == '-') return 1;
if(x == '*' || x == '/') return 2;
return 0;
}
