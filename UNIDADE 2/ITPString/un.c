#include <stdio.h>
#include <string.h>

#define TAMCHAVE 4
#define TAMMAXMENSAGEM 200

///Conjunto de simbolos
char S[]={'0','1','2','3','4','5','6','7','8','9',
          'A','B','C','D','E','F','G','H','I','J',
          'K','L','M','N','O','P','Q','R','S','T',
          'U','V','W','X','Y','Z','.',',','?',' '};

/*
Encontra o indice de um caractere no conjunto de simbolos.
Retorna -1 caso o caractere nao exista no conjunto de simbolos.
*/
int achaindice(char c) {
    for (int i = 0; i < 40; i++) if (S[i]==c) return i;
    return -1;
}

/*
Retorna o caractere do conjunto de simbolos correspondente
a um indice informado.
*/
char achasimbolo(int i) {
    while (i<0) i+=40;
    return S[i%40];
}

/**
Cifra (criptografa) a mensagem PT utilizando a chave
informada.
*/
int cifra(char PT[], int chave[]) {
    int tamPT=strlen(PT);
    for (int i=0; i<tamPT; i++) {
        int poschave=i%TAMCHAVE;
        int indice=achaindice(PT[i]);
        if (indice<0) return -1;
        PT[i]=achasimbolo(indice+chave[poschave]);
    }
    return 0;
}

int main() {
    int chave_int;
    // Vetor de chaves de um digito
    int chave[TAMCHAVE]={0};
    // Texto plano
    char PT[TAMMAXMENSAGEM];

    scanf("%d ", &chave_int);

    fgets(PT,TAMMAXMENSAGEM,stdin);

    // Conversao da chave inteira em vetor de digitos
    for (int i=TAMCHAVE-1; i>=0 && chave_int>0; i--) {
        chave[i]=chave_int%10;
        chave_int/=10;
    }

    // Caso ainda exista valor a ser convertido, a chave
    // esta fora do padrao.
    if (chave_int) {
        printf ("Chave invalida!\n");
        return 1;
    }

    //remocao do \n ao final da mensagem
    PT[strlen(PT)-1]=0;

    int falha=cifra(PT,chave);

    if (falha) printf("Caractere invalido na entrada!\n");
    else printf("%s\n", PT);
}