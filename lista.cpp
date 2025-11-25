#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string n = "", int e = 0) {
        nombre = n;
        edad = e;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre << " - Edad: " << edad << endl;
    }

    void guardarEnArchivo(ofstream &archivo) const {
        archivo << nombre << "," << edad << endl;
    }
};

void agregarPersona(vector<Persona> &lista) {
    string nombre;
    int edad;

    cout << "\nIngrese nombre: ";
    cin >> nombre;

    cout << "Ingrese edad: ";
    cin >> edad;

    lista.push_back(Persona(nombre, edad));

    cout << "Persona agregada con exito!\n";
}

void mostrarPersonas(const vector<Persona> &lista) {
    if (lista.empty()) {
        cout << "No hay personas cargadas.\n";
        return;
    }

    cout << "\n--- Lista de Personas ---\n";
    for (const auto &p : lista) {
        p.mostrar();
    }
}

void guardarArchivo(const vector<Persona> &lista) {
    ofstream archivo("personas.txt");

    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    for (const auto &p : lista) {
        p.guardarEnArchivo(archivo);
    }

    archivo.close();
    cout << "Datos guardados en personas.txt\n";
}

void cargarArchivo(vector<Persona> &lista) {
    ifstream archivo("personas.txt");

    if (!archivo) {
        cout << "No existe el archivo personas.txt.\n";
        return;
    }

    lista.clear();

    string linea;
    while (getline(archivo, linea)) {
        size_t coma = linea.find(',');

        if (coma == string::npos) continue;

        string nombre = linea.substr(0, coma);
        int edad = stoi(linea.substr(coma + 1));

        lista.push_back(Persona(nombre, edad));
    }

    archivo.close();
    cout << "Archivo cargado correctamente!\n";
}

int main() {
    vector<Persona> lista;
    int opcion;
    cargarArchivo(lista);
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar persona\n";
        cout << "2. Ver lista\n";
        cout << "0. Salir\n";
        cout << "Elegir opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarPersona(lista);
            break;
        case 2:
            mostrarPersonas(lista);
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);
    
    guardarArchivo(lista);
    return 0;
}