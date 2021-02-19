#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

#define N 5000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int u, v, weight;
} Edge;

int parent[N], rank[N];

// DSU
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (rank[a] < rank[b]) swap(&a, &b);

        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int cmpfunc(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cost = 0;
    Edge edges[m];

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    for (int i = 0; i < m; ++i) {
        make_set(i);
    }

    qsort(edges, m, sizeof(Edge), cmpfunc);

    for (int i = 0; i < m; ++i) {
        Edge e = edges[i];
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            union_sets(e.u, e.v);
        }
    }

    printf("%d", cost);

    return 0;
}