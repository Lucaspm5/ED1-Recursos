#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MOD 100
#define FOR(arr, n) for (int i = 0;i < n;++i)

void remover_duplicatas(int *, int, int *, int *);

int main() {

    srand((unsigned)time(NULL));

    int n = rand() % MOD, arr[n];

    FOR(arr, n) *(arr + i) = (rand() ^ 1) % MOD;

    int narr[n], nsize = 0;

    remover_duplicatas(arr, n, narr, &nsize);

    FOR(arr, n) printf("%d\n", *(arr + i));

    return 0;
}

void remover_duplicatas(int *vetor, int n, int *compactado, int *tam_compactado) {
    bool hsh[MOD]; memset(hsh, false, sizeof(hsh));
    FOR(vetor, n) {
        if (hsh[*(vetor + i)]) continue;
        hsh[*(vetor + i)] ^= 1;
        *(compactado + (*tam_compactado)++) = *(vetor + i);
    }

}
