#include <stdio.h>

float calculaMedia (char tipo, float n1, float n2, float n3){
    float mediaAritmetica = 0.0;
    float mediaPonderada = 0.0;
    if (tipo == 'A'){
        mediaAritmetica = (n1 +n2 + n3)/3;
        printf("Média %.2f", mediaAritmetica);
    } else if (tipo == 'P') {
        mediaPonderada = ((n1 * 4)+(n2 * 5)+(n3 * 6))/15;
        printf("Média %.2f", mediaPonderada);
    }
}

int main(){
    char tipo;
    float n1, n2, n3;
    
    scanf("%c %f %f %f", &tipo, &n1, &n2, &n3);
    calculaMedia (tipo, n1, n2, n3);
    
}