#include <stdio.h>
int main (){
    int N;
    scanf("%d", &N);
    int piramide[N][N];
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            piramide[i][j];
        }
    }
    
    int topo = 1;
    int coluna = 0;
    int linha = 0;
    
    while (topo <= N / 2 + 1) {
        for (int i = coluna; i < N - coluna; i++) {
            piramide[linha][i] = topo;
            piramide[N - linha - 1][i] = topo;
        }
        for (int i = linha + 1; i < N - linha - 1; i++) {
            piramide[i][coluna] = topo;
            piramide[i][N - coluna - 1] = topo;
        }

        topo++;
        linha++;
        coluna++;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ",piramide[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}