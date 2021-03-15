#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

const ll MOD = 1e9 + 7;

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(ll harr[], int *size, ll i) {
    if (*size == 1) return;
    if (i >= (*size) / 2) return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < (*size) && harr[left] > harr[largest]) largest = left;

    if (right < (*size) && harr[right] > harr[largest]) largest = right;

    if (largest != i) {
        swap(harr + i, harr + largest);
        maxHeapify(harr, size, largest);
    }
}

void insert(ll harr[], int *size, ll key) {
    if ((*size) == 0) {
        harr[(*size)++] = key;
        return;
    }

    harr[(*size)++] = key;

    for (int i = (*size) / 2 - 1; i >= 0; --i) maxHeapify(harr, size, i);
}

ll extractMax(ll harr[], int *size) {
    if ((*size) == 0) return -1;

    ll key = harr[0];

    if ((*size) > 1) {
        harr[0] = harr[(*size) - 1];
        maxHeapify(harr, size, 0);
    }

    (*size)--;
    return key;
}

void printHeap(ll harr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("%lld ", harr[i]);
    }

    printf("\n");
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    ll maxHarr[n], x;
    int size = 0;

    for (size_t i = 0; i < n; i++) {
        scanf("%lld", &x);

        insert(maxHarr, &size, x);
    }


    ll sum = 0;

    for (int i = 0; i < d; i++)
    {
        ll max = extractMax(maxHarr, &size);

        sum = (sum + max) % MOD;

        insert(maxHarr, &size, max / 3);
    }
    
    printf("%lld", sum);

    return 0;
}