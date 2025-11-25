
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50


void agregarpersona(void);
void verlista(void);
void vaciarlista(void);

void limpiarConsola(void) {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main()
{
	int opc;
	while(1) {
		printf("\nQue quiere hacer?\n 1 - Agregar cumpleanios\n 2 - Ver lista\n 3 - Vaciar lista\n 4 - Salir\n");
		scanf("%d", &opc);
		limpiarConsola();
		switch(opc) {
		case 1:
			agregarpersona();
			break;
		case 2:
			verlista();
			break;
		case 3:
			vaciarlista();
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}

void agregarpersona(void) {

	char nombre[MAX_CHAR];
	int anio, mes, dia;
	FILE *archivo;

	archivo = fopen("nombres.txt", "a");
	if(archivo==NULL) {
		printf("No se pudo abrir el archivo");
		return;
	}

	printf("\nIngrese el nombre: ");
	scanf(" %s", nombre);
	limpiarConsola();
	printf("\nIngrese el anio de nacimiento: ");
	scanf("%d", &anio);
	limpiarConsola();
	printf("\nIngrese el mes de nacimiento: ");
	scanf("%d", &mes);
	limpiarConsola();
	printf("\nIngrese el dia de nacimiento: ");
	scanf("%d", &dia);
	limpiarConsola();
	fprintf(archivo, "\n%s - %d / %d / %d", nombre, dia, mes, anio);
	printf("\nAgregado con exito!");

	fclose(archivo);
	return;
}

void verlista(void) {
	FILE *archivo;
	archivo = fopen("nombres.txt", "r");
	char linea[500];
	printf("Lista:\n");
	while (fgets(linea, sizeof(linea), archivo) != NULL) {
		printf("%s", linea);
	}
	printf("\n");
	fclose(archivo);
	return;
}

void vaciarlista(void) {
	FILE *archivo;
	archivo = fopen("nombres.txt", "w");
	fclose(archivo);
	printf("Lista vaciada con exito!\n");
	return;
}






