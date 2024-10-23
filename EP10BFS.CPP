#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Graph structure using an adjacency matrix
int adj[MAX][MAX]; // Adjacency matrix to represent the graph
int visited[MAX]; // Array to mark visited nodes
int nodes; // Number of nodes in the graph
// Queue structure for BFS
int queue[MAX], front = -1, rear = -1;
// Function to insert an element into the queue
void enqueue(int v) {
if (rear == MAX - 1) {
printf("Queue Overflow\n");
return;
}
if (front == -1) {
front = 0;
}
rear++;
queue[rear] = v;
}
// Function to remove and return an element from the queue
int dequeue() {
if (front == -1 || front > rear) {
printf("Queue Underflow\n");
return -1;
}
int v = queue[front];
front++;
return v;
}
// Function to check if the queue is empty
int isQueueEmpty() {
return front == -1 || front > rear;
}
// Function to perform BFS
void BFS(int start) {
// Mark the start node as visited and enqueue it
visited[start] = 1;
enqueue(start);
printf("BFS Traversal: ");
while (!isQueueEmpty()) {
// Dequeue a node and print it
int v = dequeue();
printf("%d ", v);
// Visit all adjacent nodes of dequeued node
for (int i = 0; i < nodes; i++) {
if (adj[v][i] == 1 && !visited[i]) {
visited[i] = 1; // Mark as visited
enqueue(i); // Enqueue adjacent node
}
}
}
printf("\n");
}
int main() {
int edges, u, v;
// Input number of nodes
printf("Enter number of nodes: ");
scanf("%d", &nodes);
// Input number of edges
printf("Enter number of edges: ");
scanf("%d", &edges);
// Initialize adjacency matrix and visited array
for (int i = 0; i < nodes; i++) {
for (int j = 0; j < nodes; j++) {
adj[i][j] = 0;
}
visited[i] = 0;
}
// Input edges
for (int z = 0; z < edges; z++) {
printf("Enter edge (u v): ");
scanf("%d %d", &u, &v);
adj[u][v] = 1;
adj[v][u] = 1; // For undirected graph
}
// Perform BFS starting from node 0
BFS(0);
return 0;
}