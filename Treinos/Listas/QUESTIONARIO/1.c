#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CAPACITY_INITIAL 20
#define MAX(a, b) a ^ ((a ^ b) & -(a < b))
#define MIN(a, b) b ^ ((a ^ b) & -(a < b))

typedef struct { int max, min; } Range;

char *readLine() {
    int capacity = CAPACITY_INITIAL;
    char *line = malloc(capacity * sizeof(char)), *temp = NULL;

    if (!line) return NULL;

    int c = 0, index = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (index + 1 >= capacity) {
            capacity <<= 1;
            temp = realloc(line, capacity * sizeof(char));
            if (!temp) {
                free(line);
                return NULL;
            }
            line = temp;
        }
        line[index++] = (char)c;
    }
    
    line[index] = '\0';

    return line;    
}

int main() {
    
    char *number = NULL;
    int sigma = 0, count = 0;
    double average = 0;

    Range range = {0, INT_MAX};

    while ((number = readLine()) && strcmp(number, "-1") != 0) {
        int x = atoi(number);
        if (!x) continue;
        sigma += x;
        ++count;
        range.max = MAX(range.max, x);
        range.min = MIN(range.min, x);
    }

    average = (sigma * 1.) / (count * 1.);

    printf("sum: %d count: %d average: %.2f min: %d max: %d\n", sigma, count, average, range.min, range.max);

    free(number);

    return 0;
}
    
