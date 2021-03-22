#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 10001

char str[N], res[N];

int reverseStr(int i, int j) {
    int n_by_2 = (j - i + 1) / 2;

    assert(n_by_2 >= 0);

    char temp;

    for (int k = 0; k < n_by_2; k++) {
        temp = res[i + k];
        res[i + k] = res[j - k];
        res[j - k] = temp;
    }
}

int incrementStr(int i, int j) {
    int n = j - i + 1;

    assert(n >= 0);

    for (int k = 0; k < n; ++k) {
        res[i + k]++;
    }
}

void paranthesisSR(int i) {}

void solution() {
    int pStack[N], bStack[N];
    int pTop = -1, bTop = -1;

    int j, size = 0;

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        switch (str[i]) {
            case '(':
                pStack[++pTop] = size;
                break;
            case ')':
                j = pStack[pTop--];
                reverseStr(j, size - 1);
                break;
            case '[':
                bStack[++bTop] = size;
                break;
            case ']':
                j = bStack[bTop--];
                incrementStr(j, size - 1);
                break;

            default:
                res[size++] = str[i];
                break;
        }
    }
}

int main() {
    scanf("%s%*c", str);

    solution();

    printf("%s", res);

    return 0;
}