#include <stdio.h>
#include <string.h>
#include <ctype.h>

--finalizado
const char S[] =
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

void encriptografado(char mensagem[], const char chave[]){
   int tamanhoMensagem = strlen(mensagem);
   int tamanhoChave = strlen(chave);

   for(int i = 0; i < tamanhoMensagem; i++){
        char mensagemChar = mensagem[i];
        char chaveChar = chave[i % tamanhoChave];
         int shift = chaveChar - '0';
        for (int j = 0; j < sizeof(S); j++) {
            if(mensagemChar == S[j]){
              int position = (j + shift) % sizeof(S);
              mensagem[i] = S[position];
              break;
            }
        }
    }
}

int chaveValida(const char chave[]) {
    if (strlen(chave) != 4)
        return 0;
    for (int i = 0; i < 4; i++) {
        if (!isdigit(chave[i]))
            return 0;
    }
    return 1;
}

int mensagemValida(const char mensagem[]) {
    for (int i = 0; i < strlen(mensagem); i++) {
        int validaChar = 0;
        for (int j = 0; j < sizeof(S); j++) {
            if (mensagem[i] == S[j]) {
                validaChar = 1;
                break;
            }
        }
        if (!validaChar)
            return 0;
    }
    return 1;
}

int main (){
    char chave[5];
    char mensagem[201];

    scanf("%s", chave);
    
    if (!chaveValida(chave)) {
        printf("Chave invalida!\n");
        return 1;
    }

    getchar(); 
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0'; 

    if (!mensagemValida(mensagem)) {
        printf("Caractere invalido na entrada!\n");
        return 1;
    }

    encriptografado(mensagem, chave);

    printf("%s", mensagem);
    return 0;

}