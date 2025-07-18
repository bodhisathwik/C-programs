#include <stdio.h>
#define MAX 100
int n;
int adj[MAX][MAX]; 
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int v) {
    if(front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = v;
    printf("Enqueued: %d\n", v);
}
int dequeue() {
    int v = queue[front];   
    front = front + 1;
    printf("Dequeued: %d\n", v);
    return v;
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void BFS(int start) {
    int i, v;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal Starting from vertex %d:\n", start);
    printf("Visited: %d ", start);
    while(!isEmpty()) {
        v = dequeue();
        for(i = 0; i < n; i++) {
            if(adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                printf("Visited: %d ", i);
            }
        }
    }
    printf("\nBFS Traversal Complete\n");
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
    BFS(start);
    return 0;
}