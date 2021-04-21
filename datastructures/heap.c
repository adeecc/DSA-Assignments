#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define N (int)1e5

typedef struct {
    ll arr[N];
    int size;
} Heap;

void swap(Heap *h, int i, int j) {
    ll temp = h->arr[i];
    h->arr[i] = h->arr[j];
    h->arr[j] = temp;
}

ll get(Heap *h, int i) { return h->arr[i]; }

void maxHeapify(Heap *h, int i) {
    if (h->size == 1) return;
    if (i >= h->size / 2) return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (h->size > left && get(h, left) > get(h, largest)) largest = left;
    if (h->size > right && get(h, right) > get(h, largest)) largest = right;

    if (largest != i) {
        swap(h, largest, i);
        maxHeapify(h, largest);
    }
}

void insert(Heap *h, ll key) {
    if (!h->size) {
        h->arr[(h->size)++] = key;
        return;
    }

    h->arr[(h->size)++] = key;

    for (int i = h->size / 2 - 1; i >= 0; --i) {
        maxHeapify(h, i);
    }
}

ll getMax(Heap *h) {
    if (!h->size) return -1;

    ll key = get(h, 0);

    if (h->size > 1) {
        h->arr[0] = get(h, h->size - 1);
        maxHeapify(h, 0);
    }

    h->size--;
    return key;
}

void printHeap(Heap *h) {
    printf("Current Heap State: ");
    for (int i = 0; i < h->size; i++) {
        printf("%lld ", get(h, i));
    }
    printf("\n");
}

int main() {
    ll arr[] = {9, 5, 3, 4, 5, 6, 2, 4, 5, 7, 3, 5};

    int n = sizeof arr / sizeof(ll);

    Heap *heap = (Heap *)malloc(sizeof(Heap));

    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
        printHeap(heap);
    }

    for (int i = 0; i < n; i++) {
        ll key = getMax(heap);

        printf("Removed: %lld ", key);
        printHeap(heap);
    }

    return 0;
}