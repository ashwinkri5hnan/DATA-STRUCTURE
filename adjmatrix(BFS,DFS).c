#include<stdio.h>
int n;
void printgraph(int adj[][n]){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
        }

}

void bfs(int adj[][n],int start)
{
    int visited[n],queue[n],front=-1,rear=-1;
    for(int i=0;i<n;i++)
        visited[i]=0;
    front++;
    queue[++rear]=start;
    visited[start]=1;
    while(front<=rear){
        start=queue[front++];
        printf("%d\t",start);
        for(int i=0;i<n;i++){
            if(adj[start][i]==1 && visited[i]!=1){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
    
}

void dfs(int adj[][n],int visited[],int start)
{
    printf("%d->",start);
    visited[start]=1;
    for(int i=0;i<n;i++){
        if(visited[i]!=1 && adj[start][i]==1){
            dfs(adj,visited,i);
        }
    }
}
int main(){
    int s,d,start,ch,visited[n];
    printf("Enter the number of vertices");
    scanf("%d",&n);
    int adj[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    
    printf("Enter an edge");
    while(s!=-1 && d!=-1){

        printf("Enter an egde from node(0 to %d) to node (0 to %d)",n,n);
        scanf("%d%d",&s,&d);
        adj[s][d]=1;
        adj[d][s]=1;
        
    }
   
    do{
        printf("Enter 1 for BFS\nEnter 2 for DFS\nEnter 3 for printing the matrix\nEnter 3 to Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        printf("Enter the starting vertex");
        scanf("%d",&start);
        bfs(adj,start);
        break;
        case 2:
        printf("Enter the starting vertex");
        scanf("%d",&start);
        for(int i=0;i<n;i++)
            visited[i]=0;
        dfs(adj,visited,start);
        break;
        case 3:
        printgraph(adj);
        break;
        case 4:
        printf("Exit point reached");
        default:printf("Enter a valid choice");
            break;
        }
    }
    while(ch!=5);
    printgraph(adj);
    return 0;
}
