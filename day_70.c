// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE
#include <stdio.h>
#include <limits.h>

#define MAX 100

// Edge structure
struct Edge {
    int u, v, w;
};

int main() {
    int n, m;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex:\n");
    scanf("%d", &src);

    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE detected\n");
            return 0;
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
