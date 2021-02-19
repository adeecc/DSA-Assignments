#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

#define N (int)1e4 + 1

int main() {
    int n;
    scanf("%d", &n);

    int currentMultiplier = 1, x = 0, newMultiplier, AX;

    int multiplierStack[N] = {0}, top = 0;

    char instr[5];

    for (size_t i = 0; i < n; i++) {
        scanf("%s", instr);

        switch (instr[0]) {
            case 'F':
                scanf("%d", &AX);
                x += (currentMultiplier * AX);
                break;

            case 'L':
                scanf("%d", &newMultiplier);
                multiplierStack[top++] = newMultiplier;
                currentMultiplier *= newMultiplier;
                break;

            case 'E':
                AX = multiplierStack[--top];
                currentMultiplier /= AX;
                break;

            default:
                break;
        }
    }

    printf("%d", x);

    return 0;
}