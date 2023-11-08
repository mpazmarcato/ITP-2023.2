#include <stdio.h>

int contarBolinhas(char matriz[100][100], int linha, int coluna, int linhas, int colunas) {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || matriz[linha][coluna] == '*' || matriz[linha][coluna] == 'M' || matriz[linha][coluna] == ' ') {
        return 0;
    }

    if (matriz[linha][coluna] == '.') {
        matriz[linha][coluna] = ' ';  
    }
    
    int bolinha = (matriz[linha][coluna] == ' ');

    int bolinhasComidas = (bolinha + contarBolinhas(matriz, linha - 1, coluna, linhas, colunas)
    + contarBolinhas(matriz, linha + 1, coluna, linhas, colunas)
    + contarBolinhas(matriz, linha, coluna - 1, linhas, colunas)
    + contarBolinhas(matriz, linha, coluna + 1, linhas, colunas));

    return bolinhasComidas;
}

int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    char matriz[100][100];
    for (int i = 0; i < linhas; i++) {
        scanf("%s", matriz[i]);
    }

    int totalBolinhas = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 'C') {
                totalBolinhas = contarBolinhas(matriz, i, j, linhas, colunas);
                break;
            }
        }
    }

    printf("Total de bolinhas devoradas: %d\n", totalBolinhas);
    printf("Mapa final:\n");
    for (int i = 0; i < linhas; i++) {
        printf("%s\n", matriz[i]);
    }

    return 0;
}