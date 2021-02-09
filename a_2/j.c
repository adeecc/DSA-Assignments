#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 5001

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
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

void BFS(Graph* graph, int startVertex, int endVertex) { // Uses a circular queue
    if (startVertex == endVertex) {
        printf("0");
        return;
    }

    uint32_t visited[N] = {0}, dist[N] = {UINT32_MAX}, pred[N] = {-1};
    int q[N], front = 0, rear = 0;

    // Enque startVertex
    q[rear++] = startVertex; 

    visited[startVertex] = 1;
    dist[startVertex] = 0;

    while (front < rear) {
        // Dequeu
        int v = q[front++];
        front %= N;

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;
                dist[u->vertex] = dist[v] + 1;
                pred[u->vertex] = v;

                q[rear++] = u->vertex;
                rear %= N;

                if (u->vertex == endVertex) {
                    printf("%d", dist[u->vertex] * 100);
                    return;
                }
            }
        }

    }

    printf("0");
}

int main() {
    uint32_t n, m, s, t, u, v;
    scanf("%d%*c%d%*c%d%*c%d%*c", &n, &m, &s, &t);

    Graph* route = createGraph(n);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(route, u, v);
    }

    BFS(route, s, t);        

    return 0;
}