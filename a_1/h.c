#include <stdio.h>
#include <stdint.h>

#define N 1000

uint32_t n, front, rear;
int64_t arr[N], sq_arr[N], cu_arr[N];

#define DIFF(x, y) ((x) > (y)) ? ((x) - (y)) : ((y) - (x))

int64_t costDifference() {
    int64_t oddSum = 0, evenSum = 0;  

    for (int i = front; i < rear; i = (i + 2)) {
        evenSum += sq_arr[i % n];
    }

    for (int i = front + 1; i < rear; i = (i + 2)) {
        oddSum += cu_arr[i % n];
    }

    return evenSum - oddSum;
}

void nextPermuation() {
    front++;
    rear++;
}

int main() {

    scanf("%d%*c", &n);

    front = 0;
    rear = n;

    for (int i = 0; i < n; ++i) {
        scanf("%ld ", arr + i);

        sq_arr[i] = arr[i] *    arr[i];
        cu_arr[i] = arr[i] * sq_arr[i];
    }


    int64_t minDiff = 1e14, maxDiff = -1e14;
    
    if (n % 2) {
        int64_t tmp;
        for (int i = 0; i < n; ++i) {
            tmp = costDifference();
            nextPermuation();

            if (tmp > maxDiff) {
                maxDiff = tmp;
            } else if (tmp < minDiff) {
                minDiff = tmp;
            }
        }

    } else {
        minDiff = costDifference();
        nextPermuation();
        maxDiff = costDifference();
    }

    printf("%ld\n", DIFF(minDiff, maxDiff));

    return 0;
}