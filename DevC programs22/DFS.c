#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n; // number of vertices

// Function Definition: DFS(graph, v, visited)
void DFS(int v) {
	int i;
    visited[v] = 1;                 // Step 2: Mark current vertex as visited
    printf("%d ", v);               // Print the current vertex

    // Step 3: Recur for all adjacent vertices
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
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

    printf("\nDepth First Traversal starting from vertex %d:\n", start);
    DFS(start);

    return 0;
}

