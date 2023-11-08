#include <stdio.h>

int main(){
    int number, digito;
    int divisor = 100000;
    int nonZeroFound = 0;
    
    scanf("%d\n", &number);
    
    while(divisor >= 1 && number > 0){ 
        digito = number / divisor; 
        
        if (digito != 0 || nonZeroFound) {
            printf("%d\n", digito);
            nonZeroFound = 1; 
        }

        number %= divisor; 
        divisor /= 10; 
        
    }
    
    return 0;
}