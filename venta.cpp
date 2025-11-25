#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    float precio;
    int stock;

public:
    Producto(string n = "", float p = 0, int s = 0) : nombre(n), precio(p), stock(s) {}

    void ingresardatos() {
        cout << "Nombre del producto: ";
        cin >> nombre;

        cout << "Precio: ";
        cin >> precio;

        cout << "Stock: ";
        cin >> stock;
    }

    void mostrar() const {
        cout << "Producto: " << nombre << " | Precio: $" << precio << " | Stock: " << stock << endl;
    }
};


void agregarProducto(vector<Producto> &inventario) {
    Producto p;
    p.ingresardatos();
    inventario.push_back(p);
}

void mostrarInventario(const vector<Producto> &inventario) {
    if (inventario.empty()) {
        cout << "\nNo hay productos cargados.\n";
        return;
    }

    cout << "\n--- INVENTARIO ---\n";
    for (const auto &p : inventario)
        p.mostrar();
}


int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "0. Salir\n";
        cout << "Elija: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(inventario);
                break;
            case 2:
                mostrarInventario(inventario);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}