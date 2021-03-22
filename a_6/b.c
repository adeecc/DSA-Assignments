#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define ull unsigned long long int

#define TRUE 1
#define FALSE 0

#define INF (ll)(1e9 + 1)
#define N 10001

ll stack[N];
int top = -1;

void push(ll key) {
    // printf("Pushing: %lld\n", key);
    stack[++top] = key;
}

ll pop() {
    ll key = stack[top--];
    // printf("Popping: %lld\n", key);
    return key;
}

ll peek() { return stack[top]; }

int notEmpty() { return top > -1; }

int stackSize() { return top + 1; }

void maxSegments(int n, ll arr[n]) {
    push(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (arr[i] >= peek()) {
            push(arr[i]);
        } else {  // arr[i] < stack[top]
            ll last = pop();
            while (notEmpty() && arr[i] < peek()) {
                ll key = pop();
            }

            push(last);
        }
    }

    // for (int i = 0; i < stackSize(); i++) {
    //     printf("%lld ", stack[i]);
    // }

    printf("\n%d", stackSize());
}

int main() {
    int n;
    scanf("%d", &n);

    ll h[n];

    for (size_t i = 0; i < n; ++i) {
        scanf("%lld", h + i);
    }

    maxSegments(n, h);

    return 0;
}