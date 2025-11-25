




#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARTAS_JUGADOR 21
#define MAX_CARTAS_DEALER 11


void limpiarConsola(void);
int cartasjugador[MAX_CARTAS_JUGADOR], cartasdealer[MAX_CARTAS_DEALER];
int darcarta(int carta);
void imprimircarta(int carta);
int manojugador(int vector[], int tamano, int carta, int apuesta, int saldo);
int manodealer(int vector[], int tamano, int carta);
int sumarcartas(int vector[], int tamano);
void vaciarvector(int vector[], int tamano)
{
	for (int i=0; i<tamano; i++) {
		vector[i] = 0;
	}
}

int main()
{
	srand(time(NULL));
	int apuesta, carta, saldo, historial;
	int ganadas, perdidas, empates;

	printf("Bienvenido a la mesa\n");
	FILE *archivo = fopen("saldo.txt", "r");
	if(archivo==NULL){
	    archivo = fopen("saldo.txt", "w");
	    historial=0;
	    fprintf(archivo, "%d", historial);
	}else{
	    fscanf(archivo, "%d", &historial);
	}
	fclose(archivo);
	printf("Historial: %d\n", historial);
	printf("Cuanto saldo desea ingresar?\n");
	scanf("%d", &saldo);
	int saldoinicial = saldo;
	limpiarConsola();
	while(1) {
		vaciarvector(cartasjugador, MAX_CARTAS_JUGADOR);
		vaciarvector(cartasdealer, MAX_CARTAS_DEALER);
		int x=0, sumajugador=0, sumadealer=0;
		if(saldo>0) {
			printf("\nQueres jugar esta mano?    1 - Si    2 - Salir\n");
			scanf("%d", &x);
			limpiarConsola();

			if (x==1) {
				int w=1, ultapuesta;
				while(w==1) {
					printf("\nCuanto quieres apostar? - 0 para repetir apuesta - 1 All in\n Saldo: $%d\n", saldo);
					scanf("%d", &apuesta);
					limpiarConsola();
					if(saldo<apuesta) {
						printf("Saldo insuficiente\n");
						
					} else {
						if(apuesta<0) {
							printf("Ingrese un numero valido\n");
						}else if(apuesta==0){
						    apuesta = ultapuesta;
						    w=0;
						}else if(apuesta==1){
						    apuesta = saldo;
						    w=0;
						} 
						else {
						    ultapuesta = apuesta;
							w=0;
						}
					}
				}
				limpiarConsola();
				printf("\nCarta dealer: ");
				cartasdealer[0] =  darcarta(carta);
				imprimircarta(cartasdealer[0]);
				printf("\nTus cartas: ");
				cartasjugador[0] = darcarta(carta);
				cartasjugador[1] = darcarta(carta);
				imprimircarta(cartasjugador[0]);
				imprimircarta(cartasjugador[1]);
				sumajugador=manojugador(cartasjugador, MAX_CARTAS_JUGADOR, carta, apuesta, saldo);
				if(sumajugador>100) {
					apuesta=apuesta*2;
					sumajugador=sumajugador-100;
				}
				if(sumajugador>21) {
					saldo=saldo-apuesta;
					printf("\nTe pasaste - Usted pierde\nSaldo: $%d", saldo);
					perdidas++;
				} else {
					if(cartasjugador[2]==0 && sumajugador==21) {
						saldo = saldo + apuesta*1.5;
						printf("\nBlackJack - Usted gana $%d\nSaldo: $%d", apuesta, saldo);
						ganadas++;
					} else {
						sumadealer=manodealer(cartasdealer, MAX_CARTAS_DEALER, carta);
						if(sumadealer>21) {
							printf("\nSe pasa el dealer: %d\n", sumadealer);
							saldo = saldo + apuesta;
							printf("\nUsted gana $%d\nSaldo: $%d", apuesta*2, saldo);
							ganadas++;
						} else {
							printf("\nSuma dealer: %d\n", sumadealer);
							if(sumadealer<sumajugador) {
								saldo = saldo + apuesta;
								printf("\nUsted gana $%d\nSaldo: $%d", apuesta*2, saldo);
								ganadas++;
							} else if(sumadealer==sumajugador) {
								printf("\nEmpate $%d\nSaldo $%d", apuesta, saldo);
								empates++;
							} else {
								printf("\nUsted pierde\nSaldo $%d", saldo-apuesta);
								saldo = saldo - apuesta;
								perdidas++;
							}
						}
					}
				}
			} else if(x==2) {
				printf("\nGracias por jugar!\n\n Saldo inicial: $%d\n Saldo actual: $%d\n Ganancia: x%d", saldoinicial, saldo, saldo/saldoinicial);
				printf("\nEstadisticas:\n Ganadas: %d\n Perdidas: %d\n Empates: %d", ganadas, perdidas, empates);
				archivo = fopen("saldo.txt", "w");
				historial = historial + (saldo - saldoinicial);
				fprintf(archivo, "%d", historial);
				fclose(archivo);

				return 0;
			}
		} else {
			printf("\n\nTe quedaste sin saldo - Gracias por jugar");
			printf("\nEstadisticas:\n Ganadas: %d\n Perdidas: %d\n Empates: %d", ganadas, perdidas, empates);
			archivo = fopen("saldo.txt", "w");
			historial = historial - saldoinicial;
			fprintf(archivo, "%d", historial);
			fclose(archivo);
			return 0;
		}
	}
}

int darcarta(int carta) {
	carta = rand() % 13 + 1;
	return carta;
}
const char* obtenerPaloAleatorio() {
    const char *palos[] = {"♠", "♥", "♦", "♣"};
    return palos[rand() % 4];
}

const char* obtenerValorCarta(int carta) {
    switch(carta) {
        case 1: return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: {
            static char buffer[3];
            snprintf(buffer, sizeof(buffer), "%d", carta);
            return buffer;
        }
    }
}

void imprimircarta(int carta) {
    const char* valor = obtenerValorCarta(carta);
    const char* palo = obtenerPaloAleatorio();

    printf("\n+-------+\n");
    printf("|%-2s     |\n", valor);   // Valor arriba izquierda
    printf("|   %s   |\n", palo);      // Palo al centro
    printf("|     %-2s|\n", valor);   // Valor abajo derecha
    printf("+-------+\n");
}

int manojugador(int vector[], int tamano, int carta, int apuesta, int saldo) {

	int sumajugador=0, x = 1;
	int i=2;
	sumajugador = sumarcartas(cartasjugador, MAX_CARTAS_JUGADOR);
	printf("\nTotal: %d", sumajugador);
	while (sumajugador<21 && x!=2 && x!=3) {
	    printf("\nApuesta: %d", apuesta);
		printf("    1 - Pedir    2 - Quedarse    3 - Doblar\n");
		scanf("%d", &x);
		if(x==3 && apuesta*2>saldo) {
			printf("Saldo insuficiente para Doblar\n");
			x=1;
		} else {
			limpiarConsola();
			if(x==3){
		        apuesta = apuesta*2;
		    }
		    printf("\nApuesta: %d", apuesta);
			printf("\nCarta dealer:");
			imprimircarta(cartasdealer[0]);
			printf("\nTus cartas:");
			if(x==1) {
				vector[i]=darcarta(carta);
				i++;
			} else if(x==3) {
				vector[i]=darcarta(carta);
				i=3;
			}
			for(int y=0; y<i; y++) {
				imprimircarta(vector[y]);
			}
			sumajugador = sumarcartas(cartasjugador, MAX_CARTAS_JUGADOR);
			printf("\nTu total : %d\n", sumajugador);
			if(x==3) {
				sumajugador=sumajugador+100;
			}
		}
	}
	return sumajugador;
}

int manodealer(int vector[], int tamano, int carta) {
	int i=1, sumadealer=0;
	vector[0];
	printf("\nMano dealer: ");
	imprimircarta(vector[0]);
	while (sumadealer < 17 && i < tamano) {
		vector[i] = darcarta(carta);
		imprimircarta(vector[i]);
		i++;
		sumadealer = sumarcartas(vector, i);
	}

	sumadealer = sumarcartas(cartasdealer, MAX_CARTAS_DEALER);
	return sumadealer;
}

int sumarcartas(int vector[], int tamano) {
	int suma = 0, ases = 0;

	for (int i = 0; i < tamano; i++) {
		int carta = vector[i];
		if (carta >= 11 && carta <= 13) {
			suma += 10;
		} else if (carta == 1) {
			suma += 11;
			ases++;
		} else {
			suma += carta;
		}
	}

	while (suma > 21 && ases > 0) {
		suma -= 10;
		ases--;
	}

	return suma;
}

void limpiarConsola() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

