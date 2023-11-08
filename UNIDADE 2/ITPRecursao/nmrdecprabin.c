#include <stdio.h>

void decimalParaBinario(int n) {
    if (n > 1) {
        decimalParaBinario(n / 2);
    }
    printf("%d", n % 2);
}

int main(){
    int numero;
    scanf("%d", &numero);
    
    decimalParaBinario(numero);
    printf("\n");

}
