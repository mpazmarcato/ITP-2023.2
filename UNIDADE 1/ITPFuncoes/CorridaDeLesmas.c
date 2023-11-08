#include <stdio.h>

int determinarNivel(int velocidade) {
    if (velocidade < 10) {
        return 1;
    } else if(velocidade >= 10 && velocidade < 20) {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int velocidades[N];
    
    for(int i = 0; i < N; i++){
        scanf("%d", &velocidades[i]);
    }
    
    int maiorNivel = 0;
    
    for (int i = 0; i < N; i++){
        int nivel = determinarNivel(velocidades[i]);
        if (nivel > maiorNivel){
            maiorNivel = nivel;
        }
    }
    printf("Level %d", maiorNivel);
    return 0;
}