#include <stdio.h>
#include <stdlib.h>
#define V 6
 void
 topologicalSortUtil(int graph[V][V], int v, int visited[], int stack[])
{
 visited[v] = 1;
 for (int i = 0; i < V; i++)
 {
 if (graph[v][i] == 1 && !visited[i])
 topologicalSortUtil(graph, i, visited, stack); }
 stack[--stack[V - 1]] = v;}
void topologicalSort(int graph[V][V])
{
 int visited[V];
 int stack[V];
 for (int i = 0; i < V; i++){
 visited[i] = 0;
 stack[i] = 0; }
for (int i = 0; i < V; i++){
 if (!visited[i])
 topologicalSortUtil(graph, i, visited, stack);}
 for (int i = 0; i < V; i++)
 printf("%d ", stack[i]);
 printf("\n");}
int main(){
 int graph[V][V] = {
 {0, 1, 1, 0, 0, 0},
 {0, 0, 0, 1, 0, 0},
 {0, 0, 0, 0, 1, 0},
 {0, 0, 0, 0, 0, 1},
 {0, 0, 0, 0, 0, 1},
 {0, 0, 0, 0, 0, 0}};
 topologicalSort(graph);
 return 0;
}