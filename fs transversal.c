#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
typedef struct {
    int queue[MAX_NODES];
    int front, rear;
} Queue;
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
bool isQueueEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}
void enqueue(Queue* q, int node) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->queue[q->rear] = node;
}
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int node = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}
void breadthFirstSearch(int graph[MAX_NODES][MAX_NODES], int start, int numNodes) {
    bool visited[MAX_NODES] = { false };
    Queue q;
    initQueue(&q);
    int i,j;
    visited[start] = true;
    printf("BFS Traversal: %d ", start);
    enqueue(&q, start);
    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        for (i = 0; i < numNodes; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
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
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);
    breadthFirstSearch(graph, startNode, numNodes);
    return 0;
}

