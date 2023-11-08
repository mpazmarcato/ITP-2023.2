#include <stdio.h>

int main(){
    int total, num1, num2, sum;
    
    total = num1 = num2 = sum =0;
    
    scanf("%d", &total);
    
    if (total > 0) {
        for (num1 = 1; num2 <= total; num1++){
            for (num2 = 1; num2 <= num1; num2++){
                sum = sum + 1;
                if (sum < 10){
                    printf(" %d ", sum);
                } else {
                    printf("%d ", sum);
                }
            }
        printf("\n");
        }
    } else {
        printf("Você entrou com %d, tente de novo na próxima", total);
    }
    
  return 0;  
}
