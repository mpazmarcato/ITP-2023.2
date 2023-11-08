#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int numerosAlunos[n];
    float mediasAlunos[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d - %f", &numerosAlunos[i], &mediasAlunos[i]);
    }
    
    int aprovados[n], recuperacao[n], reprovados[n];
    int numAprovados = 0, numRecuperacao = 0, numReprovados = 0;
    
    for (int i = 0; i < n; i++) {
        if (mediasAlunos[i] >= 7.0) {
            aprovados[numAprovados++] = numerosAlunos[i];
        } else if (mediasAlunos[i] >= 5.0 && mediasAlunos[i] < 7.0 ) {
            recuperacao[numRecuperacao++] = numerosAlunos[i];
        } else {
            reprovados[numReprovados++] = numerosAlunos[i];
        }
    }
    
    printf("Aprovados: ");
    for (int i = 0; i < numAprovados; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d (%.1f)", aprovados[i], mediasAlunos[aprovados[i] - 1]);
    }
    printf("\nRecuperação: ");
    for (int i = 0; i < numRecuperacao; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d (%.1f)", recuperacao[i], mediasAlunos[recuperacao[i] - 1]);
    }
    printf("\nReprovados: ");
    for (int i = 0; i < numReprovados; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d (%.1f)", reprovados[i], mediasAlunos[reprovados[i] - 1]);
    }
    
    return 0;
}