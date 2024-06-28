
#include <stdio.h>

int main()
{
    int num, divisor;
    printf("Ingrese un numero entero para saber sus divisores: ");
    scanf("%d", &num);
    for(divisor=1; divisor<num; divisor++){
        if(num%divisor==0){
            printf("%d\n", divisor);
        }
    }
    return 0;
}

