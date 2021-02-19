#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
 
int main() {
    uint32_t n, m, k;
    scanf("%d %d %d", &n, &m, &k);
 
    uint32_t A[n], S[m], satisfied = 0;
 
    for (size_t i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
 
    for (size_t i = 0; i < m; i++) {
        scanf("%d", S + i);
    }
 
    qsort(A, n, sizeof(uint32_t), cmpfunc);
    qsort(S, m, sizeof(uint32_t), cmpfunc);
 
    uint32_t front = 0;
 
    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = front; j < m; ++j) {
            int32_t diff = A[i] - S[j];
            if (diff <= k || diff >= -k) {
                // printf("i: %d, j: %d\n", i, j);
                satisfied++;
                front = j + 1;
                break;
            }
        }
    }
 
    printf("%d", satisfied);
 
    return 0;
}