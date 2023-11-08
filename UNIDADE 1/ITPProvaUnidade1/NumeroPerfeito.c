#include <stdio.h>
int numPerfeito(int X){
    int sumDiv = 0;
    for (int i = 0; i < X; i++){
        if(X %i==0){
            sumDiv += i;
        }
    }
    return sumDiv == X;
}

int main(){
    int N;
    int X;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &X);
        if (numPerfeito(X)){
        printf("%d eh perfeito", X);
        } else {
        printf("%d nao eh perfeito", X);
        }
    }
    return 0;
}


