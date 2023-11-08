#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time {
    char nome[30];
    int golsMarcados;
    int golsSofridos;
};

int compararTimes(const void *a, const void *b) {
    struct Time *timeA = (struct Time *)a;
    struct Time *timeB = (struct Time *)b;

    return timeB->golsMarcados - timeA->golsMarcados;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Time times[n];

    for (int i = 0; i < n; i++) {
        scanf(" %29[^\n]", times[i].nome);
        while ((getchar()) != '\n');
        scanf("%d", &times[i].golsMarcados);
        scanf("%d", &times[i].golsSofridos);

    }

    qsort(times, n, sizeof(struct Time), compararTimes);

    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].golsMarcados);
        printf("Gols sofridos: %d\n", times[i].golsSofridos);
    }

    return 0;
}
