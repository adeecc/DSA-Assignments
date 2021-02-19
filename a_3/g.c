#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t


int main() {
    int n, m;
    scanf("%d %d", &m, &n);

    int monis[n], restaurant[m];

    for (size_t i = 0; i < m; i++) {
        scanf("%d", restaurant + i);
    }

    for (size_t i = 0; i < n; i++) {
        scanf("%d", monis + i);
    }
    
    int count;

    for (size_t i = 0; i < n; i++)
    {
        count = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (monis[i] >= restaurant[j]) {
                count++;
            }
        }
        printf("%d ", count);
    }
    

    return 0;
}   