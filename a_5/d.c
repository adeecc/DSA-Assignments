#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

int main() {
    int m;
    scanf("%d", &m);

    ll Q[m];

    for (size_t i = 0; i < m; i++) {
        scanf("%lld", Q + i);
    }

    ll minElement = 1e9 + 1, maxElement = -1, minCount = 0, maxCount = 0;

    for (int i = 0; i < m; i++) {
        if (Q[i] < minElement) {
            minElement = Q[i];
            minCount = 1;
        }

        else if (Q[i] == minElement) {
            ++minCount;
        }

        if (Q[i] > maxElement) {
            maxElement = Q[i];
            maxCount = 1;
        }

        else if (Q[i] == maxElement) {
            ++maxCount;
        }
    }

    printf("%lld %lld", maxElement - minElement, minCount * maxCount);

    return 0;
}