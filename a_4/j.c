#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

const int MOD = 1e9 + 7;

int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int ternarySearch(int arr[], int t, int l, int r) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == t) return mid1;

        if (arr[mid2] == t) return mid2;

        if (t < arr[mid1])
            return ternarySearch(arr, t, l, mid1 - 1);
        else if (t > arr[mid2])
            return ternarySearch(arr, t, mid2 + 1, r);
        else
            return ternarySearch(arr, t, mid1 + 1, mid2 - 1);
    }

    return -1;
}

int main() {
    int n, q, t;
    scanf("%d %d", &n, &q);

    int arr[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), cmpfunc);

    for (int i = 0; i < q; ++i) {
        scanf("%d", &t);
        if (ternarySearch(arr, t, 0, n) > -1) printf("YES");
        else printf("NO");

        if (i != q - 1) printf("\n");
    }

    return 0;
}