#include <stdio.h>
#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("Visited: %d ", v);
    
    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            printf("\nGoing from %d to %d\n", v, i);
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
            
    for(i = 0; i < n; i++)
        visited[i] = 0;
        
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    
    printf("DFS Traversal Starting from vertex %d:\n", start);
    DFS(start);
    printf("\nDFS Traversal Complete\n");
    return 0;
}