#include<stdio.h>
#include<stdlib.h>
int n,j=-1,visited[100],queue[100];

void print(int adj[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}

void dfs(int start,int n,int adj[][n])
{
    visited[start]=1;
    for(int h=0;h<n;h++)
    {
        if(visited[h]!=1 && adj[start][h]==1)
        {
            dfs(h,n,adj);
        }
    }
    j+=1;
    queue[j]=start;
}

void topologicalsort(int n,int adj[][n])
{
    int i,start;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    j=0;
    for(int k=0;k<n;k++)
    {
        if(visited[k]==0)
        {
            dfs(k,n,adj);
        }
    }
}

int main()
{
    int s,d;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    int adj[n][n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
    int a, b;
    for (a = 0; a < n; a++) {
        for (b = 0; b <= n; b++) {
            adj[a][b] = 0;
        }
    }
    for (a = 1; a < n; a++) {
        for (b = 0; b < a; b++) {
            adj[a][b] = rand() % 2;
            adj[b][a] = 0;
        }
    }

    printf("\nThe directed acyclic graph in adjacency matrix form is: \n");
    print(adj);
    printf("\nThe topologically sorted order is :\n");
    topologicalsort(n,adj);
    for(int i=n;i>=1;i--)
    {
        printf("%d-->",queue[i]);
    }
    return 0;
}