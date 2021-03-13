#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 1000 //  ((int)1e5 + 1)
const int MOD = 1e9 + 7;

ull harr[N];
int size = 0;

void swap(ull *a, ull *b) {
    ull temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeapify(int i) {
    if (size == 1) return;
    if (i >= size / 2) return;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && harr[left] > harr[largest])
        largest = left;

    if (right < size && harr[right] > harr[largest])
        largest = right;
    
    if (largest != i) {
        swap(harr + i, harr + largest);
        maxHeapify(largest);
    }
}

void insert(ull key) {
    if (!size)  {
        harr[size++] = key;
        return;
    }

    harr[size++] = key;

    for (int i = size / 2 - 1; i >= 0; --i) maxHeapify(i);
}

ull getMax() {
    if (!size) return -1;

    ull key = harr[0];

    if (size > 1) {
        harr[0] = harr[size - 1];
        maxHeapify(0);
    }

    size--;
    return key;
}

void printharr() {
    for (int i = 0; i < size; ++i)
        printf("%lld\n", harr[i]);
}

ull getSum(char str[151]) {
    ull sum = 0;
    size_t n = strlen(str);

    assert(n > 0);

    ull num = 0, factor = 1;

    int state = 0;

    /*
        state = 0: Number has not started
        state = 1: Writing a number rn
    */

    for (int i = n - 1; i >= 0; --i) {
        int c = str[i] - '0';

        if (state == 0) {
            if (c < 10) {
                state = 1;
                num += c * factor;
                factor *= 10;
            }
        } else {
            if (c < 10) {
                num += c * factor;
                factor *= 10;
            } else {
                state = 0;
                sum = (sum + num);
                factor = 1;
                // printf("Final Number: %lld\n", num);
                num = 0;
            }
        }
    }

    if (state == 1) {
        state = 0;
        sum = (sum + num);
        factor = 1;

        // printf("Final Number: %lld\n", num);

        num = 0;
    }

    return sum;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char strings[n][151];

    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    for (int i = 0; i < n; i++) {
        ull numSum = (getSum(strings[i]));
        // printf("Found Sum: %lld\n", numSum);
        insert(numSum);
    }

    ull sum = 0;

    for (int i = 0; i < k; ++i) {
        sum = (sum + getMax()) % MOD;
    }

    printf("%lld", sum);

    return 0;
}