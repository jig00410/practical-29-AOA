#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

// Graph structure using an adjacency matrix
int adj[MAX][MAX];  // Adjacency matrix to represent the graph
int visited[MAX];   // Array to mark visited nodes
int nodes;          // Number of nodes in the graph

// Function to perform DFS
void DFS(int v) {
    // Mark the node as visited
    visited[v] = 1;
    printf("%d ", v);  // Output the node

    // Visit all adjacent vertices that are not visited
    for (int i = 0; i < nodes; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;
    int i, j;  // Declare loop variables here to avoid redeclaration errors

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix to 0
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            adj[i][j] = 0;
        }
    }

    // Initialize visited array to 0
    for (i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    // Input edges
    for (i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // For undirected graph
    }

    // Perform DFS starting from node 0
    printf("DFS starting from node 0: ");
    DFS(0);

    return 0;
}
