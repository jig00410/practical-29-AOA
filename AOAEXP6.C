#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

// Struct for the edges of the graph
struct Edge {
    int u;  // Start vertex of the edge
    int v;  // End vertex of the edge
    int w;  // Weight of the edge (u, v)
};

// Graph - it consists of edges
struct Graph {
    int V;              // Total number of vertices in the graph
    int E;              // Total number of edges in the graph
    struct Edge *edge;  // Array of edges
};

void bellmanford(struct Graph *g, int source);
void display(int arr[], int size);

int main(void) {
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->V = 4;  // Total vertices
    g->E = 5;  // Total edges

    // Array of edges for the graph
    g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

    // Adding the edges of the graph
    g->edge[0].u = 0; g->edge[0].v = 1; g->edge[0].w = 5;
    g->edge[1].u = 0; g->edge[1].v = 2; g->edge[1].w = 4;
    g->edge[2].u = 1; g->edge[2].v = 3; g->edge[2].w = 3;
    g->edge[3].u = 2; g->edge[3].v = 1; g->edge[3].w = 6;
    g->edge[4].u = 3; g->edge[4].v = 2; g->edge[4].w = 2;

    bellmanford(g, 0);  // 0 is the source vertex
    return 0;
}

void bellmanford(struct Graph *g, int source) {
    int i, j, u, v, w;
    int tV = g->V;
    int tE = g->E;
    int d[tV];  // Distance array
    int p[tV];  // Predecessor array

    // Step 1: Initialize distances and predecessors
    for (i = 0; i < tV; i++) {
        d[i] = INFINITY;
        p[i] = -1;
    }
    d[source] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (i = 1; i <= tV - 1; i++) {
        for (j = 0; j < tE; j++) {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;
            if (d[u] != INFINITY && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (i = 0; i < tE; i++) {
        u = g->edge[i].u;
        v = g->edge[i].v;
        w = g->edge[i].w;
        if (d[u] != INFINITY && d[v] > d[u] + w) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Output the results
    printf("Distance array: ");
    display(d, tV);

    printf("Predecessor array: ");
    display(p, tV);
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
