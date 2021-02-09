#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define N (uint32_t)1e5

void printAll(char *set, char* prefix, int n, int k) {

    if (!k) {
        printf("%s\n", prefix);
        return;
    }

    for (int i = 0; i < n; ++i) {
        char newPrefix[N] = {0};
        newPrefix[0] = set[i];

        strcat(newPrefix, prefix);

        printAll(set, newPrefix, n, k - 1);
    }
}

int main() {
    uint32_t n, k;
    scanf("%d %d", &n, &k);

    char s[n];
    scanf("%s%*c", s);

    printAll(s, "", n, k);
    
    return 0;
}