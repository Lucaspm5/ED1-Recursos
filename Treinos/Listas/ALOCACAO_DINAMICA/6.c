#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkifExist(int *arr, int arrSize) {
    for (int i = 0;i < arrSize - 1;++i) {
        for (int j = i + 1;j < arrSize;++j) {
            if ((arr[i] / 2 == arr[j]) || (arr[i] * 2 == arr[j])) return true;
        }
    }
return false;
}

int main() {

    int elemento = 0, idx = 0;
    
    int *arr = malloc(sizeof(int)), *auxPtr = NULL;
    if (!arr) exit(EXIT_FAILURE);

    while (scanf("%d", &elemento) == 1 && elemento != -1) {
        *(arr + idx++) = elemento;
        auxPtr = realloc(arr, (idx + 1) * sizeof(int));
        if (!auxPtr) exit(EXIT_FAILURE);
        arr = auxPtr;
    }

    printf("%d\n", checkifExist(arr, idx));
    
    free(arr);

    return 0;
}

