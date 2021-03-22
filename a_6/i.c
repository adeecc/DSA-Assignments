#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

/*

                |
                |
        3       2        1
                |
                |
--------4----------------0-------
                |
                |
        5       6        7
                |
                |

*/

typedef struct {
    int idx;
    int x, y;
    float m;
} Pair;

Pair hero;

int getQuad(ll x, ll y) {
    // if (x > 0 && y == 0) return 0;
    if (x > 0 && y > 0) return 1;
    if (x == 0 && y > 0) return 2;
    if (x < 0 && y > 0) return 3;
    // if (x < 0 && y == 0) return 4;
    // if (x < 0 && y < 0) return 5;
    // if (x == 0 && y < 0) return 6;
    // if (x < 0 && y > 0) return 7;
}

// Return < 0: a < b, == 0: a == b,  > 0: a > b

int cmpfunc(const void* a, const void* b) {
    Pair p = *(Pair*)a, q = *(Pair*)b;

    return (q.m - p.m) > 0 ? 1 : -1; 
}

int main() {
    int n;
    scanf("%d", &n);

    n = n - 1;

    Pair points[n];

    int minY = 1e6, minYIdx = -1;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &points[i].idx, &points[i].x, &points[i].y);

        if (points[i].y < minY) {
            minYIdx = i;
            minY = points[i].y;
        }
    }

    scanf("%d %d %d", &hero.idx, &hero.x, &hero.y);

    if (hero.y > minY) {
        Pair temp = hero;
        hero = points[minYIdx];
        points[minYIdx] = temp;
    }

    // printf("Hero: [%d] %d %d\n\n", hero.idx, hero.x, hero.y);

    // Translating to reference frame with hero as origin
    for (int i = 0; i < n; i++) {
        points[i].x -= hero.x;
        points[i].y -= hero.y;
        points[i].m = (float)points[i].x / (float)points[i].y;
    }

    qsort(points, n, sizeof(Pair), cmpfunc);

    for (int i = 0; i < n; i++) {
        printf("%d ", points[i].idx);
        // printf("[%d]: (%.3f) (%d, %d)\n", points[i].idx, points[i].m, points[i].x, points[i].y);

    }

    return 0;
}