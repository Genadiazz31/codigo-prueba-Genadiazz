
#include <stdio.h>

int main()
{
    int peso, envio, preciokg, precioenv;
    printf("Calcula el costo del envío\n");
    printf("Ingrese el peso de la mercaderia\n");
    scanf("%d", &peso);
    printf("Ingrese si es un envio de corta (1) o larga distancia (2)\n");
    scanf("%d", &envio);
    
    precioenv = (envio == 1) ? 1500 : ((envio == 2) ? 2000 : (printf("No valido\n"), 0));
    if(peso>20){
        preciokg = (envio == 1) ? (peso - 20) * 800 : ((envio == 2) ? ((peso - 20) / 5) * 800 : (printf("No valido\n"), 0));
    }
    printf("El costo del envio es %d",preciokg + precioenv);
    return 0;
}


