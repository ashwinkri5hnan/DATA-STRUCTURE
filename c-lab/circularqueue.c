#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node*next;
};
struct node*newnode;
struct node*front=-1;
struct node*rear=-1;

void enqueue()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the value\n");
scanf("%d",&data);
newnode->data=data;
newnode->next=NULL;
if(rear==-1)
{
front=rear=newnode;
rear->next=front;
}
else
{
rear->next=newnode;
rear=newnode;
rear->next=front;
}
}

void dequeue()
{
struct node*ptr;
ptr=front;
if((front==-1)&&(rear==-1))
{
printf("\nThe queue has no elements to delete from.\n");
}
else if(front==rear)
{
front=-1;
rear=-1;
free(ptr);
}
else
{
front=front->next;
rear->next=front;
free(ptr);
}
}

void peek()
{
struct node*temp;
if((front==-1)&&(rear==-1))
{
printf("\nEmpty queue\n");
}
else
{
temp=front;
printf("%d",temp->data);
}
}

void display()
{
if((front==-1)&&(rear==-1))
{
printf("\nEmpty queue\n");
}
else
{
struct node*temp;
temp=front;
while(temp->next!=front)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("%d->",temp->data);
printf("NULL");
}
}

void main()
{
int choice=0;
while(choice!=5)
{
printf("\n___________________Circular queue___________________\n");
printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
printf("\nEnter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();break;
case 2:dequeue();break;
case 3:peek();break;
case 4:display();break;
case 5:printf("\nExit point reached\n");exit(0);break;
default:printf("Enter a valid choice");
}
}
}
