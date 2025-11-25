import os
import json

ARCHIVO = "personas.json"

def cargar_datos():
    global personas
    if os.path.exists(ARCHIVO):
        with open(ARCHIVO, "r") as f:
            personas = json.load(f)
        print(f"{len(personas)} registros cargados desde {ARCHIVO}.")
    else:
        personas = []

def guardar_datos():
    with open(ARCHIVO, "w") as f:
        json.dump(personas, f, indent=4)
    print("\nDatos guardados correctamente")
    

def limpiar():
    os.system('cls' if os.name == 'nt' else 'clear')

def ver_lista():
            print("--- Lista de personas ---")
            for p in personas:
                print(f"- Nombre: {p["nombre"]} Edad: {p["edad"]} Promedio: {p["promedio"]}")
            input("\nPresioná Enter para continuar...")
            limpiar()

    
def lista_aprobados():
    print("--- Lista aprobados ---")
    for p in personas:
        if p["promedio"] > 6:
            print(f" - {p["nombre"]} - {p["promedio"]}")
    input("\nPresioná Enter para continuar...")
    limpiar()
            
def lista_desaprobados():
    print("--- Lista desaprobados ---")
    for p in personas:
        if p["promedio"] < 7:
            print(f" - {p["nombre"]} - {p["promedio"]}")
    input("\nPresioná Enter para continuar...")
    limpiar()
    
def modificar_eliminar():
    nombre = input("Ingrese el nombre de quien desea modificar o eliminar: ")
    limpiar()
    opcz = int(input("Que desea hacer?\n 1 - Modificar persona\n 2 - Eliminar persona\n 0 - Volver\n"))
    limpiar()
    for p in personas:
        if nombre.lower() == p["nombre"].lower():
            match opcz:
                case 1:
                    p["nombre"] = input("Ingrese el nuevo nombre:")
                    p["edad"] = int(input("Ingrese la nueva edad: "))
                    p["promedio"] = float(input("Ingrese el nuevo promedio: "))
                    limpiar()
                    print("Persona modificada con exito\n")
                    input("\nPresioná Enter para continuar...")
                    limpiar()
                    
                case 2:
                    personas.remove(p)
                    print("Persona eliminada con exito\n")
                    input("\nPresioná Enter para continuar...")
                    limpiar()

x = 1
cargar_datos()
while x==1:

    opc = int(input("\nQue desea hacer?\n 1 - Agregar persona/s\n 2 - Ver lista\n 3 - Otra opciones\n 0 - Salir\n"))
    limpiar()
    match opc:
        case 1:
            cantidad = int(input("Cuantas personas desea ingresar: "))
            limpiar()
            for i in range(cantidad):
                print(f"Persona {i+1}")
                nombre = input("Ingrese el nombre: ")
                edad = int(input("Ingrese la edad: "))
                promedio = float(input("Ingrese el promedio: "))
                limpiar()
                nueva_persona = {
                    "nombre" : nombre.title(),
                    "edad" : edad,
                    "promedio" : promedio
                }
                personas.append(nueva_persona)
    
        case 2:
            ver_lista()
        
        case 3:
            opcx = int(input("Que desea hacer?\n 1 - Ver lista de aprobados\n 2 - Ver lista de desaprobados\n 3 - Modificar o eliminar persona\n 0 - Volver\n"))
            limpiar()
            match opcx:
                case 1:
                    lista_aprobados()
                case 2:
                    lista_desaprobados()
                case 3:
                    modificar_eliminar()
        case 0:
            x=0
guardar_datos()