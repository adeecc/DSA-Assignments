#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

uint8_t can_place(int m, int X[m], int n, int mid) {
    int count = 1;
    int last_position = X[0];

    for (int i = 1; i < m; i++) {
        if (X[i] - last_position >= mid) {
            last_position = X[i];
            count++;
            if (count == n) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

void find_min_diff(int m, int X[m], int n) {
    int s = 0;
    int e = X[n - 1] - X[0];

    int ans = 0;

    while (s <= e)
    {
        ll mid = (s + e) / 2;

        if (can_place(m, X, n, mid)) {
            ans = mid;

            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    printf("%d", ans);  
} 

int main() {
    int n, m, X[m];
    scanf("%d %d", &n, &m);

    for (size_t i = 0; i < m; ++i) {
        scanf("%d", X + i);
    }

    qsort(X, m, sizeof(int), cmpfunc);

    find_min_diff(m, X, n);

    return 0;
}