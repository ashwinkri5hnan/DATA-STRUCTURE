#include<stdio.h>

int parent[10],cost[10][10],min,mincost=0;
int input(int n)
{
    int i,j;
    printf("\nEnter the adjacency matrix::\t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\nValue of cost[%d][%d]:\t",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    return 0;
}
int find(int a)
{
    while(parent[a])
    {
        a=parent[a];
    }
    return a;
}

int uni(int a,int b)
{
    if(a!=b)
    {
        parent[b]=a;
        return 1;
    }
    return 0;
}

int display(int n)
{
    int i,j;
    printf("\nThe cost of adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",cost[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}
int kruskal(int n)
{
    int i,j,a,b,u,v,ne=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    while(ne<n)
    {
        for(i=0,min=999;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                   
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("\nEdge %d:(%d--%d) cost:%d\t",ne++,a,b,min);
            mincost=mincost+min;
        }
        cost[a][b]=cost[b][a]=999;

    }
    printf("The minimum cost is %d",mincost);
    return 0;
}



int main()
{
    int n;
    printf("\nEnter the number of nodes::\t");
    scanf("%d",&n);
    input(n);
    display(n);
    kruskal(n);
    return 0;
}