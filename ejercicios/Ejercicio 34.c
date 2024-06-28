
#include <stdio.h>

int main()
{
    int n1, n2, R;
    printf("Para saber si la suma de sus numero ingreselos separados por una coma\n");
    scanf("%d, %d", &n1, &n2);
    R = (n1 + n2) % 2;
    if(R==1){
        printf("Su numero es impar");
    } else{
        printf("Su numero es par");
    }
    return 0;
}
