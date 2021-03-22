#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

ll totalWatermelons(int n, ll t[n], ll time) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += time / t[i];
    }

    return sum;
}

ll solution(int n, ll k, ll t[n], ll min_time, ll max_time) {
    // printf("[min_time]: %lld [max_time]: %lld", min_time, max_time);
    if (min_time < max_time) {
        ll mid = (min_time + max_time) / 2;

        ll watermelons = totalWatermelons(n, t, mid);

        if (watermelons == k) return mid;

        if (watermelons < k)
            return solution(n, k, t, mid, max_time);

        if (watermelons > k)
            return solution(n, k, t, min_time, mid);
    }
}

int main() {
    int n;
    ll k;  // Watermelon
    scanf("%d %lld", &n, &k);

    ll t[n];  // Seconds/Watermelon
    for (size_t i = 0; i < n; ++i) {
        scanf("%lld", t + i);
    }

    ll min_time = k / t[0], max_time = k * t[0], temp;

    for (int i = 0; i < n; i++) {
        temp = k * t[i];  // Watermelon^2/second

        if (temp > max_time) {
            max_time = temp;
        }

        // if (temp < min_time) {
        //     min_time = temp;
        // }
    }

    ll time = solution(n, k, t, 0, max_time);
    // printf("[min_time]: %lld [max_time]: %lld", min_time, max_time);
    printf("%lld", time);

    return 0;
}