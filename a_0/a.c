#include <stdio.h>

int main() {
    char A[1000] = {0}, B[1000] = {0}, C[1001] = {0};
    scanf("%s%*c%s", A, B);

    int a = 0, b = 0, c = 0;

    for (a = 0; A[a]; ++a)
        ;
    for (b = 0; B[b]; ++b)
        ;

    int carry = 0, sum = 0, i;

    for (i = 1; A[a - i] && B[b - i]; ++i) {
        sum = carry + A[a - i] - '0' + B[b - i] - '0';

        C[c++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (A[a - i]) {
        sum = carry + A[a - i] - '0';

        C[c++] = (sum % 10) + '0';
        carry = sum / 10;

        i++;
    }

    if (carry) {
        C[c++] = carry + '0';
    }

    
    for (int i = c - 1; i >= 0; --i) {
        printf("%c", C[i]);
    }

    // printf("\n");

    return 0;
}