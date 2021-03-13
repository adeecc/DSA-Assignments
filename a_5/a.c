#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N ((int)1e5)

typedef struct {
    int idx;
    ll P, E;
} Task;

int size = 0;
Task harr[N];

int taskLT(Task l, Task r) {
    if (l.P < r.P) return 1;

    if (l.P > r.P) return 0;

    if (l.E < r.E) return 1;

    return 0;
}

void swap(Task *a, Task *b) {
    Task temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int i) {
    if (size == 1) return;

    if (i >= size / 2) return;

    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // if (l < size && taskLT(harr[l], harr[i])) smallest = l;
    // if (r < size && taskLT(harr[r], harr[smallest])) smallest = r;

    if (l < size) smallest = taskLT(harr[l], harr[i]) ? l : i;

    if (r < size) smallest = taskLT(harr[r], harr[smallest]) ? r : smallest;

    if (smallest != i) {
        swap(harr + i, harr + smallest);
        heapify(smallest);
    }
}

void insert(Task task) {
    if (!size) {
        harr[size++] = task;
        return;
    }

    harr[size++] = task;

    for (int i = size / 2 - 1; i >= 0; i--) heapify(i);
}

void buildMinHeap() {
    int i = (size - 1) / 2;
    while (i >= 0) {
        heapify(i);
        i--;
    }
}

Task extractMin() {
    if (!size) return (Task){.idx = -1, .E = -1, .P = -1};

    Task root = harr[0];

    if (size > 1) {
        harr[0] = harr[size - 1];
        heapify(0);
    }

    size--;
    return root;
}

void printharr() {
    for (int i = 0; i < size; ++i)
        printf("[%d] %lld %lld\n", harr[i].idx, harr[i].P, harr[i].E);
    printf("\n");
}

int main() {
    ll t, k, e, p;
    scanf("%lld %lld", &t, &k);

    Task task;

    for (size_t i = 0; i < t; i++) {
        scanf("%lld %lld", &e, &p);
        task = (Task){.idx = i, .E = e, .P = p};

        insert(task);
    }

    for (int i = 0; i < k; i++) {
        task = extractMin();
        printf("%d ", task.idx);
    }

    return 0;
}