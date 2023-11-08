#include <stdio.h>
int main(){
    int N,M;
    char simbolo;
    int vegetacao = 0, agua = 0, deserto = 0, floresta = 0, hostil = 0;
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf(" %c", &simbolo);
        
        if (simbolo == '~'){
            agua++;
        } else if (simbolo == 'X'){
            hostil++;
        } else if (simbolo == '^'){
            deserto++;
        } else if (simbolo == '*'){
            floresta++;
        } else if (simbolo == '.'){
            vegetacao++;
        }
            
        }
    }
    
    if(agua >= N * M * 0.5 && floresta >= N * M * 0.2 && hostil == 0){
        printf("Planeta Classe M");
    } else if (hostil > 0){
        printf("Planeta Hostil");
    } else if (agua >= N * M * 0.85){
        printf("Planeta Aquático");
    } else if (deserto >= N * M * 0.6){
        printf("Planeta Desértico");
    } else if (vegetacao >= N * M * 0.65){
        printf("Planeta Selvagem");
    }  else {
        printf("Planeta Inóspito");
    }
    return 0;
}