#include <stdio.h>
int main() {
    float speedAv = 0.0;
    float speed = 0.0;
    int athletes = 0;
    int series = 0;

    scanf("%f", &speedAv);
    
    while (speed != -1.0) {
        scanf("%f", &speed);
        
        if (speed <= speedAv) {  
            athletes += 1;
        } else if (speedAv == 0) {
            printf("erro");
            return 1;  
        }
    }
    
    athletes -= 1;

    if (athletes % 8 == 0) {
        series = athletes / 8;
    } else {
        series = (athletes / 8) + 1;
    }

    printf("%d %d", athletes, series);

    return 0;  
}
