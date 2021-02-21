// Based on Solution by Nandan H R.

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

int Quadrant(Point p) {
    if (p.y == 0) {
        if (p.x > 0)
            return 1;
        else
            return 5;
    } else if (p.y > 0) {
        if (p.x > 0)
            return 2;
        else if (p.x == 0)
            return 3;
        else
            return 4;
    } else {
        if (p.x < 0)
            return 6;
        else if (p.x == 0)
            return 7;
        else
            return 8;
    }
}

int cmpfunc(const void* a, const void* b) {
    Point p = *((Point*)a), q = *((Point*)b);

    if ((p.x) * (q.x) > 0 && (p.y) * (q.y) > 0)
        return (p.y * q.x - q.y * p.x);
    else
        return Quadrant(p) - Quadrant(q);
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

    qsort(points, n, sizeof(Point), cmpfunc);

    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += manhattanDistance(points[i % n], points[(i + 1) % n]);
    }

    printf("%ld", sum);

    return 0;
}