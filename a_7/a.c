#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

int main() {
    int n;
    scanf("%d", &n);

    ll arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", arr + i);
    }

    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top > -1 && arr[stack[top]] >= arr[i]) top--;

        if (top < 0)
            printf("-1 ");

        else
            printf("%d ", stack[top] + 1);

        stack[++top] = i;
    }

    return 0;
}