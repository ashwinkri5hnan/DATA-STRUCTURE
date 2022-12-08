#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};

struct node*newnode,*head=NULL;

void push()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("Element cannot be inserted");
}
else
{
printf("Enter the data");
scanf("%d",&data);
newnode->data=data;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
}
}

void pop()
{
struct node*temp;
if(head==NULL)
{
printf("Stack is underflow");
}
else
{

temp=head;
head=head->next;
free(temp);
}
}

void display()
{
struct node*temp;
if(head==NULL)
{
printf("The stack is empty");
}
else
{
temp=head;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL");
}

}

void main()
{
int choice=0;
while(choice!=4)
{
printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("Enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:push();break;
case 2:pop();break;
case 3:display();break;
case 4:printf("Exit point reached");exit(0);break;
default:printf("\nEnter a valid choice\n");
}
}
}
