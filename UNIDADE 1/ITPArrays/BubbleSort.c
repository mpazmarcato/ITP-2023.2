//Ordenação (bubble sort)
//Em várias situações, precisamos ordenar informações. Um dos algoritmos de ordenação mais simples (de implementar) realiza sucessivas trocas entre valores consecutivos levando, a cada iteração, o maior elemento para o fim da sequência. Assim, na primeira iteração, o maior elemento vai para sua posição ordenada (último). Na segunda iteração, o segundo maior vai para sua posição (penúltimo). Na terceira iteração, será a vez do antepenúltimo e assim por diante.
//Esse algoritmo, também conhecido como bubble sort, é descrito em pseudocódigo da seguinte forma:
//algoritmo bubble_sort(seja A um array de n valores)
   //repita
   //|  para i de 1 até n-1
   //|  |  se A[i-1] > A[i] então
   //|  |  |  troca os valores de A[i-1] e A[i]
   //|  |  fim_se
   //|  fim_para
   //enquanto houver troca de valores no laço interno
//fim_algoritmo
//Implemente este algoritmo e imprima o estado de uma sequência de valores para compreender como ele funciona.
//Entrada
//O seu programa deve ler da entrada-padrão um valor inteiro N seguido de N valores inteiros.
//Saída
//A saída consiste em várias linhas, cada uma contendo os valores da sequência na iteração corrente, durante a execução do algoritmo. A primeira linha deve imprimir a sequência original (não ordenada) enquanto a última linha deve imprimir os valores da sequência em ordem crescente.

#include <stdio.h>

void printArray(int n, int vector[n]) {
  for (int i = 0; i < n; i++) {
    printf("%i ", vector[i]);
  }
  printf("\n");
}

void putElements(int n, int v[n]) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

void shift(int vector[], int numberPosition, int minimumPosition) {
  if (vector[minimumPosition] != vector[numberPosition]) {
    int temp = vector[minimumPosition];
    vector[minimumPosition] = vector[numberPosition];
    vector[numberPosition] = temp;
  }
}

void bubbleSort(int vector[], int lenght) {

  for (int j = 0; j < lenght - 1; j++) {
    for (int i = 0; i < lenght - 1; i++) {
      if (vector[i] > vector[i + 1]) {
        shift(vector, i+1, i);
      }
    }
    printArray(lenght, vector);
  }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int v[n];
    putElements(n, v);
    printArray(n, v);
    bubbleSort(v,n);

}