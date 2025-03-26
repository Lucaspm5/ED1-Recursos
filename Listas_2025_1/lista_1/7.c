#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define FOR(i, N) for (i = 0;i < N;++i)
#define MOD 1000

int main() {

    void contar_ocorrencias(int *vetor, int n, int *ocorrencias, int *tam_ocorrencias);

    int n, i; scanf("%d", &n);
    int arr[n];

    srand((unsigned)time(NULL));

    FOR(i, n) *(arr + i) = rand() % MOD;

    int ocorrencias[MOD + 1], tam_ocorrencias = 0;
    memset(ocorrencias, 0, sizeof(ocorrencias));    

    contar_ocorrencias(arr, n, ocorrencias, &tam_ocorrencias);

    bool visited[MOD + 1] = {false};

    FOR(i, n) {
        if (!visited[arr[i]]) {
            printf("Elemento do meu array: %d - Repeticoes: %d\n", *(arr + i), *(ocorrencias + *(arr + i)));
            visited[arr[i]] ^= 1;
        }
    }

    printf("Numero de elementos distintos: %d\n", tam_ocorrencias);

    return 0;
}

void contar_ocorrencias(int *vetor, int n, int *ocorrencias, int *tam_ocorrencias) {
    int i;
    FOR(i, n) {
        if ((++ocorrencias[*(vetor + i)] - 1) == 0) ++(*tam_ocorrencias);
    }
}
