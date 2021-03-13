#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

void merge(char N[201], char M[201]) {
    char damnlong[401];

    int n = strlen(N);
    int m = strlen(M);

    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
        if (N[i] > M[j])
            damnlong[k++] = N[i++];
        else
            damnlong[k++] = M[j++];

    while (i < n) damnlong[k++] = N[i++];

    while (j < m) damnlong[k++] = M[j++];

    damnlong[k] = '\0';

    printf("%s", damnlong);
}

int main() {
    char N[201], M[201];

    scanf("%s%*c%s", N, M);

    merge(N, M);

    return 0;
}