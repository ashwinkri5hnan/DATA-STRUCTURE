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

struct adjlist
{
    struct node*head;
};

struct graph
{
    int novertex;
    int *visited;
    struct adjlist*adj;
};

struct node*createnode(int n)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=n;
    newnode->next=NULL;
    return newnode;
}

struct graph*creategraph(int n)
{
    int i;
    struct graph*g=malloc(sizeof(struct graph));
    g->novertex=n;
    g->visited=malloc(n*sizeof(int));
    g->adj=(struct adjlist*)malloc(n*sizeof(struct adjlist *));
    for(i=0;i<g->novertex;i++)
    {
        g->visited[i]=0;
        g->adj[i].head=NULL;
    }
    return g;
}

void printgraph(struct graph*g)
{
    for(int i=0;i<g->novertex;i++)
    {
        struct node*ptr=g->adj[i].head;
        while(ptr)
        {
            printf("\n%d->%d\n",i,ptr->vertex);
            ptr=ptr->next;
        }
    }
}

void transpose(struct graph*g,int s,int d)
{
    struct node*newnode=createnode(s);
    newnode->next=g->adj[d].head;
    g->adj[d].head=newnode;
}

void addedge(struct graph*g,struct graph *g1,int s,int d)
{
    struct node*newnode=createnode(d);
    newnode->next=g->adj[s].head;
    g->adj[s].head=newnode;
    transpose(g1,s,d);
}

void readgraph(struct graph*g,struct graph*g1)
{
    int i,j,num,data;
    for(i=0;i<g->novertex;i++)
    {
        struct node*ptr=NULL;
        struct node*ptr1=NULL;
        printf("\nEnter the number of adjacent vertices of %d:",i);
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            printf("\nEnter the %dth adjacent of %d:",j,i);
            scanf("%d",&data);
            addedge(g,g1,i,data);
        }
    }
}

void dfs(struct graph*g,int start)
{
    g->visited[start]=1;
    struct node*ptr=g->adj[start].head;  
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

void dfs1(struct graph*g)
{
    for(int i=0;i<g->novertex;i++)
    {
        if(g->visited[i]==0)
        {
            dfs(g,i);
        }
    }
}

void dfs2(struct graph*g,int start)
{
    g->visited[start]=1;
    printf("%d->",start);
    struct node*ptr=g->adj[start].head;
    while(ptr!=NULL)
    {
        if(g->visited[ptr->vertex]==0)
        {
            dfs2(g,ptr->vertex);
        }
        ptr=ptr->next;
    }
}

void strongly(struct graph*g)
{
    while(top!=-1)
    {
        int s=stack[top];
        top--;
        if(g->visited[s]==0)
        {
            printf("\nComponents:\t");
            dfs2(g,s);
        }
    }
}

int main()
{
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    struct graph*g=creategraph(n);
    struct graph*gr=creategraph(n);
    readgraph(g,gr);
    printgraph(g);
    printf("\nThe transpose of the graph is: ");
    printgraph(gr);
    dfs1(g);
    printf("\nStrongly connected components:");
    strongly(gr);
    return 0;
}