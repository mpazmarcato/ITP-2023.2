#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int conjuntoA[N], conjuntoB[M];
  
    for (int i = 0; i < N; i++) {
        scanf("%d", &conjuntoA[i]);
    }
 
    for (int i = 0; i < M; i++) {
        scanf("%d", &conjuntoB[i]);
    }
   
    int resultado[100]; 
    int tamanhoResultado = 0; 
    
    // Verificar os elementos do conjunto A
    for (int i = 0; i < N; i++) {
        int pertenceA = 1; 
        
        for (int j = 0; j < M; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                pertenceA = 0;
                break;
            }
        }
        
        if (pertenceA) {
            resultado[tamanhoResultado] = conjuntoA[i];
            tamanhoResultado++;
        }
    }
    
    // Verificar os elementos do conjunto B
    for (int i = 0; i < M; i++) {
        int pertenceB = 1; 
        
        // Verificar se o elemento também está em A
        for (int j = 0; j < N; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                pertenceB = 0; 
                break;
            }
        }
        
        if (pertenceB) {
            resultado[tamanhoResultado] = conjuntoB[i];
            tamanhoResultado++;
        }
    }
   
    for (int i = 0; i < tamanhoResultado - 1; i++) {
        for (int j = i + 1; j < tamanhoResultado; j++) {
            if (resultado[i] > resultado[j]) {
                int temp = resultado[i];
                resultado[i] = resultado[j];
                resultado[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < tamanhoResultado; i++) {
        printf("%d ", resultado[i]);
    }
    
    printf("\n");
    
    return 0;
}