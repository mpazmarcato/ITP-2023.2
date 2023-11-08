#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int pontos, jogos, vitorias, empates, derrotas, gols_pro, gols_contra, saldo_gols;
} Time;

int calcularPontos(int vitorias, int empates) {
    return (vitorias * 3) + empates;
}

int compararTimes(const void *a, const void *b) {
    const Time *timeA = (const Time *)a;
    const Time *timeB = (const Time *)b;

    if (timeA->pontos != timeB->pontos) {
        return timeB->pontos - timeA->pontos;
    }
    
    if (timeA->vitorias != timeB->vitorias) {
        return timeB->vitorias - timeA->vitorias;
    }

    if (timeA->saldo_gols != timeB->saldo_gols) {
        return timeB->saldo_gols - timeA->saldo_gols;
    }

    return timeB->gols_pro - timeA->gols_pro;
}

int main() {
    int numTimes;
    scanf("%d", &numTimes);
    getchar();

    Time times[numTimes];

    for (int i = 0; i < numTimes; i++) {
        char linha[100];
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%[^;]; %d %d %d %d %d", times[i].nome, &times[i].vitorias, &times[i].empates, 
        &times[i].derrotas, &times[i].gols_pro, &times[i].gols_contra);
        times[i].pontos = calcularPontos(times[i].vitorias, times[i].empates);
        times[i].jogos = times[i].vitorias + times[i].empates + times[i].derrotas;
        times[i].saldo_gols = times[i].gols_pro - times[i].gols_contra;
    }
    
    qsort(times, numTimes, sizeof(Time), compararTimes);

    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    for (int i = 0; i < numTimes; i++) {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", times[i].nome, times[i].pontos, times[i].jogos, times[i].vitorias,
         times[i].empates, times[i].derrotas, times[i].gols_pro, times[i].gols_contra, times[i].saldo_gols);
    }

    int zonaLibertadores = (numTimes >= 6) ? 6 : numTimes;
    int rebaixados = (numTimes >= 4) ? 4 : numTimes;

    printf("\nTimes na zona da libertadores:\n");
    for (int i = 0; i < zonaLibertadores; i++) {
        printf("%s\n", times[i].nome);
    }

    printf("\nTimes rebaixados:\n");
    for (int i = numTimes - 1; i >= numTimes - rebaixados; i--) {
        printf("%s\n", times[i].nome);
    }

    return 0;
}