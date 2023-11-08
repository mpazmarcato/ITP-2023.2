#include <stdio.h>

int main(){
    int L;
    scanf("%d\n", &L);

    int C[L];
    for (int i = 0; i < L; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}














