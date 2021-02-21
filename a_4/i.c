/*

Source: https://codeforces.com/blog/entry/84024

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

#define N 1000
const int MOD = 1e9 + 7;

ll fact[N] = {1LL};
ll inv[N]  = {1LL};

int binPow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
 
        n >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k > n) return 0;

    int product = (1ll * fact[n] * inv[k]) % MOD;
    product = (1LL * product * inv[n - k]) % MOD;
    return product;
}

void binarySearch(int n, int pos, int *numBig, int *numSmol) {
    int l = 0, r = n, mid;

    while (l < r) {
        mid = (l + r) * 0.5f;

        if (pos >= mid) {
            if (pos != mid) (*numSmol)++;
            l = mid + 1;
        } else {
            (*numBig)++;
            r = mid;
        }
    }
}

int main() {
    int n, x, pos;
    scanf("%d %d %d", &n, &x, &pos);

    for (int i = 1; i <= n; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        inv[i]  = binPow(fact[i], MOD - 2);
    }

    int numBig = 0, numSmol = 0;

    binarySearch(n, pos, &numBig, &numSmol);

    int other = (n - numBig - numSmol - 1);
    int bigRange = n - x, smolRange = x - 1;

    int countBig  = (1LL * C(bigRange, numBig) * fact[numBig]) % MOD;
    int countSmol = (1LL * C(smolRange, numSmol) * fact[numSmol]) % MOD;

    int res = (1LL * countBig * countSmol) % MOD;
    res = (1LL * res * fact[other]) % MOD;

    ll ans = 0;
    ans = (ans + res) % MOD;

    printf("%ld", ans);

    return 0;
}