#include <stdio.h>

int main() {
    int n, m, x;
    char ch;
    scanf("%d %d", &n, &m);
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf(" %c", &ch);
    scanf("%d", &x);
    
    if (ch == 'l'){
        int maior = A[x][0];
        for (int j = 1; j < m; j++) {
            if (A[x][j] > maior) {
                maior = A[x][j];
            }
        }
        printf("%d", maior);
    } else if (ch == 'c') {
        int maior = A[0][x];
        for (int i = 1; i < n; i++) {
            if (A[i][x] > maior) {
                maior = A[i][x];
            }
        }
        printf("%d", maior);
    }

    return 0;

}

