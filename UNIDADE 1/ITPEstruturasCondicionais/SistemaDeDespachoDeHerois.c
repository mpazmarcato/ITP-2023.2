#include <stdio.h>
int main() {
    int numHeroes, heroClass, threatLevel;
    scanf("%d %d %d", &numHeroes, &heroClass, &threatLevel);
    
    if (numHeroes == 0) {
        printf("Melhor chamar Saitama!");
    } else {
        if (threatLevel == 1) {
           if (heroClass >= 2 || (numHeroes >= 3 && heroClass >= 1)) {
            printf("Heróis vencerão!");
           } else {
            printf("Melhor chamar Saitama!");
           }
        } else if (threatLevel == 2) {
           if (heroClass >= 3 || (numHeroes >= 3 && heroClass >= 2)) {
            printf("Heróis vencerão!");
            } else {
            printf("Melhor chamar Saitama!");
            }
        } else if (threatLevel == 3) {
           if (heroClass >= 4 || (numHeroes >= 3 && heroClass >= 3)) {
            printf("Heróis vencerão!");
           } else {
            printf("Melhor chamar Saitama!");
           }
        } else if (threatLevel == 4) {
           if (heroClass == 5 || (numHeroes >= 3 && heroClass >= 4)) {
            printf("Heróis vencerão!");
           } else {
            printf("Melhor chamar Saitama!");
           }
        } else if (threatLevel == 5) {
           if (heroClass == 5) {
            printf("Heróis vencerão!");
           } else {
            printf("Melhor chamar Saitama!");
           }
        }
    }
    return 0;
}