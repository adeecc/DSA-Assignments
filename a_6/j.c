#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

ll binarySearch(ll l, ll r, ll n) {
    ll result;

    // printf("l: %lld r: %lld\n", l, r);

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll cubed = mid * mid * mid;

        if (cubed == n)
            return mid;

        else if (cubed < n) {
            l = mid + 1;
            result = mid;
        }

        else {
            r = mid - 1;
        }

        // printf("l: %lld r: %lld\n", l, r);
    }

    return result;
}

int main() {
    ll n;
    scanf("%lld", &n);

    ll cRoot;

    if (n > 0)
        cRoot = binarySearch(0, n, n);
    else
        cRoot = -binarySearch(0, -n, -n);

    printf("%lld", cRoot);

    return 0;
}