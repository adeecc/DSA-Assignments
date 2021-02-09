#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const uint64_t MOD = 1e9 + 7;

int main() {
    uint32_t n, m;
    scanf("%d %d%*c", &n, &m);

    uint64_t P[n], A[m];

    for (size_t i = 0; i < n; i++) scanf("%ld%*c", P + i);

    for (size_t i = 0; i < m; i++) scanf("%ld%*c", A + i);

    for (size_t i = 0; i < n - m + 1; i++)

        for (size_t j = 0; j < m; j++) P[i + j] = (A[j] * P[i + j]) % MOD;

    for (size_t i = 0; i < n; i++) printf("%ld ", P[i]);

    return 0;
}