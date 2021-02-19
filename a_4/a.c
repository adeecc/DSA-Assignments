#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (int)1
#define FALSE (int)0

#define N 26

int ans[26] = {0}, ans_rear = 0;
int parent[26] = {0};

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

int DFS(Graph* graph, int start, int visited[N]) {
    visited[start] = 1;

    for (Node* u = graph->adjList[start]; u != NULL; u = u->next) {
        if (visited[u->vertex] == 0) {
            parent[u->vertex] = start;
            if (DFS(graph, u->vertex, visited)) {
                return TRUE;
            }
        } else if (visited[u->vertex] == 1) {
            return TRUE;
        }
    }
    visited[start] = 2;
    ans[ans_rear++] = start;
    return FALSE;
}

void topologicalSort(Graph* graph, int charset[N]) {
    int visited[N] = {0};

    for (int i = 0; i < N; ++i) {
        if (charset[i] && !visited[i]) {
            if (DFS(graph, i, visited)) {
                printf("ALIENS BE CRAZY");
                return;
            }
        }
    }

    for (int i = ans_rear - 1; i >= 0; --i) {
        printf("%c", (char)(ans[i] + 'A'));
    }
}

int main() {
    uint32_t n = N, m;
    char u, v;
    scanf("%d%*c", &m);

    Graph* language = createGraph(n);

    int charset[N] = {0};

    for (int i = 0; i < m; ++i) {
        scanf("%c %c%*c", &u, &v);
        addEdge(language, (int)u - 'A', (int)v - 'A');
        charset[(int)u - 'A'] = 1;
        charset[(int)v - 'A'] = 1;
    }

    // printGraph(language);
    // Check for cycles...

    topologicalSort(language, charset);

    return 0;
}