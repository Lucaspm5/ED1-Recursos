#include <stdio.h>
#include <stdlib.h>

int *removeDuplicates(int *nums, int *numsSize) {
    int max = 0;
    for (int *beginPtr = nums, *endPtr = nums + *numsSize;beginPtr < endPtr;++beginPtr) {
        if (*beginPtr > max) max = *beginPtr;
    }
    int *visited = calloc(max + 1, sizeof(int)), *new_array = malloc(sizeof(int)), *auxPtr = NULL;
    if (!visited || !new_array) return NULL;
    int idx = 0;
    for (int *beginPtr = nums, *endPtr = nums + *numsSize;beginPtr < endPtr;++beginPtr) {
        if (*(visited + *beginPtr)) continue;
        *(new_array + idx++) = *beginPtr;
        auxPtr = realloc(new_array, (idx + 1) * sizeof(int));
        if (!auxPtr) return NULL;
        new_array = auxPtr;
        (*(visited + *beginPtr))++;
    }
    *numsSize = idx;
    return new_array;
}

int main() {
    int n; scanf("%d", &n);
    int *arr1 = malloc(n * sizeof(int));
    if (!arr1) exit(EXIT_FAILURE);
    for (int i = 0;i < n;++i) scanf("%d", arr1 + i);
    int *arr2 = removeDuplicates(arr1, &n);
    if (!arr2) {
        free(arr1);
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i < n;++i) printf("%d\n", *(arr2 + i));
    free(arr1);
    free(arr2);
    return 0;
}
