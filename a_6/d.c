#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    int S[n], R[k], oneHot[n];

    for (size_t i = 0; i < n; ++i) {
        scanf("%d", S + i);
        oneHot[i] = 1;
    }

    for (size_t i = 0; i < k; ++i) {
        scanf("%d", R + i);
        oneHot[R[i]] = 0;
    }

    int primary = S[0] * oneHot[0], cumSum[n];
    cumSum[0] = S[0] * !oneHot[0];

    for (int i = 1; i < n; ++i) {
        if (oneHot[i]) {
            primary += S[i];
            cumSum[i] = cumSum[i - 1];
        } else {
            cumSum[i] = cumSum[i - 1] + S[i];
        }
    }

    int max_fed = 0;

    for (int i = 0; i < k; ++i) {
        int final = R[i] + x - 1;
        if (final >= n) {
            final = n - 1;
        }

        int fed;
        if (R[i] == 0)
            fed = cumSum[final];
        else
            fed = cumSum[final] - cumSum[R[i] - 1];

        if (fed > max_fed) max_fed = fed;
    }

    printf("%d %d", primary, primary + max_fed);

    return 0;
}