
#include <stdio.h>

int main()
{
    int num, divisor = 1, R=0;
    printf("Ingrese un numero entero para saber la suma de sus cifras: ");
    scanf("%d", &num);
    
    while(num>0){
        R = R + (num % 10);
        num = num / 10;
    }
    
    printf("La suma de las cifras es %d", R);
    
    return 0;
}


