#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Converte uma string para um inteiro, se e somente se, essa string tiver em formato de inteiro
*/

int main() {

    char *s1 = malloc(100 * sizeof(char)); scanf("%s", s1); getchar();

    int n = 0;

    char *beginPtr = s1, *endPtr = s1 + (int)strlen(s1);

    while ((beginPtr != endPtr) && (*beginPtr >= '0' && *beginPtr <= '9')) {
        n = n * 10 + ((*beginPtr) - '0');
        ++beginPtr;
    }

    printf("%d\n", n);

    free(s1);

    return 0;
}
