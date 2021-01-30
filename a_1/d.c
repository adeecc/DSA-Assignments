#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int increasing_compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    uint32_t m, n, prices[25], count = 0, total = 0;

    scanf("%d%*c%d", &m, &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%*c", prices + i);
    }

    qsort(prices, n, sizeof(uint32_t), increasing_compare);

    for (int i = 0; i < n; ++i) {
        total += prices[i];

        if (total <= m)
            count++;
        else
            break;
    }

    printf("%d\n", count);

    return 0;
}
