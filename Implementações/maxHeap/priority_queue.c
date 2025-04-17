#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "priority_queue.h"

int parent(int i) { return i >> 1; }

int left(int i) { return i << 1; }

int right(int i) { return (i << 1) + 1; }

bool construtorHeap(Heap *v) {
    v->heap = malloc(2 * sizeof(int));
    if (!v->heap) return false;
    v->size = 0;
    v->capacity = 2;
    v->heap[0] = 0; 
    return true; 
}

int sizeHeap(Heap *v) { return v->size; }

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

bool insert(Heap *v, int element) {
    if (v->size + 1 >= v->capacity) {
        v->capacity <<= 1;
        int *auxPtr = realloc(v->heap, v->capacity * sizeof(int));
        if (!auxPtr) return false;
        v->heap = auxPtr;
    }
    v->heap[++v->size] = element;
    int i = v->size, p = parent(i);
    while (p && v->heap[p] < v->heap[i]) {
        swap(&v->heap[p], &v->heap[i]);
        i = p;
        p = parent(i);
    }
    return true;
}

bool isEmpty(Heap *v) { return v->size == 0; }

int top(Heap *v) {
    return (!isEmpty(v)) ? v->heap[1] : -1;
}

int extract_max(Heap *v) {
    if (isEmpty(v)) return -1;
    int max = v->heap[1];
    swap(&v->heap[1], &v->heap[v->size--]);

    int i = 1, n = left(i) > v->size ? 0 : left(i);
    while (n) {
        int r = right(i) > v->size ? 0 : right(i);
        if (r && v->heap[r] > v->heap[n]) n = r;
        if (v->heap[i] < v->heap[n]) {
            swap(&v->heap[i], &v->heap[n]);
            i = n;
            n = left(i) > v->size ? 0 : left(i);
        } else n = 0;
    }
    return max;
}

void freeHeap(Heap *v) {
    free(v->heap);
}
                        
