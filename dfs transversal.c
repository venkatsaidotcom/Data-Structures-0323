#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
void depthFirstSearch(int graph[MAX_NODES][MAX_NODES], bool visited[MAX_NODES], int current, int numNodes) {
    printf("%d ", current);
    visited[current] = true;
    int i,j;
    for ( i = 0; i < numNodes; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, visited, i, numNodes);
        }
    }
}
void initializeVisited(bool visited[MAX_NODES], int numNodes) {
	int i,j;
    for ( i = 0; i < numNodes; i++) {
        visited[i] = false;
    }
}
int main() {
    int numNodes, startNode;
    int i,j;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for ( i = 0; i < numNodes; i++) {
        for ( j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);
    bool visited[MAX_NODES];
    initializeVisited(visited, numNodes);
    printf("DFS Traversal: ");
    depthFirstSearch(graph, visited, startNode, numNodes);
    printf("\n");
	return 0;
}
