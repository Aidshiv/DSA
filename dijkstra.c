#include<stdio.h>
#define max 20
#define INF 999

void dijkstra(int n, int cam[max][max], int src);

void main() {
    int i, j, n, src, cost[max][max];

    printf("Enter the no. of vertices in the graph\n");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the %d,%d element\n", i + 1, j + 1);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF; // Initialize non-existing edges to infinity
            }
        }
    }
    printf("\n");

    printf("The Cost Adjacency matrix entered is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("Enter the source vertex\n");
    scanf("%d", &src);
    dijkstra(n, cost, src);
}

void dijkstra(int n, int cam[max][max], int src) {
    int i, j, min, u, v;
    int d[max], visited[max];

    for (i = 0; i < n; i++) {
        d[i] = cam[src][i];
        visited[i] = 0;
    }
    d[src] = 0; // Distance to itself is always 0
    visited[src] = 1;

    for (i = 1; i < n; i++) { // Run the loop n-1 times
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break; // If no vertex is found, break out of the loop

        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (!visited[v] && cam[u][v] != INF && d[u] + cam[u][v] < d[v]) {
                d[v] = d[u] + cam[u][v];
            }
        }
    }

    printf("The shortest dist path from src to various vertices is\n");
    for (v = 0; v < n; v++) {
        if (d[v] == INF) {
            printf("Vertex %d of the graph is unreachable from source\n", v);
        } else {
            printf("Shortest path value from Source=%d to Vertex=%d is =%d\n", src, v, d[v]);
        }
    }
}