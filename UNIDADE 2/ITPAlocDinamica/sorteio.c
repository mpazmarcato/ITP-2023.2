#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PARTICIPANTES 100

int main() {
    char **participantes = NULL;
    int N = 0;
    int i, sorteado, total_sorteado = 0;
    char nome[100];

    participantes = (char **)malloc(MAX_PARTICIPANTES * sizeof(char *));
    for (i = 0; i < MAX_PARTICIPANTES; i++) {
        participantes[i] = (char *)malloc(100 * sizeof(char));
    }

    while (1) {
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; 

        if (strcmp(nome, "acabou") == 0) {
            break;
        }

        if (N < MAX_PARTICIPANTES) {
            strcpy(participantes[N], nome);
            N++;
        }
    }

    int semente;
    scanf("%d", &semente);
    srand(semente);

    while (total_sorteado < N) {
        sorteado = rand() % N;
        if (participantes[sorteado][0] != '\0') {
            printf("%s\n", participantes[sorteado]);
            total_sorteado++;
            participantes[sorteado][0] = '\0'; 
        }
    }

    for (i = 0; i < MAX_PARTICIPANTES; i++) {
        free(participantes[i]);
    }
    free(participantes);

    return 0;
}