#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000
#define INITIAL_CAPACITY 20 

char *input(int *len) {

    char *s1 = malloc((INITIAL_CAPACITY + 1) * sizeof(char)), *temp = NULL;

    if (!s1) return NULL;

    int c = 0, capacity = INITIAL_CAPACITY + 1;

    while (*len < LIMIT && (c = getchar()) != '\n' && c != EOF) {
        if (*len + 1 >= capacity) {
            capacity <<= 1;
            temp = realloc(s1, capacity * sizeof(char));
            if (!temp) {
                printf("Erro ao alocar o caracter: %c\n", (char)c);
                continue;
            }
            s1 = temp;
        }
        *(s1 + (*len)) = (char)c;
        (*len)++;
    }

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

    printf("%s\n", s1);

    free(s1);

    return 0;
}
