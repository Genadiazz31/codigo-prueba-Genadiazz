#include <stdio.h>

int main(){
    float valor1, valor2;
    int forma;
    printf("Ingrese el numero correspondiente a la operacion que quiere hacer, suma 0, resta 1, producto 2, division 3, promedio 4, doble del primero menos la mitad del segundo 5\n");
    scanf ("%d", &forma);
    printf ("Ingrese el primer valor\n");
    scanf ("%f", &valor1);
    printf ("Ingrese el segundo valor\n");
    scanf ("%f", &valor2);
        switch (forma)
    {
        case 0:
            printf("Suma: %f", valor1+valor2);
            break;
        case 1:
            printf("Resta: %f", valor1-valor2);
            break;
        case 2:
            printf("Producto: %f", valor1*valor2);
            break;
        case 3:
            printf("Division: %f", valor1/valor2);
            break;
        case 4:
            printf("Promedio: %f", (valor1+valor2)/2);
            break;
        case 5:
            printf("Resultado: %f", (valor1*2)-(valor2/2));
            break;
        default:
            printf("No valido");
            break;
    }
    
}
