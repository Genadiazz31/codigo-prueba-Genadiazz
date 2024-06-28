#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>

int main()
{   
    int j, n1, n2, f;
    char p1[100], p2[100];
    printf("Bienvenido, elige si quieres comparar palabras (1) o numeros (2)");
    scanf("%d", &j);
    __fpurge(stdin);
    switch(j){
        case 1:
            printf("Ingrese la primera palabra: ");
            scanf("%s", p1);
            __fpurge(stdin);
            printf("Ingrese la segunda palabra: ");
            scanf("%s", p2);
            __fpurge(stdin);
            f = strcmp(p1, p2);
            if(f==0){
                printf("Sus palabras son iguales");
            }else{
                printf("Sus palabras son diferentes");
            }
            break;
        case 2:
            printf("Ingrese el primer numero: ");
            scanf("%d", &n1);
            __fpurge(stdin);
            printf("Ingrese el primer numero: ");
            scanf("%d", &n2);
            __fpurge(stdin);
            f = n1 - n2;
            if(f==0){
                printf("Sus numeros son iguales");
            }else{
                printf("Sus numeros son diferentes");
        }
    }
    return 0;
}
