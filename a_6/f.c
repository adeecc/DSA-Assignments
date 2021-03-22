#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int


int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    ll arr[n];

    for (size_t i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    int front = 0, rear = n - 1, r;
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &r); 

        front = (front + r) % n;
        rear = (rear + r) % n;

        printf("%lld %lld", arr[front], arr[rear]);
        if (i != t - 1) {
            printf("\n");
        }
    }
    

    return 0;
}