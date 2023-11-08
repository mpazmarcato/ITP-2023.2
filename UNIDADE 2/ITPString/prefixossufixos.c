#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d", &n);

    // Lê os prefixos e armazena em um vetor de strings
    char prefixos[n][11];
    for (int i = 0; i < n; i++) {
        scanf("%s", prefixos[i]);
    }

    scanf("%d", &m);

    // Lê os sufixos e armazena em um vetor de strings
    char sufixos[m][11];
    for (int i = 0; i < m; i++) {
        scanf("%s", sufixos[i]);
    }

    char palavra[101];
    
    while (scanf("%s", palavra) != EOF && strcmp(palavra, "-1") != 0) {
        int tam = strlen(palavra);
        int inicio = 0, fim = tam;

        // Verifica se a palavra possui algum prefixo
        for (int i = 0; i < n; i++) {
            int tamPrefixo = strlen(prefixos[i]);
            if (tam >= tamPrefixo && strncmp(palavra, prefixos[i], tamPrefixo) == 0) {
                inicio = tamPrefixo;
                break;
            }
        }

        // Verifica se a palavra possui algum sufixo
        for (int i = 0; i < m; i++) {
            int tamSufixo = strlen(sufixos[i]);
            if (tam >= tamSufixo && strcmp(palavra + tam - tamSufixo, sufixos[i]) == 0) {
                fim -= tamSufixo;
                break;
            }
        }

        // Verifica se a palavra após a remoção dos prefixos e sufixos é não vazia
        if (inicio < fim) {
            for (int i = inicio; i < fim; i++) {
                printf("%c", palavra[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
