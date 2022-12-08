#include<stdio.h>
#include<stdlib.h>
int stack[100],choice,n,top,x,i;

void push()
{
if(top>=n-1)
{
printf("\nStack overflow");
}
else
{
printf("enter the value");
scanf("%d",&x);
top++;
stack[top]=x;
}
}
void pop()
{
if(top<=-1)
{
printf("\nStack underflow");
}
else{
printf("\nThe popped element is %d",stack[top]);
top--;
}
}
void display()
{
if(top>=0)
{
printf("\nThe elements in the stack are");
for(i=top;i>=0;i--){
printf("%d\n",stack[i]);
}
}
else
{
printf("\nThe stack is empty");
}
}

int main()
{
top=-1;
printf("\nEnter the size");
scanf("%d",&n);
printf("\nStack operations using array");
printf("\n1.Push\n2.pop\n3.Display\n4.Exit");
do
{
printf("\nEnter the choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;

case 2:
pop();
break;

case 3:
display();
break;

case 4:
exit(0);
break;

default:
printf("\nEnter a valid choice");
}
}

while(choice!=4);
return 0;

}
