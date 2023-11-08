#include <stdio.h>

int main() {
    int groups, c = 0, s = 0, l = 0, total = 0;
    char category;
    
    scanf("%d", &groups);
    
    for (int i = 0; i < groups; i++) {
        while (1) {
            scanf(" %c", &category);  
            if (category == 'F') {
                break;  
            }
            switch (category) {
                case 'C': c++; break;
                case 'S': s++; break;
                case 'L': l++; break;
            }
        }
    }
    
    total = c + s + l;
    printf("%d %d %d %d", c, s, l, total);
    
    return 0;
}