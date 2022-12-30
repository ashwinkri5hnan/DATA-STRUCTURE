#include<stdio.h>
int main()
{
    int i,j,k,n,adj[10][10],indeg[10],flag[10],count=0; 
    printf("\nEnter the number of vertices\n");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter row %d::\t",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        indeg[i]=0;
        flag[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[i]=indeg[i]+adj[j][i]; 
        }
            
    }
    printf("The topologically sorted order is ");
    while(count<n)
    {
        for(k=0;k<n;k++)
        {
            if((indeg[k]==0) && (flag[k]==0))
            {
                printf("%d ",k+1);
                flag[k]=1;
            }
            
            for(i=0;i<n;i++)
            {
                if(adj[i][k]==1)
                {
                    indeg[k]--;
                }
            }
        }
        count++;

    }
        
    return 0;
}