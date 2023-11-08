#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindromoRecursivo(char *str, int inicio, int final) {
    if (inicio >= final) {
        return 1;
    }
    while (str[inicio] == ' ') {
        inicio++;
    }
    while (str[final] == ' ') {
        final--;
    }

    if (tolower(str[inicio]) != tolower(str[final])) {
        return 0;
    }

    return palindromoRecursivo(str, inicio + 1, final - 1);
}

int palindromo(char *entrada){
    int tamanho = strlen(entrada);
    return palindromoRecursivo(entrada, 0, tamanho - 1);
}

int main(){
    char texto[300];
    fgets(texto, sizeof(texto), stdin);
    
    int resultado = palindromo(texto);
    
    if(resultado){
        printf("O texto \"%s\" é palíndromo", texto);
    } else {
        printf("O texto \"%s\" não é palíndromo", texto);
    }
    
    return 0;
}