#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 1001

int n, ctr = 0;
int preIndex = 0;

int search(int in[], int inStart, int inEnd, int key) {
    int i;
    for (i = inStart; i < inEnd; ++i) {
        if (in[i] == key) return i;
    }
    return i;
}

void printPost(int in[], int pre[], int inStart, int inEnd) {
    if (inStart > inEnd) return;

    int inIdx = search(in, inStart, inEnd, pre[preIndex++]);

    printPost(in, pre, inStart, inIdx - 1);

    printPost(in, pre, inIdx + 1, inEnd);

    ctr++;

    if (ctr < n)
        printf("%d ", in[inIdx]);

    else
        printf("%d", in[inIdx]);
}

int main() {
    scanf("%d", &n);

    int pre[n], in[n], post[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", in + i);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", pre + i);
    }

    printPost(in, pre, 0, n - 1);

    // Node* root = createTree(n, arr);

    return 0;
}