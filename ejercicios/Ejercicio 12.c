#include <stdio.h>

int main()
{
    int dia, mes, año, diav, mesv, añov;
    printf("Ingrese su año de nacimiento: ");
    scanf("%d", &año);
    printf("Ingrese su mes de nacimiento: ");
    scanf("%d", &mes);
    printf("Ingrese su dia de nacimiento: ");
    scanf("%d", &dia);
    
   // imaginando que hoy es 31/5/2024 //
   
    if(mes>0 && mes<13 && dia>0 && dia<32 && año>1900 && año<2025)
    {
        if((mes-5)<0)
        {
            printf("Has vivido %d dias %d meses %d años",31-dia,5-mes,2024-año);
        }
            else
            {
            printf("Has vivido %d dias %d meses %d años", 31-dia, 17-mes, 2023-año);
            }
        
    }
}
