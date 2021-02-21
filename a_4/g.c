#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t

int merge(int arr[], int temp[], int start, int mid, int end) {
    int i = start, j = mid, k = start;

    int inv_count = 0;

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

int mergeSort(int arr[], int temp[], int start, int end) {
    int mid, inv_count = 0;
    if (end > start) {
        mid = (start + end) / 2;

        inv_count += mergeSort(arr, temp, start, mid);
        inv_count += mergeSort(arr, temp, mid + 1, end);
        inv_count += merge(arr, temp, start, mid + 1, end);
    }

    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];

    for (size_t i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    printf("%d", mergeSort(arr, temp, 0, n - 1));

    return 0;
}