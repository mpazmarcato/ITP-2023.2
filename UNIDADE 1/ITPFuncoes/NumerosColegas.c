#include <stdio.h>
#include <stdlib.h>
int somaDivisoresProprios(int numero) {
    int soma = 0;

    for (int i = 1; i <= numero/2; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }

    return soma;
}

int saoColegas(int a, int b) {
    int somaDivA = somaDivisoresProprios(a);
    int somaDivB = somaDivisoresProprios(b);
    int result1 = abs(a -  somaDivB);
    int result2 = abs(b - somaDivA);

    return (result1 <= 2 && result2 <= 2);
}

int main() {
    int numero1, numero2;
    
    scanf("%d %d", &numero1, &numero2);

    if (saoColegas(numero1, numero2)) {
        printf("S\n"); 
    } else {
        printf("N\n"); 
    }

    return 0;
}