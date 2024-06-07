#include <stdio.h>

int main()
{
    char v1, v2, v3, f1, f2, f3;
    printf("Ingrese las letras que quieres ordenar\n");
    scanf("%c %c %c", &v1, &v2, &v3);

    if(v1 > v2){
            f1 = v1 > v3 ? v1 : v3;
        } else{
                f1 = v2 > v3 ? v2 : v3;
            }
    if(v1 > v2){
            f2 = v2 > v3 ? v2 : (f2 = v3 > v1 ? v1 : v3);
        } else{
                f2 = v2 < v3 ? v2 : (f2 = v1 > v3 ? v1 : v3);   
            }
    if(v1 > v2){
            f3 = v2 < v3 ? v2 : v3;
        } else {
                f3 = v1 > v3 ? v3 : v1;
            }
    
    printf("%c %c %c", f3, f2, f1);
    return 0;
} 

