#include <stdio.h>

float calcular_media(int *, int);

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};

    printf("%.2f", calcular_media(arr, sizeof(arr) >> 2));

    return 0;
}

float calcular_media(int *arr, int n) {
    int sum = 0;
    for (int i = 0;i < n;++i) sum += arr[i];
    return (float) sum / n;
}
