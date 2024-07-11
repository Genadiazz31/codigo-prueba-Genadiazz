#include <stdio.h>
int menu, precio, mas = 1;
int Hamburguesas (void);
int Desayuno (void);
int Helados (void);
int Bebidas (void);
void Pagar (void);
int Combo (void);

int
main ()
{
  printf ("Bienvenido al menu de McDonalds\n");
  while (mas == 1)
	{
	  printf ("Ingrese que menu quiere ver\n");
	  printf
		("Ingrese\n1 - Hamburguesas\n2 - Desayuno\n3 - Helados\n4 - Bebidas\n");
	  scanf ("%d", &menu);
	  switch (menu)
		{
		case 1:
		  precio = Hamburguesas ();
		  break;
		case 2:
		  precio = Desayuno ();
		  break;
		case 3:
		  precio = Helados ();
		  break;
		case 4:
		  precio = Bebidas ();
		  break;
		}
	  printf ("Precio Total: $%d\n", precio);
	  printf ("Quiere agregar algo mas? Si (1) - No (2)\n");
	  scanf ("%d", &mas);
	}
  Pagar ();
  return 0;
}

int
Hamburguesas ()
{
  int hamburguesa;
  printf
	("Ingrese\n1 - Big Mac $7000\n2 - Cajita Feliz $5500\n3 - Triple Tasty $8000\n4 - Doble Cuarto de Libra $7500\n5 - Volver\n");
  scanf ("%d", &hamburguesa);
  switch (hamburguesa)
	{
	case 1:
	  Combo ();
	  precio = precio + 7000;
	  break;
	case 2:
	  precio = precio + 5500;
	  break;
	case 3:
	  Combo ();
	  precio = precio + 8000;
	  break;
	case 4:
	  Combo ();
	  precio = precio + 7500;
	  break;
	case 5:
	  return precio;
	  break;
	}
  return precio;
}

int
Desayuno ()
{
  int desayuno;
  printf
	("Ingrese\n1 - Tostado de jamon y queso $1000\n2 - Medialuna $350\n3 - Brownie $1400\n4 - Dona $700\n5 - Cafe $1000\n6 - Capuccino $1200\n7 - Volver\n");
  scanf ("%d", &desayuno);
  switch (desayuno)
	{
	case 1:
	  precio = precio + 1000;
	  break;
	case 2:
	  precio = precio + 350;
	  break;
	case 3:
	  precio = precio + 1400;
	  break;
	case 4:
	  precio = precio + 700;
	  break;
	case 5:
	  precio = precio + 1000;
	  break;
	case 6:
	  precio = precio + 1200;
	  break;
	case 7:
	  return precio;
	  break;
	}
  return precio;
}

int
Helados ()
{
  int helados;
  printf
	("Ingrese\n1 - Cono Helado $500\n2 - McFlury $1800\n3 - Sundae $1200\n4 - Cono relleno $1000\n5 - Volver\n");
  scanf ("%d", &helados);
  switch (helados)
	{
	case 1:
	  precio = precio + 500;
	  break;
	case 2:
	  precio = precio + 1800;
	  break;
	case 3:
	  precio = precio + 1200;
	  break;
	case 4:
	  precio = precio + 1000;
	  break;
	case 5:
	  return precio;
	  break;
	}
}

int
Bebidas ()
{
  int bebida;
  printf
	("Ingres\n1 - Gaseosa grande $1500\n2 - Gaseosa mediana $1200\n3 - Gaseosa pequeC1a $900\n4 - Agua $1000\n5 - Volver\n");
  scanf ("%d", &bebida);
  switch (bebida)
	{
	case 1:
	  precio = precio + 1500;
	  break;
	case 2:
	  precio = precio + 1200;
	  break;
	case 3:
	  precio = precio + 900;
	  break;
	case 4:
	  precio = precio + 1000;
	  break;
	case 5:
	  return precio;
	  break;
	}
}

Pagar ()
{
  int pago;
  printf ("Desea pagar en efectivo (1) o transferencia (2)\n");
  scanf ("%d", &pago);
  if (pago == 1)
	{
	  printf
		("B!Gracias por su compra!\nPague en la caja $%d y espere su pedido",
		 precio);
	}
  else if (pago == 2)
	{
	  printf
		("B!Gracias por su compra!\nTransfiera al CBU: 0140091503710256489397 $%d\nUna vez llegue el pago su pedido se comenzara automaticamente",
		 precio);
	}
}

int
Combo ()
{
  int combo;
  printf
	("Eliga un combo de papas y gaseosa\n1 - Grande +$800\n2 - Mediano +$400\n3 - PequeC1o +$0\n");
  scanf ("%d", &combo);
  switch (combo)
	{
	case 1:
	  precio = precio + 800;
	  break;
	case 2:
	  precio = precio + 400;
	  break;
	case 3:
	  return precio;
	  break;
	  return precio;
	}
}
