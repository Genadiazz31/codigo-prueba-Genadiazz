#include <stdio.h>

int main()
{
    int num, lim, mul;
    printf("Bienvenido, en este programa podra ver la tabla de multiplicacion del numero que quiera\n");
    printf("Ingrese el numero que quiere saber la tabla\n");
    scanf("%d", &num);
    printf("Ingrese el hasta que numero quiere la tabla\n");
    scanf("%d", &lim);
    while(mul!=lim+1){
        printf("%d x %d = %d\n", num, mul, num*mul);
        mul++;
    }
    return 0;
}
