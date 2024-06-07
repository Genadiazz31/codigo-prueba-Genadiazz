#include <stdio.h>
#include <math.h>

int main()
{
    int horas, dias, antiguedad;
    printf("Bienvenido al programa para calcular su sueldo\n");
    printf("Ingrese las horas que trabaja al dia: ");
    scanf("%d", &horas);
    printf("Ingrese los dias que trabaja a la semana: ");
    scanf("%d", &dias);
    printf("Ingrese la cantidad de años que lleva trabajando: ");
    scanf("%d", &antiguedad);
    printf("Su sueldo ronda los $%f", horas*dias*4500*3.5*(1+0.02*antiguedad));
    
    return 0;
}
