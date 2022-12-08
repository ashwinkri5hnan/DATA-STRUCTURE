#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};

struct node*temp,*newnode,*head=NULL;

void creation(int data)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
temp=newnode;
}
else
{
temp->next=newnode;
temp=newnode;
}
}

void insertbeg()
{
int newdata;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the element you want to add in the beginning of the list");
scanf("%d",&newdata);
newnode->data=newdata;
newnode->next=head;
head=newnode;
}

void insertlast()
{
int lastdata;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the element you want to add in the end of the list");
scanf("%d",&lastdata);
newnode->data=lastdata;
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
temp=newnode;
}




void insertspec()
{
int item,pos,i=1;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the position");
scanf("%d",&pos);
printf("Enter the element you want to add in %d position",pos);
scanf("%d",&item);
newnode->data=item;
temp=head;
while(i<pos-1)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;
}


void deletefirst()
{
temp=head;
head=temp->next;
free(temp);
}


void deletelast()
{
struct node*prev;
temp=head;
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
prev->next=NULL;
free(temp);
}

void deletespec()
{
int pos,i=1;
printf("Enter the position you want to delete from");
scanf("%d",&pos);
temp=head;
while(i<pos-1)
{
temp=temp->next;
i++;
}
newnode=temp->next;
temp->next=newnode->next;
free(newnode);
}


void search()
{
int key,i=0;
printf("Enter the element to be searched");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
temp=temp->next;
i++;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("There is no element such as '%d'",key);
}
else
{
printf("the element %d can be found in %d position.",key,i+1);
}

}

void display()
{
if(head==NULL)
{
printf("there are no elements in the list");
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
int i,n,choice,data;
printf("Enter the size of the list");
scanf("%d",&n);
printf("Enter the elements");
for(i=0;i<n;i++)
{
scanf("%d",&data);
creation(data);
}
display();
printf("\n-----------------SINGLY LINKED LIST---------------\n1.Insert at the beginning\n2.Insert at the last\n3.Insert at a specified position\n4.Delete from the beginning\n5.Delete from the last\n6.Delete from a specified position\n7.Search\n8.Display\n9.Exit");
do
{
printf("\nEnter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insertbeg();break;
case 2:insertlast();break;
case 3:insertspec();break;
case 4:deletefirst();break;
case 5:deletelast();break;
case 6:deletespec();break;
case 7:search();break;
case 8:display();break;
case 9:printf("Exit point");exit(0);
default:printf("Enter a valid choice");
}
}
while(choice!=9);
}
