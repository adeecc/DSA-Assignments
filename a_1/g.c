#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

uint8_t visited[N] = {0}, connectedComponents[N] = {0};
int numConnectedComponent = 0;

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
    int* visited;
};

typedef struct Node Node;
typedef struct Graph Graph;

Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->vertex = v;
    node->next = NULL;

    return node;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjList = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int s, int d) {
    Node* node = createNode(d);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;

    node = createNode(s);
    node->next = graph->adjList[d];
    graph->adjList[d] = node;
}

void BFS(Graph* graph, int startVertex) {
    int q[N], front = 0, rear = 0;

    // Enque startVertex
    q[rear++] = startVertex; // Enqueue

    visited[startVertex] = 1;
    connectedComponents[numConnectedComponent]++;


    while (front < rear) {
        int v = q[front++]; // Dequeue
        front %= N;

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;
                connectedComponents[numConnectedComponent]++;

                q[rear++] = u->vertex;
                rear %= N;
            }
        }

    }
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m, s, d;
    scanf("%d %d", &n, &m);

    Graph* goraq = createGraph(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &s, &d);
        addEdge(goraq, s, d);
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            BFS(goraq, v);
            numConnectedComponent++;
        }
    }

    printf("%d\n", numConnectedComponent);

    for (int i = 0; i < numConnectedComponent; ++i) {
        printf("%d ", connectedComponents[i]);
    }
    printf("\n");

    return 0;
}