#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

#define N (int)1e5

#define _ABS(x) ((x) >= 0 ? (x) : -(x))

typedef struct {
    int idx;
    int x, y;
} Point;

Point points[N];
double angles[N];

int cmpfunc(const void* a, const void* b) {
    double diff = angles[((Point*)a)->idx] - angles[((Point*)b)->idx];
    if (diff == 0) return 0;
    if (diff < 0) return 1;
    if (diff > 0) return -1;
}

ll manhattanDistance(Point u, Point v) {
    int x = u.x - v.x;
    int y = u.y - v.y;
    return _ABS(x) + _ABS(y);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].idx = i;
    }

    for (int i = 0; i < n; i++) {
        angles[i] = atan2(points[i].y, points[i].x);
    }

    qsort(points, n, sizeof(Point), cmpfunc);

    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += manhattanDistance(points[i % n], points[(i + 1) % n]);
    }

    printf("%ld", sum);

    return 0;
}