#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N (int)1e5 + 1

int visited[N] = {0};
int infected[N] = {0};

int cmpfunc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

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

    node = createNode(s);
    node->next = graph->adjList[d];
    graph->adjList[d] = node;
}

int BFS(Graph* graph, int startVertex) {  // Uses a circular queue
    int q[N], front = 0, rear = 0;

    // Enque startVertex
    q[rear++] = startVertex;
    visited[startVertex] = 1;
    int infected = 1;

    while (front < rear) {
        // Dequeu
        int v = q[front++];
        front %= N;

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;
                infected++;

                q[rear++] = u->vertex;
                rear %= N;
            }
        }
    }

    return infected;
}

int main() {
    uint32_t n, m, u, v;
    scanf("%d%*c%d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            // printf("%d\n", v);
            infected[v] = BFS(graph, v);
        }
    }

    for (size_t i = 0; i < n; i++) {
        // printf("%d", infected[i]);
    }

    qsort(infected, n, sizeof(int), cmpfunc);

    // printf("\n");

    int sum = 0;
    float req = n * 0.8f;

    for (int i = 0; i < n; i++) {
        sum += infected[i];
        // printf("%d ", infected[i]);

        if (sum > req) {
            printf("\n%d", i + 1);
            break;
        }
    }

    return 0;
}