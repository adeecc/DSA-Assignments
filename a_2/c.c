#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2000

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
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
}

void printGraph(Graph* graph, uint32_t v) {
    for (uint32_t i = 0; i < v; ++i) {
        printf("%d:", i + 1);
        for (Node* node = graph->adjList[i]; node != NULL; node = node->next) {
            printf(" -> %d", node->vertex + 1);
        }

        printf("\n");
    }
}

int BFS(Graph* graph, int startVertex,
        int endVertex) {  // Uses a circular queue

    uint8_t visited[N] = {0};
    int q[N], front = 0, rear = 0;

    // Enque startVertex
    q[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        // Dequeu
        int v = q[front++];
        front %= N;

        // printf("%d:", v + 1);

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;

                if (u->vertex == endVertex) return 1;

                // printf(" -> %d", u->vertex + 1);

                q[rear++] = u->vertex;
                rear %= N;
            }
        }
        // printf("\n");
    }

    return 0;
}

int main() {
    uint32_t n, m, u, v;
    scanf("%d%*c", &n);

    m = (n * (n - 1) * 0.5) - 1;

    Graph* results = createGraph(n);
    uint8_t adjMat[n][n];

    memset(adjMat, 0, sizeof adjMat);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);

        u--;
        v--;

        addEdge(results, u, v);

        adjMat[u][v] = adjMat[v][u] = 1;
    }

    uint32_t flag = 0, u1, u2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!adjMat[i][j] && i != j) {
                if (BFS(results, i, j)) {
                    printf("%d %d", i + 1, j + 1);
                    return 0;
                } 
                if (BFS(results, j, i)) {
                    printf("%d %d", j + 1, i + 1);
                    return 0;
                }
                else {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    printf("-1");

    return 0;
}