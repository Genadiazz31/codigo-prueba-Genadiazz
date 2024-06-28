#include <stdio.h>

int main() {
    float num, suma = 0;
    int contador = 0;
    
    printf("Ingrese números para calcular el promedio (para finalizar ingrese 0):\n");
    while(1){
        scanf("%f", &num);
        
        if(num==0){
            break;
        } else{
        contador++;
        suma += num;
        }
    }
    printf("El promedio es: %f", suma/contador);
    return 0;
}