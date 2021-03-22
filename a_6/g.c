#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 10001

int arr[N];
int n;

int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

int isLeaf(int i) {
    int l = leftChild(i);
    int r = rightChild(i);

    if (l > n || r > n) return TRUE;

    if (arr[l] == -1 && arr[r] == -1) return TRUE;

    return FALSE;
}

int hammingDistance(int a, int b) {
    return __builtin_popcount(a ^ b);
}

void populateChildren(int children[n], int *top, int parent) {
    int l = leftChild(parent);
    int r = rightChild(parent);

    if (isLeaf(parent)) {
        children[++(*top)] = parent;
    } else {
        if (isLeaf(l)) {
            children[++(*top)] = l;
        }

        else {
            populateChildren(children, top, l);
        }

        if (isLeaf(r)) {
            children[++(*top)] = r;
        }

        else {
            populateChildren(children, top, r);
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d %d", &n, &a, &b);

    for (size_t i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    int aIdx = -1, bIdx = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == a) aIdx = i;
        if (arr[i] == b) bIdx = i;
    }

    if (aIdx < 0 || bIdx < 0) {
        printf("-1");
        return 0;
    }

    int childrenA[n], childrenB[n];
    int topA = -1, topB = -1;

    populateChildren(childrenA, &topA, aIdx);
    populateChildren(childrenB, &topB, bIdx);

    // printf("Children of A:\n");

    // for (int i = 0; i < topA + 1; i++) {
    //     printf("%d ", arr[childrenA[i]]);
    // }

    // printf("\n\nChildren of B:\n");

    // for (int i = 0; i < topB + 1; i++) {
    //     printf("%d ", arr[childrenB[i]]);
    // }

    // printf("\n");

    int minDist = 1000;

    for (int i = 0; i < topA + 1; ++i) {
        for (int j = 0; j < topB + 1; ++j) {
            int dist = hammingDistance(arr[childrenA[i]], arr[childrenB[j]]);
            if (dist < minDist) {
                // printf("Using a: %d, b: %d\n", arr[childrenA[i]], arr[childrenB[j]]);
                minDist = dist;
            }
        }
    }

    printf("%d", minDist);
    

    return 0;
}