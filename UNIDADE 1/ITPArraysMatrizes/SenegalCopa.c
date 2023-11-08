#include <stdio.h>

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor) {
    int valor_cor;
    int SY = 0;
    int SG = 0;
    int SR = 0;
    int verde = largura / 3;
    int amarelo = 2 * (largura / 3);
    int vermelho = largura;

    if (cor == 'G') {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < verde; j++) {
                SG = SG + bandeira[i][j];
            }
        }
        return SG;

    } else if (cor == 'Y') {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < verde; j++) {
                SG = SG + bandeira[i][j];
            }
        }
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < amarelo; j++) {
                SY = SY + bandeira[i][j];
            }
        }
        SY = SY - SG;
        return SY;
    } else if (cor == 'R') {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < amarelo; j++) {
                SY = SY + bandeira[i][j];
            }
        }
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < vermelho; j++) {
                SR = SR + bandeira[i][j];
            }
        }
        SR = SR - SY;
        return SR;
    }
    return 0;
}

int main() {
    int largura, altura, inicial;
    char cor;
    
    scanf("%d %d %c", &largura, &inicial, &cor);
    altura = (largura * 2) /3;
    int bandeira[altura][largura];
   
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
           if (j <= (largura / 3) - 1){
            bandeira[i][j] = inicial + 1;
           } else if (j <= (2 * largura / 3) - 1){
            bandeira[i][j] = inicial + 2;
           } else if (j <= largura - 1){
            bandeira[i][j] = inicial + 3;
           }
        }
    }
    int aposta = calcular_aposta(largura, altura, bandeira, cor);
    printf("%d\n", aposta);
    
    return 0;
}