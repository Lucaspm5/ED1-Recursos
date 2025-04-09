#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int missingNumber(int* nums, int numsSize) {
    int *memo = calloc(numsSize + 1, sizeof(int));
    if (!memo) exit(EXIT_FAILURE);
    for (int i = 0;i < numsSize;++i) (*(memo + *(nums + i)))++;
    int i = 0;
    while (i <= numsSize && *(memo + i++));
    int answer = (*(memo + (--i)) == 0 ? i : -1);
    free(memo);
    return answer;
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
    