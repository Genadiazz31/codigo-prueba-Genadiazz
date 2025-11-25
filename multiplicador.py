def imprimir_vector(vector):
    for v in vector:
        print(v, end=" ")
    print()


def multiplicar_un_valor(vector):
    x = int(input("\nIngrese por qué número quiere multiplicar: "))
    for i in range(len(vector)):
        vector[i] *= x


def sumar_un_valor(vector):
    x = int(input("\nIngrese qué número quiere sumar: "))
    for i in range(len(vector)):
        vector[i] += x


n = int(input("Ingrese la cantidad de elementos del vector: "))

vector = []

for i in range(n):
    valor = int(input(f"Ingrese el valor N°{i+1}: "))
    vector.append(valor)

print("\nIngrese qué quiere hacer con su vector")
opc = int(input(" 1 - Multiplicarlos por un valor\n 2 - Sumarles un valor\n"))


print("\nVector antes de modificar: ", end="")
imprimir_vector(vector)

if opc == 1:
    multiplicar_un_valor(vector)
elif opc == 2:
    sumar_un_valor(vector)

print("\nVector después de modificar: ", end="")
imprimir_vector(vector)