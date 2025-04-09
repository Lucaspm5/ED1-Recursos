#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int missingNumber(int* nums, int numsSize) {
    int N = ((numsSize + 1) * numsSize) / 2, arr_sum = 0;
    for (int i = 0;i < numsSize;++i) arr_sum += (*(nums + i));
    return N - arr_sum;
}

int main() {
    int n; scanf("%d", &n);
    int *nums = malloc(n * sizeof(int));
    if (!nums) exit(EXIT_FAILURE);
    for (int i = 0;i < n;++i) scanf("%d", nums + i);
    printf("%d\n", missingNumber(nums, n));
    free(nums);
    return 0;
}
    