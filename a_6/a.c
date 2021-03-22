#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

int n, k;

int cmpfunc(const void* a, const void* b) { 
    if (*(ll*)a != *(ll*)b)
        return ((*(int*)a % k) - (*(int*)b % k)); 

    return ((*(int*)a) - (*(int*)b)); 
}


int main() {
    scanf("%d %d", &n, &k);

    ll a[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%lld", a + i);
    }
    
    qsort(a, n, sizeof(ll), cmpfunc);

    int i;
    for (i = 0; i < n - 1; i++)
    {
        printf("%lld ", a[i]);
    }

    printf("%lld", a[i]);
    
    return 0;
}