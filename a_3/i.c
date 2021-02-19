#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

int insertionSort(int n, int arr[]) {
    int i, key, j;
    for (size_t i = 1; i < n; ++i)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }
}

int div_ceil(int Nr, int Dr) {
    if (Nr == -1 && Dr != -1) {
        return 0;
    }

    div_t res = div(Nr, Dr);
    return res.quot + !!res.rem;
}


int main() {
    int n, m, l, u, v, a, b, k;
    scanf("%d %d %d", &n, &m, &l);
    scanf("%d %d %d %d %d", &u, &v, &a, &b, &k);

    int T[m], C[l];

    for (size_t i = 0; i < m; ++i) {
        scanf("%d", T + i);
    }
    
    for (size_t i = 0; i < l; ++i) {
        scanf("%d", C + i);
    }
    

    insertionSort(m, T);
    insertionSort(l, C);

    // Look for u and v

    size_t u_idx, v_idx;

    // Use binary search?
    for (size_t i = 0; i < m; ++i)
    {
        if (T[i] == u) {
            u_idx = i;
        }

        if (T[i] == v) {
            v_idx = i;
        }
    }
    
    int temp, len = v_idx - u_idx;
    int diff[len];

    // Scaling and translting diff[i] according to 
    for (size_t i = u_idx; i < v_idx; ++i) {
        diff[i - u_idx] = div_ceil(T[i + 1] - T[i] - b, a);
    }

    int cost = 0;

    for (int i = 0; i < len; ++i) {
        // Binary Search and find min element greater than or equal to
        for (int j = 0; j < l; ++j) {
            if (C[j] >= diff[i]) {
                cost += C[j];
                break;
            }
        }
    }

    printf("%d", cost * k);

    return 0;
}