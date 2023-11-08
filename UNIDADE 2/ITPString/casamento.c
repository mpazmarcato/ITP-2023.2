#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

void patternSearchOriginal(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int i = 0;
    int found = 0;  // Flag para indicar se o padrão foi encontrado

    while (i <= n - m) {
        int match = 1;

        for (int j = 0; j < m; j++) {
            printf("%c ", text[i + j]);

            if (text[i + j] != pattern[j]) {
                match = 0;
                printf("não\n");
                break;
            }
        }

        if (match) {
            printf("sim\nAchei o padrão no índice %d\n", i);
            i += m;  // Avança para a próxima posição após o padrão
            found = 1;  // Marcamos que o padrão foi encontrado
        } else {
            i++;
        }
    }

    if (!found) {
        printf("Não achei o padrão\n");
    }
}

int main() {
    char text[MAX_LENGTH];
    char pattern[MAX_LENGTH];

    fgets(text, MAX_LENGTH, stdin);
    fgets(pattern, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    patternSearchOriginal(text, pattern);

    return 0;
}

#include <stdio.h>
#include <string.h>
int main() {
    int casamento = 0;
    int fim = 0;
    int indice = -1;
    char eString[51];
    char pString[51];
    scanf("%s", eString);
    scanf("%s", pString);
    int comprimentoE = strlen(eString);
    int comprimentoP = strlen(pString);
    
    for (int i = 0; i < comprimentoE; i++) {
        int j =0;
        while (j < comprimentoP && eString[i + j] == pString[j]) {
            printf("%c ", eString[i + j]);
            j++;
        }
        if (j == comprimentoP){
            printf("sim\n");
            casamento = 1;
            indice = i;
            break;
        }
        else{
            printf("%c ", eString[i + j]);
            printf("não\n");
            char caractere = eString[j + i];
            char *resultado = strchr(pString, caractere);
            if (resultado == NULL) {
                i = i + j;
            }
            if ((i + comprimentoP) > comprimentoE - 1){
                printf("Não achei o padrão");
                fim = 1;
                break;
            }
            continue;
        }
    }
    if (casamento == 0){
        if (fim == 0){
        printf("Não achei o padrão");
        }
    }
    else{
        printf("Achei o padrão no índice %d", indice);
    }
    return 0;
}