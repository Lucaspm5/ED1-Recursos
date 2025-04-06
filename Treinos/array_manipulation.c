#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 1103515245
#define C 12345
#define M 2147483648

typedef struct { int *beginPtr, *advancePtr, *endPtr; } Array;

typedef struct { unsigned seed; } Random;

Random init_random() {
    Random r;
    r.seed = (unsigned)time(NULL);
    return r;
}

Array init_array() {
    Array a;
    a.beginPtr = malloc(10 * sizeof(int));
    if (!a.beginPtr) {
        printf("Erro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }
    a.advancePtr = a.beginPtr;
    a.endPtr = a.beginPtr + 10;
    return a;
}

void free_array(Array a) {
    free(a.beginPtr);
}

unsigned _rand(Random *r) {
    r->seed = (A * r->seed + C) % M;
    return (r->seed & 0x7F) | 0x1;
}

void safe_array(Array *a, Random *r) {
    a->advancePtr = a->beginPtr;
    while (a->advancePtr < a->endPtr) {
        *(a->advancePtr) = _rand(r);
        if (*(a->advancePtr) >= 100) *(a->advancePtr) %= 100;
        a->advancePtr++;
    }
}

void print_array(Array a) {
    a.advancePtr = a.beginPtr;
    while (a.advancePtr < a.endPtr) {
        printf("%d ", *(a.advancePtr));
        a.advancePtr++;
    }
    printf("\n");
}

int main() {
    Random r = init_random();
    Array a = init_array();
    
    safe_array(&a, &r);
    print_array(a);
    
    free_array(a);
    return 0;
}
