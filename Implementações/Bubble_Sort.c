#include <stdio.h>
#include <stdbool.h>

#define FOR(arr, n) \
    for (int *beginPtr = arr, *endPtr = arr + n;beginPtr != endPtr;++beginPtr)

void bubbleSort(int *arr, int, bool (*)(int, int));
bool comp1(const int, const int);
bool comp2(const int, const int);

int main() {

    int arr[] = {7, 9, 10, 1, 2, 3, 4, 8, 7}, n = sizeof(arr) >> 2;

    bubbleSort(arr, n, comp1);
    
    FOR(arr, n) printf("%d\n", *beginPtr);

    bubbleSort(arr, n, comp2);

    printf("\n");
    FOR(arr, n) printf("%d\n", *beginPtr);

    return 0;
}

void bubbleSort(int *arr, int n, bool (*compare)(int, int)){

    void _swap(int *, int *);

    bool swapped = true;
    for (int i = 0; i < n - 1 && swapped; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if ((*compare)(*(arr + j), *(arr + j + 1))) {
                _swap(arr + j, arr + j + 1);
                swapped = true;
            }
        }
    }

}

bool comp1(const int a, const int b) { return b > a; }
bool comp2(const int a, const int b) { return a > b; }

void _swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
