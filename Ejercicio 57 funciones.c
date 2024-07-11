#include <stdio.h>

int mayorDeDos(void);

int main() 
{
    int R = mayorDeDos();
    if(R==1)
    {
        printf("El primer numero es mayor");
    } else if(R==2) 
    {
        printf("El segundo numero es mayor");
    } else if(R==3)
    {
        printf("Sus numero son iguales");
    }
    
}
int mayorDeDos()

{
    int n1, n2;
    printf("Ingrese el primer valor: ");
    scanf("%d", &n1);
    printf("Ingrese el segundo valor: ");
    scanf("%d", &n2);
    
    if(n1>n2)
        {
            return 1;
    }else if(n2>n1){
            return 2;
    } else {
            return 3;
        }
        
    
}