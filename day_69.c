// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Priority Queue (Min Heap)
struct HeapNode heap[MAX];
int size = 0;

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int vertex, int dist) {
    heap[size].vertex = vertex;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}

void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dijkstra(int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct HeapNode temp = pop();
        int u = temp.vertex;

        struct Node* curr = adj[u];
        while (curr != NULL) {
            int v = curr->vertex;
            int weight = curr->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }
            curr = curr->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(2, 3, 4);
    addEdge(3, 2, 6);

    dijkstra(V, 0);

    return 0;
}