#include<stdio.h>

int visited[10]={0},cost[10][10],min,mincost=0;
int input(int n)
{
    int i,j;
    printf("\nEnter the adjacency matrix::\t");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\nValue of cost[%d][%d]:\t",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    return 0;
}
int display(int n)
{
    int i,j;
    printf("\nThe cost of adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d",cost[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}
int prims(int n)
{
    int i,j,a,b,u,v,ne=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[1]=1;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        printf("\nEdge %d:(%d--%d) cost:%d\t",ne++,a,b,min);
        mincost=mincost+min;
        visited[b]=1;
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
    prims(n);
    return 0;
}