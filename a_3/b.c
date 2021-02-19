#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    uint32_t n, m;
    scanf("%d %d", &n, &m);

    int32_t A[n], B[m], G[m];

    for (size_t i = 0; i < n; i++) {
        scanf("%d", A + i);
    }

    for (size_t i = 0; i < m; i++) {
        scanf("%d %d", B + i, G + i);
    }

    uint32_t monis;

    for (size_t i = 0; i < n; ++i) {   
        monis = 0;
        for (size_t j = 0; j < m; ++j) {
            if (A[i] >= B[j]) {
                monis += G[j];
            }
        }

        printf("%d ", monis);
    }
    

    return 0;
}