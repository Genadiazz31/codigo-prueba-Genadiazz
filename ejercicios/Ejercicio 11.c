
#include <stdio.h>

int main()
{
    float val;
    int entrada;
    
    printf("Ingrese el numero correspondiente a lo que quiere convertir\n");
    printf("Ingrese 0 para centimetros\n");
    printf("Ingrese 1 para pulgadas\n");
    printf("Ingrese 2 para pies\n");
    scanf("%d", &entrada);
    
    switch(entrada) 
    {
        case 0:
            printf("Ingrese el valor en centimetros\n");
            scanf("%f", &val);
            printf("En pulgadas:%f\n", val/2.54);
            printf("En pies:%f\n", val/30.48);
            break;
        case 1:
            printf("Ingrese el valor en pulgadas\n");
            scanf("%f", &val);
            printf("En centimetros: %f\n", val*2.54);
            printf("En pies: %f\n", val/12);
            break;
        case 2:
            printf("Ingrese el valor en pies\n");
            scanf("%f", &val);
            printf("En centimetros: %f\n", val*30.48);
            printf("En pulgadas: %f\n", val*12);
            break;
        default:
            printf("No valido");
            break;
    }
    return 0;
    
}

