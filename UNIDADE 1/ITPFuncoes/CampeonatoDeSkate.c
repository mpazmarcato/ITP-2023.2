#include <stdio.h>

int calcularScoreDia(int n1, int n2, int n3) {
    if ((n1 >= n2 && n1 <= n3) || (n1 >= n3 && n1 <= n2)) {
        return n1;
    } else if ((n2 >= n1 && n2 <= n3) || (n2 >= n3 && n2 <= n1)) {
        return n2;
    } else {
        return n3;
    }
}

void lerNotasDia(int *n1, int *n2, int *n3) {
    scanf("%d %d %d", n1, n2, n3);
}

int calcularScoreFinal() {
    int dia[3];
    int score;

    for (int i = 0; i < 3; i++) {
        int n1, n2, n3;
        lerNotasDia(&n1, &n2, &n3);
        dia[i] = calcularScoreDia(n1, n2, n3);
    }

    score = calcularScoreDia(dia[0], dia[1], dia[2]);
    return score;
}

int main() {
    int score1, score2;

    score1 = calcularScoreFinal();
    score2 = calcularScoreFinal();

    if (score1 > score2) {
        printf("A\n");
    } else if (score1 < score2) {
        printf("B\n");
    } else {
        printf("empate\n");
    }

    return 0;
}
