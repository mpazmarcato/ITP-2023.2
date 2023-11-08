#include <stdio.h>

int main (){
    char letra;
    int temperatura;
    float celsius, farenheit, kelvin;
    
    scanf("%d %c",&temperatura, &letra);
    
    if (letra == 'C'){
        celsius = temperatura;
        farenheit = (celsius * 1.8) + 32;
        kelvin = celsius + 273.15;
        printf("Celsius: %.2f\n", celsius);
        printf("Farenheit: %.2f\n", farenheit);
        printf("Kelvin: %.2f\n", kelvin);
        
    } else if (letra == 'F'){
        farenheit = temperatura;
        celsius = (farenheit - 32)/1.8;
        kelvin = (5 * (farenheit - 32) )/9 + 273.15;
        printf("Celsius: %.2f\n", celsius);
        printf("Farenheit: %.2f\n", farenheit);
        printf("Kelvin: %.2f\n", kelvin);
        
    } else {
        kelvin = temperatura;
        celsius = kelvin - 273.15;
        farenheit = (9*(kelvin - 273.15))/5 + 32;
        printf("Celsius: %.2f\n", celsius);
        printf("Farenheit: %.2f\n", farenheit);
        printf("Kelvin: %.2f\n", kelvin);
    }
    return 0;
}