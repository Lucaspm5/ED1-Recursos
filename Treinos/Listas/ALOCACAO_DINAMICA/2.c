#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct { int _mx, _mn; } Point;

bool ocorrenciasUnicas(int * arr, int arrSize) {
    
    Point x = {0, INT_MAX};

    for (int i = 0; i < arrSize;++i) {
        x._mx = max(x._mx, *(arr + i));
        x._mn = min(x._mn, *(arr + i));
    }

    int hsh = max(abs(x._mx), abs(x._mn));

    int *memo = calloc(((hsh + 1) << 1) + 1, sizeof(int));

    for (int i = 0; i < arrSize;++i) {
        int recover = *(arr + i);
        if (recover < 0)
            recover = (hsh + 2) + (-1 * (*(arr + i)));
        ++(*(memo + recover));
    }

    int *freq = calloc(arrSize + 1, sizeof(int));

    bool answer = true;
    for (int i = x._mn;i <= x._mx && answer;++i) {
        int recover = i;
        if (recover < 0) recover = (hsh + 2) + (-1 * i);
        if (*(memo + recover) == 0) continue;
        if (++(*(freq + *(memo + recover))) > 1) answer = false;
    }

    free(memo), free(freq);

    return answer;
}

int main() {
    int n; scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if (!arr) exit(EXIT_FAILURE);
    for (int i = 0;i < n;++i) scanf("%d", &arr[i]);
    printf("%s", (ocorrenciasUnicas(arr, n) ? "SHOW" : "NOT SHOW"));
    free(arr);
    return 0;
}
