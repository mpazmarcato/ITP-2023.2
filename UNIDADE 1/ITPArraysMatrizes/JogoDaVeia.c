#include <stdio.h>
int vencedor(char tabuleiro[3][3], int X, int Y, char jogador){
    //linha horizontal
    for (int i = 0; i < 3; i++) { 
        if (tabuleiro[X][0] == jogador && tabuleiro[X][1] == jogador && tabuleiro[X][2] == jogador) {
        return 1;
        }
    }
    //coluna vertical
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][Y] == jogador && tabuleiro[1][Y] == jogador && tabuleiro[2][Y] == jogador) {
        return 1;
        }
    }
    //diagonais
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((X == Y && tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) || 
            (X + Y == 2 && tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
                return 1;
            }
        }    
    }
    return 0;
}
int main(){
    char tabuleiro[3][3];
    int N, X, Y;
    char SIMB;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d %d %c", &X, &Y, &SIMB);
        X--;
        Y--;
        
        if(tabuleiro[X][Y] != '.'){
            printf("Jogada inválida!\n");
        } else {
            tabuleiro[X][Y] = SIMB;
            if(vencedor(tabuleiro, X, Y, SIMB)){
                printf("Boa jogada, vai vencer!\n");
            } else {
                printf("Continua o jogo.\n"); 
            }
            tabuleiro[X][Y] = '.';
        }
        
    }
    return 0;
    
}