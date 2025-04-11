#include <stdio.h>
#include <stdlib.h>

int solve(int **matriz, int n) {
    int **visited = calloc(n, sizeof(int *));
    if (!visited) exit(EXIT_FAILURE);
    for (int i = 0;i < n;++i) {
        *(visited + i) = calloc(n, sizeof(int));
        if (!visited) {
            for (int j = 0;j < i;++j) free(*(visited + j));
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) printf("%d", matriz[i][j]);
        printf("\n");
    }
    int answer = 0;
    for (int i = 0;i < n;++i) {
        answer += (!visited[i][i] ? matriz[i][i] : 0);
        visited[i][i] = 1;
        answer += (!visited[i][n / 2] ? matriz[i][n / 2] : 0);
        visited[i][n / 2] = 1;
        answer += (!visited[n / 2][i] ? matriz[n / 2][i] : 0);
        visited[n / 2][i] = 1;
        answer += (!visited[i][n - i - 1] ? matriz[i][n - i - 1] : 0);
        visited[i][n - i - 1] = 1;
    }
    for (int i = 0;i < n;++i) free(*(visited + i));
    free(visited);
    return answer;
}

int main() {
    int n; scanf("%d", &n);
    int **matriz = malloc(n * sizeof(int *));
    if (!matriz) exit(EXIT_FAILURE);
    for (int i = 0;i < n;++i) {
        *(matriz + i) = malloc(n * sizeof(int));
        if (!matriz) {
            for (int j = 0;j < i;++j) free(*(matriz + j));
            exit(EXIT_FAILURE);
        }
        for (int j = 0;j < n;++j) scanf("%d", *(matriz + i) + j);
    }

    printf("%d\n", solve(matriz, n));

    for (int i = 0;i < n;++i) free(*(matriz + i));
    free(matriz);

    return 0;
}
