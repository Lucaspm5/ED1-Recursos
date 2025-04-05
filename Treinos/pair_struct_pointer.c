#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *beginPtr, *endPtr;
}Pair;

int main() {

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {1, 2, 3, 4, 5, 6, 7};

    Pair x[3];

    x[0].beginPtr = a, x[0].endPtr = a + sizeof(a) / sizeof(int);
    x[1].beginPtr = b, x[1].endPtr = b + sizeof(b) / sizeof(int); 
    x[2].beginPtr = c, x[2].endPtr = c + sizeof(c) / sizeof(int);
    
    for (int i = 0;i < 3;++i) {

        int *beginPtr = x[i].beginPtr;
        int *endPtr = x[i].endPtr;

        while (beginPtr != endPtr) {
            printf("[%d]", *beginPtr);
            ++beginPtr; 
        }

        printf("\n");
    }

    return 0;
}
