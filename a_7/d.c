#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int

#define N (int)1e3
#define M (int)1e3

int min(const int x, const int y) { return x < y ? x : y; }

int n, m;

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

void initaliseGraph(Graph* g, int arr[n][m]) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == n - 1) {
                if (j != m - 1) {
                    addEdge(g, k, k + 1);
                }
            } else if (j == m - 1) {
                addEdge(g, k, k + m);
            } else {
                addEdge(g, k, k + 1);
                addEdge(g, k, k + m);
            }

            k++;
        }
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%d:", i);
        for (Node* node = graph->adjList[i]; node != NULL; node = node->next) {
            printf(" %d", node->vertex);
        }

        printf("\n");
    }
}

int dist[N * M], visited[N * M] = {0}, q[N * M];
int front = 0, rear = 0;

void BFS(Graph* graph) {  // Uses a circular queue
    while (front < rear) {
        int v = q[front++];
        front %= (N * M);

        for (Node* u = graph->adjList[v]; u != NULL; u = u->next) {
            if (!visited[u->vertex]) {
                dist[u->vertex] = min(dist[u->vertex], dist[v] + 1);

                visited[u->vertex] = 1;

                q[rear++] = u->vertex;
                rear %= (N * M);
            }
        }
    }
}

void findMinDist(Graph* g, int arr[n][m]) {
    for (int i = 0; i < m * n; i++) {
        dist[i] = 2147483647;
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                dist[k] = 0;
                visited[k] = 1;
                q[rear++] = k;
                rear %= (N * M);
            }

            k++;
        }
    }

    BFS(g);

    k = 0;
    char c;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            c = (j == m - 1) ? '\n' : ' ';
            printf("%d%c", dist[k], c);
            k++;
        }
    }

    for (int j = 0; j < m; j++) {
        (j == m - 1) ? printf("%d", dist[k]) : printf("%d ", dist[k]);
        k++;
    }
}

int main() {
    int u, v;
    scanf("%d%*c%d", &n, &m);

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    Graph* map = createGraph(n * m);
    initaliseGraph(map, arr);

    // printGraph(map);
    findMinDist(map, arr);

    return 0;
}