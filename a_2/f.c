#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint32_t fast_log2(uint32_t n) {
    uint16_t k = 0;
    while (n >>= 1) k++;
    return k;
}

int numWays(int n, int k) {
    if (!n || !k) return 1;

    if (1 << k <= n) 
        return numWays(n - (1 << k), k) + numWays(n, k - 1);
    else
        return numWays(n, k - 1);
    
}

int main() {
    uint32_t n;
    scanf("%d", &n);

    printf("%d", numWays(n, fast_log2(n)));    

    return 0;
}