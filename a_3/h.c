#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <limits.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

#define INF (int)1e10

#define MIN(x, y) (x) > (y) ? (y) : (x)

int main() {
    int a, p, c;
    scanf("%d %d %d", &a, &p, &c);

    uint32_t authors[p], inDegree[p], citation, hIndex[a];

    memset(inDegree, 0, sizeof(inDegree));
    memset(hIndex, INF, sizeof(hIndex));

    for (size_t i = 0; i < p; i++) {
        scanf("%d", authors + i);
    }

    for (size_t i = 0; i < c; i++) {
        scanf("%*d %d", &citation);
        inDegree[citation]++;
    }

    int currentAuthor;

    for (size_t i = 0; i < p; i++) {
        // hIndex[authors[i]] = MIN(hIndex[authors[i]], inDegree[i]);

        currentAuthor = authors[i];
        if (hIndex[currentAuthor] > inDegree[i]) {
            hIndex[currentAuthor] = inDegree[i];
        }
    }

    for (size_t i = 0; i < a; i++) {
        printf("%u ", hIndex[i]);
    }

    return 0;
}