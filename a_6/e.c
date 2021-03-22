#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N (int)1e7
typedef struct {
    int idx;
    float x, y;
    ll n;
} Pair;

Pair points[N];
int size = 0;

int cmpfunc(const Pair a, const Pair b) { 
    if (a.n == b.n) {
        return a.idx - b.idx;
    }

    return a.n - b.n;
}

void swap(int i, int j) {
    Pair temp = points[i];
    points[i] = points[j];
    points[j] = temp;
}

void minHeapify(int i) {
    if (size == 1) return;
    if (i >= size / 2) return;

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && cmpfunc(points[left], points[smallest]) < 0)
        smallest = left;

    if (right < size && cmpfunc(points[right], points[smallest]) < 0)
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        minHeapify(smallest);
    }
}

void buildHeap() {
    for (int i = size / 2 - 1; i >= 0; --i) {
        minHeapify(i);
    }
}

void extractMin() {
    if (size <= 0) return;

    printf("%d", points[0].idx);
    // printf("[%d] %f %f %lld", points[0].idx, points[0].x, points[0].y, points[0].n);


    if (size == 1) {
        size--;
        return;
    }

    points[0] = points[size-1];
    size--;
    minHeapify(0);
}

int main() {
    int n, c, d, k;
    scanf("%d %d %d %d", &n, &c, &d, &k);

    int xBucket[c], yBucket[d];

    for (int i = 0; i < c; i++) xBucket[i] = 0;

    for (int i = 0; i < d; i++) yBucket[i] = 0;

    float x, y;

    for (size_t i = 0; i < n; ++i) {
        scanf("%f %f", &x, &y);

        points[i] = (Pair){.idx = i, .x = x, .y = y};
        xBucket[(int)x]++;
        yBucket[(int)y]++;
    }

    size = n;

    for (int i = 0; i < n; ++i) {
        points[i].n = xBucket[(int)points[i].x] * yBucket[(int)points[i].y];
    }

    buildHeap();

    for (int i = 0; i < k - 1; i++) {
        extractMin();
        printf(" ");
    }

    extractMin();

    return 0;
}