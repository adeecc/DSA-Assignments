#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int main() {
    uint32_t n;
    scanf("%d%*c", &n);

    uint32_t S[n], B, front = 0, rear = n - 1, count = 0;

    for (size_t i = 0; i < n; i++) scanf("%d%*c", S + i);

    scanf("%d%*c", &B);

    qsort(S, n, sizeof(int), cmpfunc);

    while (front <= rear) {
        if (S[front] + S[rear] <= B) {
            count++;
            front++;
            rear--;
        } else {
            rear--;
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
