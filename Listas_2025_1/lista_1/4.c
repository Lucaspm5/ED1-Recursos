#include <stdio.h>
#include <stdlib.h>

int main() {

    int soma_diagonal(int **matriz, int n);

    int n; scanf("%d", &n);

    int **matriz = malloc(n * sizeof(int *));

    if (!matriz)
        exit(EXIT_FAILURE);

    for (int i = 0;i < n;++i) {
        *(matriz + i) = malloc(sizeof(int) * n);
        if (!(*(matriz + i))) exit(EXIT_FAILURE);
        for (int j = 0;j < n;++j) scanf("%d", *(matriz + i) + j);
    }

    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) printf("[%d]", *(*(matriz + i) + j));
        printf("\n");
    }

    printf("%d\n", soma_diagonal(matriz, n));

    for (int i = 0;i < n;++i) free(*(matriz + i));

    free(matriz);

    return 0;
}


int soma_diagonal(int **matriz, int n) {
    int sum = 0;
    for (int i = 0;i < n;++i) sum += (*(*(matriz + i) + i));
    return sum;
}
