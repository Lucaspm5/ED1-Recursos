#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize;
    while (left < right) {
        int middle = left + ((right - left) >> 1);
        if (*(nums + middle) == target) return middle;
        else if (*(nums + middle) > target) right = middle;
        else left = middle + 1;
    }
    return left;
}
void merge_version_luquinhas(int left, int right, int *x) {
    if (left >= right) return;
    int middle = left + ((right - left) >> 1);

    merge_version_luquinhas(left, middle, x), merge_version_luquinhas(middle + 1, right, x);

    int *prefix = calloc(middle - left + 1, sizeof(int));
    int *sufix = calloc(right - middle, sizeof(int));

    for(int i = left;i <= middle;++i) *(prefix + (i - left)) = *(x + i);
    for(int i = middle + 1;i <= right;++i) *(sufix + (i - (middle + 1))) = *(x + i);

    int i = 0, j = 0, k = left;
    int n = middle - left + 1;
    int m = right - middle;

    while(i < n || j < m) {
        if (j == m || ((*(prefix + i) < *(sufix + j)) && i < n)) *(x + k++) = *(prefix + i++);
        else *(x + k++) = *(sufix + j++);
    }
    free(prefix), free(sufix);
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int *x = malloc(n * sizeof(int));
    for(int i = 0;i < n;++i) scanf("%d", &x[i]);
    merge_version_luquinhas(0, n - 1, x);
    printf("%d\n", searchInsert(x, n, target));
    free(x);
    return 0;
}
