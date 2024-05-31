
#include <stdio.h>

int main()
{
    int h1, h2, m1, m2, s1, s2, h3, m3, s3;
    printf("Ingrese el primer tiempo expreseado en horas, minutos y segundos\n");
    scanf("%d %d %d", &h1, &m1, &s1);
    printf("Ingrese el segundo tiempo\n");
    scanf("%d %d %d", &h2, &m2, &s2);
        
        if((s1+s2)>60){
            m3=m1+m2+1;
            s3=(s1+s2)-60;
        } 
        else{
            m3=m1+m2;
        }
        if(m3>60){
            h3=h1+h2+1;
            m3=m3-60;
        }
    printf("%d horas %d minutos %d segundos", h3, m3, s3);
    return 0;
}
