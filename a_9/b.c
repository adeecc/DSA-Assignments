#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 100001

int main() {
    ll n;
    ll x;
    scanf("%lld", &n);

    int frequencyArray[N] = {0};

    int discarded = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        if (x > n) {
            discarded++;
        } else {
            frequencyArray[x]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (frequencyArray[i] == i) continue;
        if (frequencyArray[i] < i) discarded += frequencyArray[i];
        if (frequencyArray[i] > i) discarded += (frequencyArray[i] - i);
    }

    printf("%d", discarded);

    return 0;
}