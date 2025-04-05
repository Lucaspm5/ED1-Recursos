#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Pega o tamanho de uma string
    1. Leitura dinâmica
*/

#define LIMIT 1000

char *input(int *len) {
    char *s1 = NULL, *temp = NULL;

    int c = 0;

    while (*len < LIMIT && (c = getchar()) != '\n' && c != EOF) {
        temp = realloc(s1, sizeof(char) * (*len + 1));
        if (!temp) {
            printf("Erro ao adicionar o caracter: %c!", (char)c);
            continue;
        }
        s1 = temp;
        *(s1 + (*len)) = (char)c;
        (*len)++;
    }

    temp = realloc(s1, sizeof(char) * (*len + 1));
    if (!temp) {
        printf("Erro ao adicionar o caracter de fim de string!\n");
        free(s1);
        return NULL;
    }

    s1 = temp;
    *(s1 + (*len)) = '\0';

    return s1;

}

int main() {

    int len = 0;

    char *s1 = input(&len);

    if (!s1) {
        printf("Ocorreu um erro na alocação!\n");
        exit(EXIT_FAILURE);
    }

    printf("%s - %d\n", s1, len);

    free(s1);

    return 0;
}
