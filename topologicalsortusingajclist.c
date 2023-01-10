#include<stdio.h>
#include<stdlib.h>
int n; 
int stack[5];
int top=-1;
struct node
{
    int vertex;
    struct node*next;
};

struct graph
{
    int novertex;
    int*visited;
    struct node**adj;
};

struct node*createnode(int n)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=n;
    newnode->next=NULL;
    return newnode;
}

struct graph *creategraph(int n)
{
    int i;
    struct graph *g=(struct graph*)malloc(sizeof(struct graph));
    g->novertex=n;
    g->visited=(struct graph*)malloc(n*sizeof(int));
    g->adj=(struct node*)malloc(n*sizeof(struct node));
    for(i=0;i<n;i++)
    {
        g->visited[i]=0;
        g->adj[i]=NULL;
    }
    return g;
}

void readgraph(struct graph*g)
{
    int i,j,num,data;
    for(i=0;i<g->novertex;i++)
    {
        struct node*temp=NULL;
        printf("\nEnter the number of adjacent vertices of %d :",i);
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            printf("\nEnter %dth adjacent of %d:\t",j,i);
            scanf("%d",&data);
            struct node *new=createnode(data);
            if(g->adj[i]==NULL)
            {
                g->adj[i]=new;
            }
            else
            {
                temp->next=new;
            }
            temp=new;

        }
    }
}

void printgraph(struct graph*g)
{
    struct node*temp=NULL;
    for(int i=0;i<g->novertex;i++)
    {
        printf("\nAdjacent of %d are:",i);
        temp=g->adj[i];
        while(temp!=NULL)
        {
            printf("%d->",temp->vertex);
            temp=temp->next;
        }
    }
}

void dfs(struct graph*g,int start)
{
    g->visited[start]=1;
    struct node*ptr=g->adj[start];
    while(ptr!=NULL)
    {
        if(g->visited[ptr->vertex]==0)
        {
            dfs(g,ptr->vertex);
        }
        ptr=ptr->next;
    }
    top++;
    stack[top]=start;
}

void topologicalsort(struct graph*g)
{
    for(int i=0;i<g->novertex;i++)
    {
        if(g->visited[i]==0)
        {
            dfs(g,i);
        }
    }
}

void printts(struct graph*g)
{
    printf("\nThe topologically sorted order is: ");
    for(int i=top;i>-1;i--)
    {
        printf("%d->",stack[i]);
    }
}

int main()
{
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    struct graph*g=creategraph(n);
    readgraph(g);
    printgraph(g);
    topologicalsort(g);
    printts(g);
    return 0;
}