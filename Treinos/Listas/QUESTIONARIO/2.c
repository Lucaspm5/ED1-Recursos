#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand((unsigned)time(NULL));

    int m, n, x; scanf("%d %d %d", &m, &n, &x);

    int **a = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        *(a + i) = malloc(n * sizeof(int));
        for (int j = 0;j < n;j++) *(*(a + i) + j) = rand() % (x + 1);
    }

    int *memo = calloc(x + 1, sizeof(int));
    
    for (int i = 0;i < m;++i) {
        for (int j = 0;j < n;++j) (*(memo + *(*(a + i) + j)))++;
    }

    for (int i = 0;i < m;++i) {
        for (int j = 0;j < n;++j)
            printf("%d ", *(*(a + i) + j));
        printf("\n");
    }

    for (int i = 0;i <= x;++i)
        printf("%d %d\n", i, *(memo + i));

    for (int i = 0;i < m;i++) free(*(a + i));

    free(a);    

    return 0;
}
    
