#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* maior(int *, int *);

int main() {

    srand((unsigned)time(NULL));

    int a = rand() % 10, b = rand() % 10;

    printf("%d\n", *maior(&a, &b));

    return 0;
}

int* maior(int *a, int *b) { return (*a) > (*b) ? a : b; }
