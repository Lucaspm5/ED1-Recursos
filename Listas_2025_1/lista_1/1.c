#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MOD 100
#define FOR(n) for (int i = 0;i < n;++i)

int main() {

    void remover_duplicatas(int *vetor, int n, int *compactado, int *tam_compactado);

    srand((unsigned)time(NULL));

    int n = rand() % MOD + 1, arr[n];

    FOR(n) *(arr + i) = (rand() ^ 1) % MOD;

    int narr[n], nsize = 0;

    printf("Antes:\n");
    FOR(n) printf("|%d|", *(arr + i));

    remover_duplicatas(arr, n, narr, &nsize);

    printf("\n\n");
    printf("Depois:\n");
    FOR(nsize) printf("|%d|", *(narr + i));

    return 0;
}

void remover_duplicatas(int *vetor, int n, int *compactado, int *tam_compactado) {
    bool hsh[MOD]; memset(hsh, false, sizeof(hsh));
    FOR(n) {
        if (hsh[*(vetor + i)]) continue;
        hsh[*(vetor + i)] ^= 1;
        *(compactado + (*tam_compactado)++) = *(vetor + i);
    }

}
