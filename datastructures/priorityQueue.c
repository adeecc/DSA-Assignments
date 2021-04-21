#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define N (int)1e5

typedef struct {
    ll key;
    ll priority;
} PQNode;

typedef struct {
    PQNode harr[N];
    int size;
} PriorityQueue;

PriorityQueue *createPQ() {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;

    return pq;
}

void swap(PriorityQueue *pq, int i, int j) {
    PQNode temp = pq->harr[i];
    pq->harr[i] = pq->harr[j];
    pq->harr[j] = temp;
}

void minHeapify(PriorityQueue *pq, int i) {
    if (pq->size == 1) return;
    if (i >= pq->size / 2) return;

    int smolest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (pq->size > l && pq->harr[l].priority < pq->harr[smolest].priority)
        smolest = l;
    if (pq->size > r && pq->harr[r].priority < pq->harr[smolest].priority)
        smolest = r;

    if (smolest != i) {
        swap(pq, i, smolest);
        minHeapify(pq, smolest);
    }
}

void insert(PriorityQueue *pq, ll key, ll priority) {
    if (!pq->size) {
        pq->harr[pq->size++] = (PQNode){.key = key, .priority = priority};
        return;
    }

    pq->harr[pq->size++] = (PQNode){.key = key, .priority = priority};

    for (int i = pq->size / 2 - 1; i >= 0; --i) {
        minHeapify(pq, i);
    }
}

ll getTop(PriorityQueue *pq) {
    if (!pq->size) return -1;

    ll key = pq->harr[0].key;

    if (pq->size > 1) {
        pq->harr[0] = pq->harr[pq->size - 1];
        minHeapify(pq, 0);
    }

    pq->size--;
    return key;
}

int main() {
    PriorityQueue *pq = createPQ();

    insert(pq, 3, 1);
    insert(pq, 2, 5);
    insert(pq, 7, 1);
    insert(pq, 1, 2);
    insert(pq, 2, 3);
    insert(pq, 26, 6);
    insert(pq, 3, 1);
    insert(pq, 5, 9);
    insert(pq, 22, 5);
    insert(pq, 4, 4);

    /*
    Correct Order
        insert(pq, 3, 1);
        insert(pq, 7, 1);
        insert(pq, 3, 1);
        insert(pq, 1, 2);
        insert(pq, 2, 3);
        insert(pq, 4, 4);
        insert(pq, 2, 5);
        insert(pq, 22, 5);
        insert(pq, 26, 6);
        insert(pq, 5, 9);
    */

    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));
    printf("%lld ", getTop(pq));

    return 0;
}