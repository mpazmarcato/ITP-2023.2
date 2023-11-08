#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 50

struct Pessoa {
    char nome[MAX_NOME];
    int idade;
    char sexo;
};

struct Pessoa criar(char nome[], int idade, char sexo) {
    struct Pessoa novaPessoa;
    strcpy(novaPessoa.nome, nome);
    novaPessoa.idade = idade;
    novaPessoa.sexo = sexo;
    return novaPessoa;
}

void inserir(struct Pessoa pessoas[], int *count, struct Pessoa novaPessoa) {
    pessoas[*count] = novaPessoa;
    (*count)++;
}

void deletar(struct Pessoa pessoas[], int *count, struct Pessoa pessoaParaDeletar) {
    for (int i = 0; i < *count; i++) {
        if (pessoas[i].idade != -1 && strcmp(pessoas[i].nome, pessoaParaDeletar.nome) == 0 &&
            pessoas[i].idade == pessoaParaDeletar.idade &&
            pessoas[i].sexo == pessoaParaDeletar.sexo) {
            for (int j = i; j < *count - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }
            (*count)--;
            i--;
        }
    }
}

void imprimir(struct Pessoa pessoas[], int count) {
    for (int i = 0; i < count; i++) {
        if (pessoas[i].idade != -1) {
            printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
        }
    }
}

int main() {
    struct Pessoa *pessoas = (struct Pessoa *)malloc(100 * sizeof(struct Pessoa));
    if (pessoas == NULL) {
        fprintf(stderr, "Erro ao alocar memória para pessoas.\n");
        exit(1);
    }
    int count = 0;
    char op;

    do {
        scanf(" %c", &op);
        if (op == 'i') {
            char nome[MAX_NOME];
            int idade;
            char sexo;
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            struct Pessoa novaPessoa = criar(nome, idade, sexo);
            inserir(pessoas, &count, novaPessoa);
        } else if (op == 'd') {
            char nome[MAX_NOME];
            int idade;
            char sexo;
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            struct Pessoa pessoaParaDeletar = criar(nome, idade, sexo);
            deletar(pessoas, &count, pessoaParaDeletar);
        } else if (op == 'p') {
            imprimir(pessoas, count);
        }
    } while (op != 'p');

    free(pessoas); 
    return 0;
}