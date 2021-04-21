#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define N 10001

ll harr[N];
int size = 0;

int frq[N] = {0};

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int i) {
    if (size == 1) return;
    if (i >= size / 2) return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && harr[left] > harr[largest]) largest = left;
    if (right < size && harr[right] > harr[largest]) largest = right;

    if (largest != i) {
        swap(harr + i, harr + largest);
        maxHeapify(largest);
    }
}

void insert(ll key) {
    harr[size++] = key;
    for (int i = size / 2 - 1; i >= 0; --i) {
        maxHeapify(i);
    }
}

ll getMaxFromHarr() {
    if (!size) return -1;

    ll key = harr[0];

    if (size > 1) {
        harr[0] = harr[size - 1];
        maxHeapify(0);
    }

    size--;
    return key;
}

int main() {
    int n;
    scanf("%d", &n);

    ll x;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);

        if (x & 1) continue;  // literally skip all odd numbers

        if (frq[x])
            continue;  // Skip all elements that already exist in the heap

        insert(x);
        frq[x]++;
    }

    int steps = 0;

    while (size) {
        steps++;

        x = getMaxFromHarr();
        // printf("Received: %lld\n", x);
        frq[x]--;

        x /= 2;

        if (x & 1) continue;

        if (frq[x]) {
            // printf("Skipped Inserting: %lld (Already in Harr)\n", x);
            continue;
        }

        // printf("Inserting into harr: %lld\n", x);

        insert(x);
        frq[x]++;
    }

    printf("%d", steps);
}