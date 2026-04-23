// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];     // To store MST
    int key[MAX];        // Minimum weights
    int mstSet[MAX];     // Included in MST

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0; // Start from node 1
    parent[1] = -1;

    for (int count = 1; count < n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 2; i <= n; i++) {
        totalWeight += key[i];
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}