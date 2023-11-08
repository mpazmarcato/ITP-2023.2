#include <stdio.h>
#include <string.h>

-finalizado
void decifrar(int key[], char text[], const char S[]){
    int indice = 0;
    char C[200] = {0};

    for (int i = 0; i < strlen(text); i++){
        for (int j = 0; j < 40; j++){
            if(text[i] == S[j]){
                if(j- key[i]<0){
                    indice= j - key[i] + 40;
                }
                else{
                    indice = j - key[i];
                }
                C[i] = S[indice];
            }
        }
        
    }

    for (int k = 0; k < 4; k++){
        printf("%d", key[k]);
    }
    printf("\n");
    
    printf("%s", C);
    
}

void ordem(int ordem, int chave[], char mensagem[], const char S[]){
    int K[200] = {0}, i = 0, aux = 0;

    if(ordem == 4){
        K[0] = chave[0];	
		K[1] = chave[1];
	    K[2] = chave[2];
		K[3] = chave[3];
    }
    else if(ordem == 1){
        K[0] = chave[3];	
		K[1] = chave[0];
	    K[2] = chave[1];
		K[3] = chave[2];
    }
    else if(ordem == 2){
        K[0] = chave[2];	
		K[1] = chave[3];
	    K[2] = chave[0];
		K[3] = chave[1];
    }
    else if(ordem == 3){
        K[0] = chave[1];	
		K[1] = chave[2];
	    K[2] = chave[3];
		K[3] = chave[0];
    }

    for (i = 4; i < strlen(mensagem); i++){
        K[i] = K[aux];
        aux++;

        if(aux >= 4){
            aux = 0;
        }
    }

    decifrar(K, mensagem, S);
    
}

void chave(char cripto[], const char S[], int original[]){
    int inicio = 0, final = 8, a = 0, control = 0, aux = 0, m = 0, tamanho = 0, posicao = 0;
    int K[8] ={0};

    tamanho = (int)strlen(cripto) - 9;

    for (int p = 0; p < tamanho; p++){
        if(posicao == 4){
            posicao = 0;
        }
        if(m != 1){
            for (int i = inicio; i < final; i++){
                for (int j = 0; j < 40; j++){
                    if(cripto[i] == S[j]){
                        a = j;
                    }
                }
                K[aux] = a - original[aux];
                if(a - original[aux] < 0){
                    K[aux] = a - original[aux] +40;
                }
                aux++;
            }
            aux = 0;
            
            for (int k = 0; k < 4; k++){
                if(K[k] == K[k+4]){
                    control++;
                }
            }
            
            if(control == 4){
                m = 1;
            }
            //ATUALIZAÇÃO DO LOOP
            else{
                inicio++;
                final++;
                a = 0;
                control = 0;
            }
        }
        posicao++;
    }

    if(m != 1){
        printf("Mensagem nao e da Resistencia!");
    }
    else{
        ordem(posicao, K, cripto, S);
    }
    
}

int main(){
    const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
    const char KP[] = {'Q', 'U', 'E', ' ', 'A', ' ', 'F', 'O', '\0'};
    char C[200] = {0};
    int KP[9] = {0};

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 40; j++){
            if(KP[i] == S[j]){
                KP[i] = j;
            }
        }
    }

    fgets(C, 200, stdin);
    
    chave(C, S, KP);

    return 0;
}