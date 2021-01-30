#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define N 1e6

uint64_t digit_frequency[10] = {0};

void simpleSieve(uint64_t limit, uint8_t prime[]) {

}

void updateDigitFrequency(uint64_t num) {
    while (num) {
        digit_frequency[num % 10]++;
        num /= 10;
    }
}

int isPrime(uint64_t n) {
    int flag = 1;
    for (uint64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main() {
    uint64_t a, b;
    scanf("%ld %ld", &a, &b);

    // Small Optimization.
    // Reduces execution speed by ~half
    // Ignores all even numbers since they are not prime
    for (uint64_t i = a + !(a % 2); i <= b; i += 2) {
        if (isPrime(i)) 
            updateDigitFrequency(i);
    }

    int max_freq = 0, idx = 0;

    for (int i = 0; i < 10; ++i) {
        if (digit_frequency[i] > max_freq) {
            max_freq = digit_frequency[i];
            idx = i;
        }
    }

    printf("%d %d\n", idx, max_freq);
    
    return 0;
}