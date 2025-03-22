#include <stdio.h>
#include <stdbool.h>

#define FOR(arr, n) \
    for (int *beginPtr = arr, *endPtr = arr + n;beginPtr != endPtr;++beginPtr)

void bubbleSort(int *arr, int);

int main() {

    int arr[] = {7, 9, 10, 1, 2, 3, 4, 8, 7}, n = sizeof(arr) >> 2;

    bubbleSort(arr, n);

    FOR(arr, n) printf("%d\n", *beginPtr);

    return 0;
}

void bubbleSort(int *arr, int n){

    void _swap(int *, int *);

    bool swapped = true;
    for (int i = 0; i < n - 1 && swapped; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                _swap(arr + j, arr + j + 1);
                swapped = true;
            }
        }
    }
}

void _swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
