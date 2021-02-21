#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10001

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

int _compare(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return 0;

    int count = 0, n = strlen(str1);

    for (int i = 0; i < n; ++i) {
        if (str1[i] != str2[i]) count++;

        if (count > 1) return 0;
    }

    return 1;
}

int BFS(Graph* graph, int startVertex,
        int endVertex) {  // Uses a circular queue
    int q[N], front = 0, rear = 0;

    int visited[N] = {0};
    int distance[N] = {0};

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
                distance[u->vertex] = distance[v] + 1;

                if (endVertex == u->vertex) {
                    return distance[u->vertex] - 1;
                }

                q[rear++] = u->vertex;
                rear %= N;
            }
        }
    }

    return -1;
}

int main() {
    uint32_t n;
    scanf("%d", &n);

    char strings[20][n + 1];

    for (int i = 0; i < n + 1; i++) {
        scanf("%s%*c", strings[i]);
    }

    Graph* dictionary = createGraph(n + 1);

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            if (_compare(strings[i], strings[j])) {
                addEdge(dictionary, i, j);
            }
        }
    }

    printf("%d", BFS(dictionary, 0, n));

    return 0;
}