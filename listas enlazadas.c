#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

int main() {
    Nodo* cabeza = NULL;
    Nodo* actual = NULL;

    int numero;

    printf("Ingrese números enteros (use -1 para terminar):\n");

    while (1) {
        scanf("%d", &numero);
        if (numero == -1) break;

        Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->valor = numero;
        nuevo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevo;
        } else {
            actual->siguiente = nuevo;
        }
        actual = nuevo;
    }


    printf("\nNúmeros ingresados:\n");
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if(temp->siguiente != NULL){
            printf("%d -> ", temp->valor);
            temp = temp->siguiente;
        }else{
            printf("%d", temp->valor);
            temp = temp->siguiente;
        }
    }
  
    return 0;
}