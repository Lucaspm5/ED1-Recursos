#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados, tamanho, capacidade;
} Vector;

#define CAPACIDADE_INICIAL 10

Vector vector_create() {
    Vector v;
    v.dados = calloc(CAPACIDADE_INICIAL, sizeof(int));
    if (!v.dados) return (Vector){NULL, 0, 0};  
    v.tamanho = 0;
    v.capacidade = CAPACIDADE_INICIAL;
    return v;
}

int push_back(Vector *v, int value) {
    if (v->tamanho == v->capacidade) {
        v->capacidade <<= 1;
        int *temp = realloc(v->dados, v->capacidade * sizeof(int));
        if (!temp) return 0;
        v->dados = temp;
    }
    v->dados[v->tamanho++] = value;
    return 1;
}

void clear(Vector *v) {
    free(v->dados);
    v->dados = NULL;
    v->tamanho = 0;
    v->capacidade = CAPACIDADE_INICIAL;
}

int elementMin(int *nums, int nums1Size, int *nums2, int nums2Size) {

    int max = 0;

    for (int i = 0;i < nums1Size;++i) {
        if (nums[i] > max) max = nums[i];
    }

    for (int i = 0;i < nums2Size;++i) {
        if (nums2[i] > max) max = nums2[i];
    }

    int *memo = calloc(max + 1, sizeof(int));

    for (int i = 0;i < nums1Size;++i) {
        if (memo[nums[i]] != 0) continue;
        ++memo[nums[i]];
    }

    for (int i = 0;i < nums2Size;++i) ++memo[nums2[i]];
    
    int i = 0;
    while (i <= max && memo[i++] < 2);
    int answer = (memo[--i] >= 2) ? i : -1; 
    free(memo);
    return answer;
}

int main() {
    Vector a = vector_create();
    if (a.dados == NULL) exit(EXIT_FAILURE);

    Vector b = vector_create();
    if (b.dados == NULL) exit(EXIT_FAILURE);

    int n1; scanf("%d", &n1);
    for (int i = 0;i < n1;++i) {
        int value; scanf("%d", &value);
        if (!push_back(&a, value)) exit(EXIT_FAILURE);
    }

    int n2; scanf("%d", &n2);
    for (int i = 0;i < n2;++i) {
        int value; scanf("%d", &value);
        if (!push_back(&b, value)) exit(EXIT_FAILURE);
    }

    printf("%d\n", elementMin(a.dados, a.tamanho, b.dados, b.tamanho));

    clear(&a);
    clear(&b);

    return 0;
}
