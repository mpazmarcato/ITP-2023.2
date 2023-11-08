#include <stdio.h>

int main (){
    int lines;
    char letter;
    
    scanf("%d %c", &lines, &letter);
    lines = lines - 2;
    for (int i = 0; i <= lines; i++) {
        for (int j = 0; j <= lines ; j++) {
            if (i == j || i+j == lines) {
                printf("%c", letter);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}