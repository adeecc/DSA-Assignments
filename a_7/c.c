#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

ll maxAreaUnderHistogram(int n, int m, ll arr[n][m], int idx) {

    ll stack[m], top = -1;

    ll area, maxArea = 0, tp;

    int i;

    for (i = 0; i < m; ++i) {
        while (top > -1 && arr[idx][stack[top]] >= arr[idx][i]) {
            tp = stack[top--];
            area = arr[idx][tp] * (top < 0 ? i : i - stack[top] - 1);
            if (area > maxArea) {
                maxArea = area;
            }
        };

        stack[++top] = i;
    }

    while (top > -1) {
        tp = stack[top--];

        area = arr[idx][tp] * (top < 0 ? i : i - stack[top] - 1);

        if (area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int loc[n][m];
    ll height[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &loc[i][j]);
        }
    }

    for (int i = 0; i < m; ++i) {
        height[0][i] = loc[0][i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (loc[i][j]) {
                height[i][j] = height[i - 1][j] + 1;
            } else {
                height[i][j] = 0;
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         printf("%d ", height[i][j]);
    //     }
    //     printf("\n");
    // }

    ll area, maxArea = 0;

    for (int i = 0; i < n; ++i) {
        area = maxAreaUnderHistogram(n, m, height, i);

        if (area > maxArea) maxArea = area;

    }

    printf("%lld", maxArea);

    return 0;
}