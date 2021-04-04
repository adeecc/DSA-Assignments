// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

ll maxAreaUnderHistogram(int n, ll arr[n]) {

    ll stack[n], top = -1;

    ll area, maxArea = 0, tp;

    // int i = 0;
    // while(i < n) {
    //     if (top < 0 || arr[stack[top]] <= arr[i])
    //         stack[++top] = i++;
    //     else {
    //         tp = stack[top--];

    //         area = arr[tp] * (top < 0 ? i : i - stack[top] - 1);

    //         if (area > maxArea) {
    //             maxArea = area;
    //         }
    //     }
    // }

    // while (top > -1) {
    //     tp = stack[top--];

    //     area = arr[tp] * (top < 0 ? i : i - stack[top] - 1);

    //     if (area > maxArea) {
    //         maxArea = area;
    //     }
    // }

    int i;

    for (i = 0; i < n; ++i) {
        while (top > -1 && arr[stack[top]] >= arr[i]) {
            tp = stack[top--];
            area = arr[tp] * (top < 0 ? i : i - stack[top] - 1);
            if (area > maxArea) {
                maxArea = area;
            }
        };

        stack[++top] = i;
    }

    while (top > -1) {
        tp = stack[top--];

        area = arr[tp] * (top < 0 ? i : i - stack[top] - 1);

        if (area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);

    ll arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", arr + i);
    }


    printf("%lld", maxAreaUnderHistogram(n, arr));

    return 0;
}