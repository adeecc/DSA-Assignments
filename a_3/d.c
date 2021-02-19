#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t


int main() {
    int n, k1, k2;
    scanf("%d %d %d", &n, &k1, &k2);

    int X[n], Y[n], diff = k1 - k2;

    for (size_t i = 0; i < n; i++) {
        scanf("%d", X + i);
    }

    for (size_t i = 0; i < n; i++) {
        scanf("%d", Y + i);
    }

    ll count;
        
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (X[i] + X[j] + diff > Y[i] + Y[j]) {
                count++;


            }
        }
        
    }
    
    printf("%ld", count);

    return 0;
}