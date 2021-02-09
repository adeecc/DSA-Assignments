#include <stdio.h>
#include <stdint.h>

uint64_t f(uint32_t x) {
    int32_t div1 = -1, div2 = -1;

    for (int i = x - 1; i > 1; --i) {
        if (x % i == 0) {
            if (div1 == -1) {
                div1 = i;
            } else {
                div2 = i;
                break;
            }
        }
    }

    if (div1 > 0 && div2 > 0) {
        return f(div1) + f(div2);
    } else {
        return x;
    }
}

int main() {
    uint32_t n;
    scanf("%d", &n);

    /* code */
    printf("%ld", f(n));

    return 0;
}