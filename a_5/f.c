#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define N 1000

ll harr[N];
int size = 0;

void swap(ll *a, ll *b) {
    ll temp = *b;
    *b = *a;
    *a = temp;
}

void minHeapify(int i) {
    if (size == 1) return;
    if (i >= size / 2) return;

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && harr[left] < harr[smallest])
        smallest = left;

    if (right < size && harr[right] < harr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(harr + i, harr + smallest);
        minHeapify(smallest);
    }
}

void insert(ll key) {
    if (!size)  {
        harr[size++] = key;
        return;
    }

    harr[size++] = key;

    for (int i = size / 2 - 1; i >= 0; --i) minHeapify(i);
}

ll getMin() {
    if (!size) return -1;

    ll key = harr[0];

    if (size > 1) {
        harr[0] = harr[size - 1];
        minHeapify(0);
    }

    size--;
    return key;
}

void printharr() {
    for (int i = 0; i < size; ++i)
        printf("%lld ", harr[i]);

    printf("\n");
}

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

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("[%d]: ", i);

        Node* u = g->adjList[i];

        for (Node* u = g->adjList[i]; u != NULL; u = u->next) {
            printf("%d ", u->vertex);
        }

        printf("\n");
    }
}

void BFS(Graph* graph, int startVertex) { 
    int visited[N] = {0};

    insert(startVertex); 
    visited[startVertex] = 1;

    while (size) {
        int v = getMin(); 
        printf("%d ", v + 1); // Print the minimum each time

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                visited[u->vertex] = 1;               
                insert(u->vertex);
            }
        }
    }
}

int main() {
    uint32_t n, m, u, v;
    scanf("%d%*c%d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u - 1, v - 1);
    }

    BFS(graph, 0);

    return 0;
}