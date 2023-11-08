#include <stdio.h>

//função se pode botar um número em uma casa
int numeroPossibilitado(int sudoku[9][9], int linha, int coluna, int num) {
    // Se o número não está na mesma linha ou coluna
    for (int x = 0; x < 9; x++) {
        if (sudoku[linha][x] == num || sudoku[x][coluna] == num) {
            return 0;
        }
    }

    // Se o número não está na mesma submatriz 3x3
    int comecaLinha = linha - linha % 3;
    int comecaColuna = coluna - coluna % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + comecaLinha][j + comecaColuna] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int resolverSudoku(int sudoku[9][9], int linha, int coluna) {
    if (linha == 9) {
        return 1;
    }
    if (coluna == 9) {
        return resolverSudoku(sudoku, linha + 1, 0);
    }
    if (sudoku[linha][coluna] != 0) {
        return resolverSudoku(sudoku, linha, coluna + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (numeroPossibilitado(sudoku, linha, coluna, num)) {
            sudoku[linha][coluna] = num;
            if (resolverSudoku(sudoku, linha, coluna + 1)) {
                return 1; // solução
            }
            sudoku[linha][coluna] = 0;
        }
    }
    return 0;
}

int main() {
    int sudoku[9][9];
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            char casas;
            scanf(" %c", &casas);
            if (casas == '*') {
                sudoku[linha][coluna] = 0;
            } else {
                sudoku[linha][coluna] = casas - '0';
            }
        }
    }

    if (resolverSudoku(sudoku, 0, 0)) {
        for (int linha = 0; linha < 9; linha++) {
            for (int coluna = 0; coluna < 9; coluna++) {
                printf("%d", sudoku[linha][coluna]);
            }
            printf("\n");
        }
    } else {
        printf("Não tem solução!\n");
    }
    return 0;
}
