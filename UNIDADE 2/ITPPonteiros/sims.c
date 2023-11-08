#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void atualiza_status(int *fome, int *sede, int *banheiro, int *sono, int *tedio, int upfome, int upsede, int upbanheiro, int upsono, int uptedio);
int simula_sims(int *fome, int *sede, int *banheiro, int *sono, int *tedio);
int testa_fim(int *fome, int *sede, int *banheiro, int *sono, int *tedio);
void limita_atributos(int *fome, int *sede, int *banheiro, int *sono, int *tedio);
void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio);

int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d", &acoes);
    
    for(int i = 0; i < acoes; i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }
    
    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}

void atualiza_status(int *fome, int *sede, int *banheiro, int *sono, int *tedio, int upfome, int upsede, int upbanheiro, int upsono, int uptedio){
    *fome += upfome;
    *sede += upsede;
    *banheiro += upbanheiro;
    *sono += upsono;
    *tedio += uptedio;
}

int simula_sims(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    char comando[30];
    
    scanf(" %[^\n]", comando);
    
    if(strcmp(comando, "comer") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, 30, -5, -15, -5, -5);
    else if (strcmp(comando, "beber") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, -5, 30, -20, -5, -5);
    else if (strcmp(comando, "dormir") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, -30, -30, -30, 80, 30);
    else if (strcmp(comando, "se aliviar") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, -5, -5, 100, -5, -5);
    else 
        atualiza_status(fome, sede, banheiro, sono, tedio, -20, -20, -20, -20, 80);
    
    limita_atributos(fome, sede, banheiro, sono, tedio);
    
    return testa_fim(fome, sede, banheiro, sono, tedio);
}

int testa_fim(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    int vivo = 1;
    
    if(*fome <= 0){
        vivo = 0;
        printf("Game Over! Morreu de fome\n");
    }
    if(*sede <= 0){
        vivo = 0;
        printf("Game Over! Morreu de sede\n");
    }
    if(*banheiro <= 0){
        vivo = 0;
        printf("Game Over! Morreu apertado...\n");
    }
    if(*sono <= 0){
        vivo = 0;
        printf("Game Over! Morreu dormindo...\n");
    }
    if(*tedio <= 0){
        vivo = 0;
        printf("Game Over! Morreu deprimido...\n");
    }
    
    if (!vivo) return vivo;
    if (*fome <= 15) printf("Alerta: fome está com valor baixo\n");
    if (*sede <= 15) printf("Alerta: sede está com valor baixo\n");
    if (*banheiro <= 15) printf("Alerta: banheiro está com valor baixo\n");
    if (*sono <= 15) printf("Alerta: sono está com valor baixo\n");
    if (*tedio <= 15) printf("Alerta: tédio está com valor baixo\n");
    
    return vivo;
}

void limita_atributos(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    if(*fome > 100) *fome = 100;
    if(*sede > 100) *sede = 100;
    if(*banheiro > 100) *banheiro = 100;
    if(*sono > 100) *sono = 100;
    if(*tedio > 100) *tedio = 100;
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio){
    printf("Status final: \n");
    printf("Fome: %d\nSede: %d\nBanheiro: %d\nSono: %d\nTédio: %d\n", fome, sede, banheiro, sono, tedio);
}