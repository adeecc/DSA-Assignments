#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N (int)1e6

typedef struct {
    ll key;
    int idx;
    int visited;
} Node;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node harr[], int *size, int i) {
    if (*size == 1) return;
    if (i >= (*size) / 2) return;

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < (*size) && harr[left].key < harr[smallest].key) smallest = left;

    if (right < (*size) && harr[right].key < harr[smallest].key)
        smallest = right;

    if (smallest != i) {
        swap(harr + i, harr + smallest);
        minHeapify(harr, size, smallest);
    }
}

void maxHeapify(Node harr[], int *size, int i) {
    if (*size == 1) return;
    if (i >= (*size) / 2) return;

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < (*size) && harr[left].key > harr[smallest].key) smallest = left;

    if (right < (*size) && harr[right].key > harr[smallest].key)
        smallest = right;

    if (smallest != i) {
        swap(harr + i, harr + smallest);
        minHeapify(harr, size, smallest);
    }
}

void insertMinHeap(Node harr[], int *size, Node key) {
    if ((*size) == 0) {
        harr[(*size)++] = key;
        return;
    }

    harr[(*size)++] = key;

    for (int i = (*size) / 2 - 1; i >= 0; --i) minHeapify(harr, size, i);
}

void insertMaxHeap(Node harr[], int *size, Node key) {
    if ((*size) == 0) {
        harr[(*size)++] = key;
        return;
    }

    harr[(*size)++] = key;

    for (int i = (*size) / 2 - 1; i >= 0; --i) maxHeapify(harr, size, i);
}

Node extractMin(Node harr[], int *size) {
    if ((*size) <= 0) return (Node){.idx = -1, .key = -1};

    if ((*size) == 1) {
        (*size)--;
        return harr[0];
    }

    Node key = harr[0];
    harr[0] = harr[(*size) - 1];
    (*size)--;
    minHeapify(harr, size, 0);

    return key;
}

Node extractMax(Node harr[], int *size) {
    if ((*size) <= 0) return (Node){.idx = -1, .key = -1};

    if ((*size) == 1) {
        (*size)--;
        return harr[0];
    }

    Node key = harr[0];
    harr[0] = harr[(*size) - 1];
    (*size)--;
    maxHeapify(harr, size, 0);

    return key;
}

void printHeap(Node harr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("[%d]%lld ", harr[i].idx, harr[i].key);
    }

    printf("\n");
}

int main() {
    int n, q, k;
    scanf("%d %d", &n, &q);

    ll cum_sum = 0;

    Node minHeap[N], maxHeap[N];
    int minHeapSize = 0, maxHeapSize = 0;

    Node key;

    for (size_t i = 0; i < n; ++i) {
        scanf("%lld", &key.key);
        key.idx = i;
        key.visited = 0;

        insertMaxHeap(maxHeap, &maxHeapSize, key);
        insertMinHeap(minHeap, &minHeapSize, key);

        cum_sum += key.key;
    }

    Node smollest, largest;

    int visited[N] = {0};

    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &k);

        smollest = extractMin(minHeap, &minHeapSize);
        while (visited[smollest.idx]) {
            smollest = extractMin(minHeap, &minHeapSize);
            // printf("Checking smolest: [%d]%lld", smollest.idx, smollest.key);
        }

        largest = extractMax(maxHeap, &maxHeapSize);
        while (visited[largest.idx]) {
            largest = extractMax(maxHeap, &maxHeapSize);
            // printf("Checking Largest: [%d]%lld", largest.idx, largest.key);
        }

        // printf("Largest: %lld Smallest: %lld\n", largest.key, smollest.key);

        visited[smollest.idx] = 1;
        visited[largest.idx] = 1;

        Node diff = (Node){.idx = q + n, .key = largest.key - smollest.key};
        
        cum_sum -= smollest.key + largest.key;
        cum_sum += diff.key;

        insertMinHeap(minHeap, &minHeapSize, diff);
        insertMaxHeap(maxHeap, &maxHeapSize, diff);

        printf("%lld\n", cum_sum);
    }



    return 0;
}