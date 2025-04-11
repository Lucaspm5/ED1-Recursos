#include <stdio.h>
#include <stdlib.h>

int countNegatives(int **grid, int m, int n) {
    int negatives = 0;
    for (int i = 0;i < m;++i) {
        for (int j = 0;j < n;++j) negatives += (*(*(grid + i) + j) < 0);
    }
    return negatives;
}

int main() {

    int m, n; scanf("%d %d", &m, &n);

    int **matriz = malloc(m * sizeof(int*));

    if (!matriz) exit(EXIT_FAILURE);

    for (int i = 0;i < m;++i) {
        *(matriz + i) = malloc(n * sizeof(int));
        if (!(*(matriz + i))) {
            for (int j = 0;j < i;++j) free(*(matriz + j));
            exit(EXIT_FAILURE);
        }
        for (int j = 0;j <n;++j) scanf("%d", *(matriz + i) + j);
    }

    printf("%d\n", countNegatives(matriz, m, n));

    for (int i = 0;i < m;++i) free(*(matriz + i));
    free(matriz);
    
    return 0;
}
