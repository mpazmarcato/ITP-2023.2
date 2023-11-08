#include <stdio.h>

void calcular_media(int *A, int *B) {
     int menor, maior;

    if (*A < *B) {
        menor = *A;
        maior = *B;
        *A = (menor + maior) / 2;
        *B = (menor + maior) % 2;
    } else {
        menor = *B;
        maior = *A;
        *A = (menor + maior) % 2;
        *B = (menor + maior) / 2;
    }
}


int main() {
    int A, B;

    scanf("%d %d", &A, &B);

    calcular_media(&A, &B);

    printf("A = %d\nB = %d\n", A, B);

    return 0;
}