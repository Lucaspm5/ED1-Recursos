#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "priority_queue.c"

void printHeap(Heap *v) {
    printf("Heap: ");
    for (int i = 1; i <= v->size; i++) {
        printf("%d ", v->heap[i]);
    }
    printf("\n");
}

void testInsert(Heap *v, int *values, int n) {
    printf("\n=== Insert Test ===\n");
    for (int i = 0; i < n; i++) {
        printf("Inserting %d... ", values[i]);
        if (insert(v, values[i])) {
            printf("OK\n");
            printHeap(v);
        } else {
            printf("FAIL\n");
        }
    }
}

void testExtract(Heap *v, int n) {
    printf("\n=== Extract Test ===\n");
    for (int i = 0; i < n; i++) {
        printf("Extracting max... ");
        int max = extract_max(v);
        if (max != -1) {
            printf("OK - Max: %d\n", max);
            printHeap(v);
        } else {
            printf("FAIL - Empty heap\n");
        }
    }
}

void testTop(Heap *v) {
    printf("\n=== Top Test ===\n");
    int t = top(v);
    if (t != -1) {
        printf("Top: %d\n", t);
    } else {
        printf("Empty heap\n");
    }
}

void testEmpty(Heap *v) {
    printf("\n=== Empty Test ===\n");
    printf("Heap is %s\n", isEmpty(v) ? "empty" : "not empty");
}

void testMemory(Heap *v) {
    printf("\n=== Memory Test ===\n");
    printf("Current size: %d\n", v->size);
    printf("Current capacity: %d\n", v->capacity);
}

int main() {
    printf("=== TEST 1: Empty Heap ===\n");
    Heap v1;
    construtorHeap(&v1);
    testEmpty(&v1);
    testTop(&v1);
    testExtract(&v1, 1);
    freeHeap(&v1);

    printf("\n=== TEST 2: Sequential Insert and Extract ===\n");
    Heap v2;
    construtorHeap(&v2);
    int values1[] = {831021728, 7, 4, 6, 1, 3, 2};
    testInsert(&v2, values1, 7);
    testMemory(&v2);
    testExtract(&v2, 7);
    testEmpty(&v2);
    freeHeap(&v2);

    printf("\n=== TEST 3: Random Insert ===\n");
    Heap v3;
    construtorHeap(&v3);
    srand(time(NULL));
    int values2[20];
    for (int i = 0; i < 20; i++) {
        values2[i] = rand() % 1000;
    }
    testInsert(&v3, values2, 20);
    testMemory(&v3);
    testExtract(&v3, 20);
    testEmpty(&v3);
    freeHeap(&v3);

    printf("\n=== TEST 4: Stress Test ===\n");
    Heap v4;
    construtorHeap(&v4);
    for (int i = 0; i < 1000; i++) {
        insert(&v4, rand() % 10000);
    }
    testMemory(&v4);
    for (int i = 0; i < 1000; i++) {
        extract_max(&v4);
    }
    testEmpty(&v4);
    freeHeap(&v4);

    return 0;
}
