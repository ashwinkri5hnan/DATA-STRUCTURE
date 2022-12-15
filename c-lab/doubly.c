#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*newnode,*temp,*head=NULL;

void insertbeg()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the element you want to insert in the beginning\n");
scanf("%d",&data);
if(head==NULL){
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    
}
else{
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
}

void insertlast(){
int data;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter your data");
scanf("%d",&data);
if(head==NULL){
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    
}
else{
    newnode->data=data;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=NULL;
    newnode->prev=temp;
    temp->next=newnode;
}
}
void insertspec()
{
int data,pos,i=1,count=0;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter your data");
scanf("%d",&data);
printf("Enter the position");
scanf("%d",&pos);
temp=head;
while(temp!=NULL){
    temp=temp->next;
    count++;
}

if(pos>count){
    printf("Insertion not possible since the position does not exist");
}
else{
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
        
    }
newnode->data=data;
newnode->next=temp->next;
newnode->prev=temp;
temp->next=newnode;
temp->next->prev=newnode;
}

}

void deletefirst()
{
if(head==NULL){
    printf("There are no elements in the list");
}
else if(head->next==NULL){
    head=NULL;
    free(head);
}
else{
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
}

void deletelast()
{
if(head==NULL){
    printf("There are no elements in the list");
}
else if(head->next==NULL){
    head=NULL;
    free(head);
}
else{
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    temp->prev->next=NULL;
    free(temp);
}
}

void deletespec(){
int pos;
printf("Enter the data after which the node is to be deleted");
scanf("%d",&pos);
temp=head;
while(temp->data!=pos){
    temp=temp->next;
}
if(temp->next==NULL){
    printf("Can't delete");
}
else if(temp->next->prev==NULL){
    temp->next=NULL;
}
else{
    newnode=temp->next;
    temp->next=newnode->next;
    newnode->next->prev=temp;
    free(newnode);
}
}
void search(){
    int i=0,item,flag=1;
    temp=head;
    if(head==NULL){
        printf("Empty list");
    }
    else{
        printf("Enter the element you want to search");
        scanf("%d",&item);
        while(temp!=NULL){
            if(temp->data==item){
                printf("Data found at %d",i+1);
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            i++;
            temp=temp->next;
        
        }
        if(flag==1){
            printf("Item not found");
        }
    }
}

void display()
{
if(head==NULL){
    printf("There are no elements in the list");
 head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
else{
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");

}
}


void main()
{
int i,n,choice,data;
printf("\n-----------------DOUBLY LINKED LIST---------------\n1.Insert at the beginning\n2.Insert at the last\n3.Insert at a specified position\n4.Delete from the beginning\n5.Delete from the last\n6.Delete from a specified position\n7.Search\n8.Display\n9.Exit");
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