#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 1000

struct Node
{
    int vertex;
    float weight;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjList;
};

typedef struct Node Node;
typedef struct Graph Graph;

float probabilities[N] = {1}, stopProb[N] = {0};
Graph* tree;

Node* createNode(int v, float w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
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

void addEdge(Graph* graph, int s, int d, float w) {
    Node* node = createNode(d, w);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;
}

void travserse(Graph* g) {
    for (int i = 0; i < g->numVertices; ++i) {
        printf("%d [%.2f]", i, probabilities[i]);
        for (Node *u = g->adjList[i]; u != NULL; u = u->next) {
            printf(" -> %d[%.2f]", u->vertex, probabilities[u->vertex]);
        }
        printf("\n");
    }
}

void BFS(Graph* graph, int startVertex) { // Uses a circular queue
    int q[N], front = 0, rear = 0;

    int visited[N] = {0};

    // Enque startVertex
    q[rear++] = startVertex; 
    visited[startVertex] = 1;

    while (front < rear) {
        // Dequeu
        int v = q[front++];
        front %= N;

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;

                probabilities[u->vertex] = u->weight * probabilities[v];

                q[rear++] = u->vertex;
                rear %= N;
            }
        }
    }
}

void computeStopProb(Graph* g) {
    for (int i = 0; i < g->numVertices; ++i) {
        for (Node *u = g->adjList[i]; u != NULL; u = u->next) {
            stopProb[i] += u->weight;
        }
        stopProb[i] = (1 - stopProb[i]) * probabilities[i];
    }
}

int cmpfunc(const void* a, const void* b) {
    float diff = stopProb[*(int*)a] - stopProb[*(int*)b];
    if (diff == 0) return diff;
    if (diff < 0)  return  1;
    if (diff > 0)  return -1;
}

int main() {
    uint32_t n, e, s, u, v;
    float w;
    scanf("%d %d %d", &n, &e, &s);

    tree = createGraph(n);

    for (int i = 0; i < e; ++i) {
        scanf("%d %d %f", &u, &v, &w);
        probabilities[v] = w;
        addEdge(tree, u, v, w);
    }

    BFS(tree, s);

    computeStopProb(tree);

    int ordering[n];

    
    for (int i =0; i < n; ++i) {
        ordering[i] = i;
    }

    qsort(ordering, n, sizeof(int), cmpfunc);

    printf("\n");

    for (int i =0; i < n; ++i) {
        printf("%d ", ordering[i]);
    }

    return 0;
}