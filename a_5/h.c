#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N (int)(1e5)

ll leftHeap[N];   // Max Heap
ll rightHeap[N];  // Min Heap
int leftSize = 0, rightSize = 0;

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(ll i) {
    if (rightSize == 1) return;
    if (i >= rightSize / 2) return;

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < rightSize && rightHeap[left] < rightHeap[smallest])
        smallest = left;

    if (right < rightSize && rightHeap[right] < rightHeap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(rightHeap + i, rightHeap + smallest);
        minHeapify(smallest);
    }
}

void maxHeapify(ll i) {
    if (leftSize == 1) return;
    if (i >= leftSize / 2) return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < leftSize && leftHeap[left] > leftHeap[largest]) largest = left;

    if (right < leftSize && leftHeap[right] > leftHeap[largest])
        largest = right;

    if (largest != i) {
        swap(leftHeap + i, leftHeap + largest);
        maxHeapify(largest);
    }
}

void minHeapInsert(ll key) {
    if (rightSize == 0) {
        rightHeap[rightSize++] = key;
        return;
    }

    rightHeap[rightSize++] = key;

    for (int i = rightSize / 2 - 1; i >= 0; --i) minHeapify(i);
}

void maxHeapInsert(ll key) {
    if (leftSize == 0) {
        leftHeap[leftSize++] = key;
        return;
    }

    leftHeap[leftSize++] = key;

    for (int i = leftSize / 2 - 1; i >= 0; --i) maxHeapify(i);
}

ll getTop(ll harr[], int size) {
    if (size <= 0) return -1;
    return harr[0];
}

ll extractMin() {
    if (rightSize <= 0) return -1;

    if (rightSize == 1) {
        rightSize--;
        return rightHeap[0];
    }

    ll key = rightHeap[0];
    rightHeap[0] = rightHeap[rightSize - 1];
    rightSize--;
    minHeapify(0);

    return key;
}

ll extractMax() {
    if (leftSize <= 0) return -1;

    if (leftSize == 1) {
        leftSize--;
        return leftHeap[0];
    }

    ll key = leftHeap[0];
    leftHeap[0] = leftHeap[leftSize - 1];
    leftSize--;
    maxHeapify(0);

    return key;
}

void printHeap(ll harr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("%lld ", harr[i]);
    }

    printf("\n");
}

// Max heap on Left, Min Heap on right
ll getMedian(ll e, ll *m) {
    if (leftSize > rightSize) {
        if (e < *m) {
            ll el = extractMax();
            minHeapInsert(el);
            maxHeapInsert(e);
        } else {
            minHeapInsert(e);
        }

        *m = (getTop(leftHeap, leftSize) + getTop(rightHeap, rightSize)) / 2;

    }

    else if (leftSize == rightSize) {
        if (e < *m) {
            maxHeapInsert(e);
            *m = getTop(leftHeap, leftSize);
        } else {
            minHeapInsert(e);
            *m = getTop(rightHeap, rightSize);
        }
    }

    else {
        if (e < *m) {
            maxHeapInsert(e);
        } else {
            ll el = extractMin();
            maxHeapInsert(el);
            minHeapInsert(e);
        }

        *m = (getTop(leftHeap, leftSize) + getTop(rightHeap, rightSize)) / 2;
    }

    return *m;
}

int main() {
    int n;
    scanf("%d", &n);

    ll leftHeap[N], rightHeap[N], e, m = 0;
    int leftSize = 0, rightSize = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &e);
        getMedian(e, &m);
        printf("%lld ", m);
    }

    return 0;
}