#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define ull unsigned long long int
#define ll long long int
#define INF 9223372036854775807LL

ll graph[N][N];
ll cost[N];

ll min(ll x, ll y) { return x < y ? x : y; }

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(ll harr[], int *size, ll i) {
    if (*size == 1) return;
    if (i >= (*size) / 2) return;

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < (*size) && cost[harr[left]] < cost[harr[smallest]])
        smallest = left;

    if (right < (*size) && cost[harr[right]] < cost[harr[smallest]])
        smallest = right;

    if (smallest != i) {
        swap(harr + i, harr + smallest);
        minHeapify(harr, size, smallest);
    }
}

void insert(ll harr[], int *size, ll key) {
    if ((*size) == 0) {
        harr[(*size)++] = key;
        return;
    }

    harr[(*size)++] = key;

    for (int i = (*size) / 2 - 1; i >= 0; --i) minHeapify(harr, size, i);
}

ll extractMin(ll harr[], int *size) {
    if ((*size) <= 0) return -1;

    if ((*size) == 1) {
        (*size)--;
        return harr[0];
    }

    ll key = harr[0];
    harr[0] = harr[(*size) - 1];
    (*size)--;
    minHeapify(harr, size, 0);

    return key;
}

void printHeap(ll harr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("%lld ", harr[i]);
    }

    printf("\n");
}

void djikstra(int src, int n) {
    int visited[N] = {0};

    for (int i = 0; i < n; i++) {
        cost[i] = INF;
    }

    cost[src] = 0;

    ll pq[N];
    int pqSize = 0;

    insert(pq, &pqSize, src);

    while (pqSize) {
        ll u = extractMin(pq, &pqSize);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                cost[v] = min(cost[v], cost[u] + graph[u][v]);

                insert(pq, &pqSize, v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", cost[i]);
    }
}

int main() {
    int n, m, s, u, v;
    ll w;
    scanf("%d %d %d", &n, &m, &s);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    djikstra(s, n);

    // printf("%lld", INF);

    return 0;
}