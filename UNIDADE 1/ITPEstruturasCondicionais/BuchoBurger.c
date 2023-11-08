#include <stdio.h>

int main(){
    int numero, dinheiro, troco, valorCombo;
    int precos[] = {12, 23, 31, 28, 15};
    
    scanf("%d %d", &numero, &dinheiro);
    
    if (numero >= 1 && numero <=5) {
        valorCombo = precos[numero-1];
        troco = dinheiro - valorCombo;
        
        if(troco == 0) {
        printf("Deu certim!");
        
        } else if(troco > 0){
            printf("Troco = %d reais\n", troco);
            
        } else {
         printf("Saldo insuficiente! Falta %d reais", -troco);
            
        }
    } else {
        printf("Invalido");
    }
    return 0;
}