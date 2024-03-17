#include <stdio.h>
#include <stdlib.h>
#define MAX_CITIES 20
struct Graph
{
    int vertices;
    int adjMatrix[MAX_CITIES][MAX_CITIES];
};
struct Graph createGraph(int N)
{
    struct Graph graph;
    graph.vertices = N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph.adjMatrix[i][j] = 0;
        }
    }
    printf("Enter connections between cities (0 for no connection, 1 for connection):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                printf("Is there a connection between city %d and city %d? (1/0): ", i + 1, j + 1);
                scanf("%d", &graph.adjMatrix[i][j]);
            }
        }
    }
    return graph;
}
void DFS(struct Graph graph, int start, int visited[])
{
    visited[start] = 1;
    printf("City %d is reachable.\n", start + 1);
    for (int i = 0; i < graph.vertices; i++)
    {
        if (graph.adjMatrix[start][i] == 1 && !visited[i])
        {
            DFS(graph, i, visited);
        }
    }
}
void printDFS(struct Graph graph, int start)
{
    int visited[MAX_CITIES] = {0};
    printf("Nodes reachable from City %d using DFS:\n", start + 1);
    DFS(graph, start, visited);
}
void BFS(struct Graph graph, int start, int visited[])
{
    int queue[MAX_CITIES];
    int front = -1, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;
    while (front <= rear)
    {
        int current = queue[front++];
        printf("City %d is reachable.\n", current + 1);
        for (int i = 0; i < graph.vertices; i++)
        {
            if (graph.adjMatrix[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
void printBFS(struct Graph graph, int start)
{
    int visited[MAX_CITIES] = {0};
    printf("Nodes reachable from City %d using BFS:\n", start + 1);
    BFS(graph, start, visited);
}

// output

// Enter the number of cities: 3
// Enter connections between cities (0 for no connection, 1 for connection):
// Is there a connection between city 1 and city 2? (1/0): 1
// Is there a connection between city 1 and city 3? (1/0): 1
// Is there a connection between city 2 and city 1? (1/0): 1
// Is there a connection between city 2 and city 3? (1/0): 1
// Is there a connection between city 3 and city 1? (1/0): 1
// Is there a connection between city 3 and city 2? (1/0): 0
// Enter the starting city to explore: 1 
// Nodes reachable from City 1 using DFS: 
// City 1 is reachable.
// City 2 is reachable.
// City 3 is reachable.
// Nodes reachable from City 1 using BFS: City 40 is reachable.
// City 1 is reachable.
// City 2 is reachable.
// City 3 is reachable.

int main()
{
    int N, startCity;
    printf("Enter the number of cities: ");
    scanf("%d", &N);
    struct Graph cityGraph = createGraph(N);
    printf("Enter the starting city to explore: ");
    scanf("%d", &startCity);
    if (startCity > 0 && startCity <= N)
    {
        printDFS(cityGraph, startCity - 1);
        printBFS(cityGraph, startCity - 1);
    }
    else
    {
        printf("Invalid starting city. Please enter a valid city number.\n");
    }
    return 0;
}
