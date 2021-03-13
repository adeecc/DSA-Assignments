#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 1000
const int MOD = 1e9 + 7;

ll harr[N];
int size = 0;

void swap(ll *a, ll *b) {
    ll temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeapify(int i) {
    if (size == 1) return;
    if (i >= size / 2) return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && harr[left] > harr[largest])
        largest = left;

    if (right < size && harr[right] > harr[largest])
        largest = right;
    
    if (largest != i) {
        swap(harr + i, harr + largest);
        maxHeapify(largest);
    }
}

void insert(ll key) {
    if (!size)  {
        harr[size++] = key;
        return;
    }

    harr[size++] = key;

    for (int i = size / 2 - 1; i >= 0; --i) maxHeapify(i);
}

ll getMax() {
    if (!size) return -1;

    ll key = harr[0];

    if (size > 1) {
        harr[0] = harr[size - 1];
        maxHeapify(0);
    }

    size--;
    return key;
}

void printharr() {
    for (int i = 0; i < size; ++i)
        printf("%lld\n", harr[i]);
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll arr[n];

    for (size_t i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }
    
    for (int i = 1; i < n; ++i) {
        insert(arr[i] - arr[i - 1]);
    }
    
    // printharr();

    for (int i = 0; i < k; i++)
    {
        int key = getMax();
        int l = key / 2;
        int r = key - l;

        insert(l);
        insert(r);
    }
    
    printf("%lld", getMax());
    return 0;
}