#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

typedef struct {
    int idx;
    int diff, a;
} Amp;

int cmpfunc(const void* a, const void* b) {
    return ((*(Amp*)a).diff - (*(Amp*)b).diff);
}

int getLeftSum(int n, int cum_sums[], int mid) {    
    return cum_sums[mid - 1];
}

int getRightSum(int n, int cum_sums[], int mid) {
    return cum_sums[n - 1] - cum_sums[mid - 1];
}

int binarySearchOverSum(int n, int cum_sums[], int start, int end) {
    if (end >= start) {
        int mid = (start + end) * 0.5f;

        int leftSum = getLeftSum(n, cum_sums, mid);
        int rightSum = getRightSum(n, cum_sums, mid);

        if (leftSum == rightSum) return mid;

        if (leftSum > rightSum)
            return binarySearchOverSum(n, cum_sums, start, mid - 1);

        if (leftSum < rightSum)
            return binarySearchOverSum(n, cum_sums, mid + 1, end);
    }

    return -1;
}

void solution(int isLast) {
    int n, x, y, a;
    scanf("%d", &n);

    Amp amps[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &a);
        amps[i] = (Amp){.idx = i, .diff = y - x, .a = a};
    }

    qsort(amps, n, sizeof(Amp), cmpfunc);

    int cum_sums[n];
    cum_sums[0] = amps[0].a;

    for (int i = 1; i < n; i++) {
        cum_sums[i] = amps[i].a + cum_sums[i - 1];
    }

    if (binarySearchOverSum(n, cum_sums, 0, n) > 0)
        printf("YES");
    else
        printf("NO");

    if (!isLast) 
        printf("\n");    
}

int main() {
    int t;
    scanf("%d", &t);

    for (size_t i = 0; i < t; i++) solution(i == t - 1);

    return 0;
}