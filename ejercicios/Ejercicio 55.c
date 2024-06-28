
#include <stdio.h>
#include <stdio_ext.h>

int main()
{
    int n1, n2, n;
    char letra;
    
    printf("Ingrese el primer numero: ");
    __fpurge(stdin);
    scanf("%d", &n1);
    printf("Ingrese el segundo numero: ");
    __fpurge(stdin);
    scanf("%d", &n2);
    printf("Ingresa (p) para Par o (i) para Impar: ");
    __fpurge(stdin);
    scanf("%c", &letra);

    n = n1;
   
    if(letra=='p'){
        while(n2-1>n){
            n = n%2==0 ? n : n-1;
            n = n + 2;
            printf("%d\n", n);
        }
    }else if(letra=='i');{
        while(n2-2>=n){
            n = n%2==0 ? n-1 : n;
            n = n+2;
            printf("%d\n", n);
        }
    }
}


