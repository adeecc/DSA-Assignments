#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
#define TRUE (uint8_t)1
#define FALSE (uint8_t)0
 
#define ll long long int
#define ull long long unsigned int
 
ll merge(ll arr[], ll temp[], ll start, ll mid, ll end) {
    ll i = start, j = mid, k = start;
 
    ll inv_count = 0;
 
    while ((i <= mid - 1) && (j <= end)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
 
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
 
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
 
    while (j <= end) {
        temp[k++] = arr[j++];
    }
 
    for (int i = start; i < end; i++) {
        arr[i] = temp[i];
    }
 
    return inv_count;
}
 
ll mergeSort(ll arr[], ll temp[], ll start, ll end) {
    ll mid;
    ll inv_count = 0;
    if (end > start) {
        mid = (start + end) / 2;
 
        inv_count = mergeSort(arr, temp, start, mid);
        inv_count += mergeSort(arr, temp, mid + 1, end);
        inv_count += merge(arr, temp, start, mid + 1, end);
    }
 
    return inv_count;
}
 
int main() {
    ll n;
    scanf("%lli", &n);
 
    ll arr[n], temp[n];
 
    for (size_t i = 0; i < n; i++) {
        scanf("%lli", arr + i);
    }
 
    printf("%lli", mergeSort(arr, temp, 0, n - 1));
 
    return 0;
}