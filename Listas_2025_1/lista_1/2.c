#include <stdio.h>

/*
    a) 
    A função recebe dois endereços de memoria como argumentos, por isso a utilização de ponteiros,
    a função trabalha diretamente com a variavel criada no main por meio da desreferenciação de ponteiros,
    por fim é feita a troca de valores.
*/

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int a = 7, b = 3;

    printf("%d - %d\n", a, b);
    // b)
    troca(&a, &b);

    printf("%d - %d\n", a, b);

    return 0;
}
