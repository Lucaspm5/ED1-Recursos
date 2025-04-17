#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int *heap;
    int size;
    int capacity;
} Heap;

int parent(int i);
int left(int i);
int right(int i);
bool construtorHeap(Heap *v);
int sizeHeap(Heap *v);
void swap(int *a, int *b);  
bool insert(Heap *v, int element);
bool isEmpty(Heap *v);
int top(Heap *v);
int extract_max(Heap *v);
void freeHeap(Heap *v);

#endif
