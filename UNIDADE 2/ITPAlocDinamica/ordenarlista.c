#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int *arr = NULL;
    int n = 0;
    int capacity = 10; 

    arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return 1;
    }

    int num;

    while (scanf("%d", &num) != EOF) {
        if (n >= capacity) {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                fprintf(stderr, "Erro na realocação de memória.\n");
                return 1;
            }
        }
        arr[n] = num;
        n++;
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(arr);

    return 0;
}