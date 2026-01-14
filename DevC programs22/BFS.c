#include <stdio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;  // Number of vertices

// Function Definition: BFS(graph, start, visited)
void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i, v;

    // Step 2: Initialize Queue
    queue[rear++] = start;     // Enqueue the starting vertex
    visited[start] = 1;        // Mark start vertex as visited

    // Step 3: Process the queue until empty
    while (front < rear) {
        v = queue[front++];    // Dequeue a vertex
        printf("%d ", v);      // Print the current vertex

        // For each vertex adjacent to v
        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;   // Enqueue the vertex
                visited[i] = 1;      // Mark it as visited
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;  // Initialize all vertices as not visited

    printf("\nBreadth First Traversal starting from vertex %d:\n", start);
    BFS(start);

    return 0;
}

