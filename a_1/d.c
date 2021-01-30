#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t m, n, prices[25], max = 0, temp;

int quantFromSubset(uint16_t combination) {
    uint32_t count = 0, total = 0;
    for (int i = 0; i < n; ++i) {
        total += (combination & 1) * prices[i];
        count += (combination & 1);

        combination >>= 1;
    }
    
    return total > m ? 0 : count;
}

int main() {
    
    scanf("%d%*c%d", &m, &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%*c", prices + i);
    }

    for (int i = 0; i < (1 << n); ++i) {
        temp = quantFromSubset(i);

        if (temp > max) {
            max = temp;
        }
    }

    
    printf("%d", max);

    return 0;
}
