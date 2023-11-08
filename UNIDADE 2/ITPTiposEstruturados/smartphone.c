#include <stdio.h>
#include <string.h>

struct Smartphone {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
};

int cadastraSmartphone(int qnt_cadastrada, struct Smartphone phones[]) {
    scanf(" %[^\n]s", phones[qnt_cadastrada].modelo);
    scanf("%d", &phones[qnt_cadastrada].memoria);
    scanf("%f", &phones[qnt_cadastrada].processador);
    scanf("%f", &phones[qnt_cadastrada].camera);
    scanf("%f", &phones[qnt_cadastrada].bateria);

    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, struct Smartphone phones[], struct Smartphone reqMin) {
    int encontrados = 0;
    
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoria &&
            phones[i].processador >= reqMin.processador &&
            phones[i].camera >= reqMin.camera &&
            phones[i].bateria >= reqMin.bateria) {
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria);
            encontrados++;
        }
    }
    
    return encontrados;
}

int main() {
    struct Smartphone smartphones[100];
    int qnt_cadastrada = 0;
    char resposta;

    do {
        scanf(" %c", &resposta);

        if (resposta == 's') {
            qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, smartphones);
        }
    } while (resposta == 's');

    struct Smartphone reqMin;
    scanf("%d", &reqMin.memoria);
    scanf("%f", &reqMin.processador);
    scanf("%f", &reqMin.camera);
    scanf("%f", &reqMin.bateria);

    int encontrados = pesquisaSmartphones(qnt_cadastrada, smartphones, reqMin);

    printf("%d smartphones encontrados.\n", encontrados);

    return 0;
}