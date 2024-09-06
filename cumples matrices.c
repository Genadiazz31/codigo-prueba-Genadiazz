
#include <stdio.h>
#define MAX_CUMPLES 30

struct Fecha {
	char nombre[10];
	int dia;
	int mes;
	int anio;
} cumples[MAX_CUMPLES];

int cumpleanos(void);
void imprimirCumpleanos(void);

int main()
{
	int x, i=0;
	while(1) {
		printf("Que desea hacer?\n1 - Agregar un cumpleanos\n2 - Ver lista de cumpleanos\n");
		scanf("%d", &x);

		if(x==1) {
			cumpleanos();
		} else if(x==2) {
			imprimirCumpleanos();
		}
	}
return 0;
}
int cumpleanos() {
    static int i=0;

	
	printf("Ingrese su nombre: ");
	scanf("%s", cumples[i].nombre);
	
	printf("Ingrese el anio de su cumpleanios: ");
	scanf("%d", &cumples[i].anio);
	
	printf("Ingrese el mes de su cumpleanios: ");
	scanf("%d", &cumples[i].mes);
	
	printf("Ingrese el dia de su cumpleanios: ");
	scanf("%d", &cumples[i].dia);
	
	i++;
	return 0;
}

void imprimirCumpleanos(){
    for(int j=0 ; j < MAX_CUMPLES ; j++){
        if(cumples[j].dia!=0)
        printf("%s: %d/%d/%d\n", cumples[j].nombre, cumples[j].dia, cumples[j].mes, cumples[j].anio);
    }
    return 0;
}



