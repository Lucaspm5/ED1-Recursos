#include <stdio.h>
#include <stdint.h>

#define MAX(a, b) a ^ ((a ^ b) & - (a < b))
#define FOR(arr, n) for (int32_t i = 0;i < n;++i)

int main() {

    int32_t maior_elemento(int32_t *, int32_t);

    int32_t v[] = {77, 88, 2, 4, 22, 103};

    printf("%d\n", maior_elemento(v, sizeof(v) >> 2));

    return 0;
}

int maior_elemento(int32_t *v, int32_t n) {
    int32_t answer = 0;
    FOR(v, n) answer = MAX(*(v + i), answer);
    return answer;
}
