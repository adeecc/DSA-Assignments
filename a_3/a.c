#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
 
int main() {
    int32_t n, m, k;
    scanf("%d %d %d", &n, &m, &k);
 
    int32_t A[n], S[m], satisfied = 0;
 
    for (size_t i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
 
    for (size_t i = 0; i < m; i++) {
        scanf("%d", S + i);
    }
 
    qsort(A, n, sizeof(int32_t), cmpfunc);
    qsort(S, m, sizeof(int32_t), cmpfunc);

    int32_t i = 0, j = 0;
 
    while (i < n && j < m) {
        int32_t diff = S[j] - A[i];
 
        if (diff <= k && diff >= -k) {
            i++;
            j++;
            satisfied++;
        } else if (diff < -k)
            j++;
        else
            i++;
    }
 
    printf("%d", satisfied);
 
    return 0;
}
