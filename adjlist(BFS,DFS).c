#include<stdio.h>
#include<stdlib.h>
int n;
struct node
{
    int data;
    struct node *next;
};

void readgraph(struct node*adj[])
{
    struct node*newnode;
    int k,data;
    for(int i=0;i<n;i++)
    {
        struct node *last=NULL;
        printf("how many adjacent node to %d:  ",i);
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the %dth neighbour of %d :",j,i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            if(adj[i]==NULL)
            {
                adj[i]=newnode;
            }
            else
            {
                last->next=newnode;
            }
            last=newnode;
        }
    }
}

void bfs(struct node*adj[],int start,int visited[])
{
    int queue[n],front=-1,rear=-1;
    queue[++rear]=start;
    visited[start]=1;
    front++;
    printf("\nThe BFS traversal from %d is : \n",start);
    while(front<=rear)
    {
        printf("%d->",queue[front]);
        struct node *ptr;
        ptr=adj[queue[front++]];
        
        while(ptr!=NULL)
        {   
            if(visited[ptr->data]!=1)
            {
                queue[++rear]=ptr->data;
                visited[ptr->data]=1;
            }
            
            ptr=ptr->next;
        }
    }
}

void dfs(struct node*adj[],int start,int visited[])
{
    visited[start]=1;
    printf("%d->",start);
    struct node*ptr=adj[start];
    while(ptr!=NULL)
    {
        if(visited[ptr->data]==0)
        {
            dfs(adj,ptr->data,visited);
        }
        ptr=ptr->next;
    }

}

void printgraph(struct node *ad[])
{
	struct node *ptr  = NULL;
	int i,j;
	for(i=0;i<n;i++)
	{
		ptr = ad[i];
		printf("\n The neighbour of %d are :",i);
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
}

int main()
{
    int ch,data;
    printf("\nEnter the number of vertices\n");
    scanf("%d",&n);
    int visited[n];
    struct node *adj[n];
    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }
    readgraph(adj);
   
    do
    {
        printf("\nEnter 1 for BFS\nEnter 2 for DFS\nEnter 3 for printing\nEnter 4 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the starting vertex");
            scanf("%d",&data);
            for(int i=0;i<n;i++)
            {
                visited[i]=0;
            }
            bfs(adj,data,visited);
            break;

            case 2:
            printf("Enter the starting vertex");
            scanf("%d",&data);
            for(int i=0;i<n;i++)
            {
                visited[i]=0;
            }
            printf("\nThe DFS traversal from %d is : \n",data);
            dfs(adj,data,visited);
            break;

            case 3: printgraph(adj);break;

    
            case 4:
            printf("Exit point reached");
            break;
            
            // default:
            // printf("Please enter a valid choice");
        }
    }
    while(ch!=4);
    return 0;
}