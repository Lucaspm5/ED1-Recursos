#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 1103515245
#define C 12345
#define M 2147483648

typedef struct {
    int *beginPtr, *advancePtr, *endPtr;
} Array;

unsigned _rand(unsigned *seed) {
    *seed = (A * *seed + C) % M;
    return *seed;
}

int main() {
    unsigned seed = (unsigned)time(NULL);
    
    Array a;
    
    a.beginPtr = malloc(10 * sizeof(int));
    
    if (!a.beginPtr) {
        printf("Erro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }

    a.advancePtr = a.beginPtr;
    a.endPtr = a.beginPtr + 10;

    while (a.advancePtr != a.endPtr) {
        *(a.advancePtr) = (_rand(&seed) & 0x7F) | 0x1;
        if (*(a.advancePtr) >= 100) *(a.advancePtr) %= 100;
        a.advancePtr++;
    }
    
    a.advancePtr = a.beginPtr;
    while (a.advancePtr != a.endPtr) {
        printf("%d ", *(a.advancePtr));
        a.advancePtr++;
    }

    free(a.beginPtr);

    return 0;
}
