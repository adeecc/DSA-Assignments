#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

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

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int greedyTwoColoring(Graph* graph) {
    int8_t coloring[N];

    coloring[0] = 0;

    for (int i = 1; i < graph->numVertices; ++i) coloring[i] = -1;

    Node* currentNode = NULL;
    for (int i = 0; i < graph->numVertices; ++i) {
        for (currentNode = graph->adjList[i]; currentNode != NULL;
             currentNode = currentNode->next) {
            if (coloring[currentNode->vertex] == -1) {
                coloring[currentNode->vertex] = !coloring[i];
            }

            else if (coloring[currentNode->vertex] == coloring[i]) {
                printf("NEED MORE COLOURS");
                return 0;
            }
        }
    }

    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%c", coloring[i] ? 'B' : 'R');
    }

    return 1;
}

int main() {
    uint32_t n, m, u, v;
    scanf("%d %d%*c", &n, &m);

    Graph* rangoli = createGraph(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(rangoli, u, v);
    }

    greedyTwoColoring(rangoli);

    return 0;
}