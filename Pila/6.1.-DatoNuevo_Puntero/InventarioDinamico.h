//Ejercicio6.1
#include "VideojuegoBase.h"

class InventarioDinamico : public VideojuegoBase {
private:
    string* nom;   
    int* cant;   
    int tod;          
    int maximo;       

public:
    InventarioDinamico(int total) {
        maximo = total;
        tod = 0;
        nom = new string[maximo];
        cant = new int[maximo];
    }

    ~InventarioDinamico() {
        delete[] nom;   
        delete[] cant;
        cout << "\n Memoria de arreglos liberada." << endl;
    }

    void agregarJuego(string nombre, int cantidad) override {
        if (!estaLleno()) {
            nom[tod] = nombre;
            cant[tod] = cantidad;
            tod++;
            cout << " Juego agregado:)" << endl;
        } else {
            cout << " Inventario lleno." << endl;
        }
    }

    void eliminar() override {
    if (tod > 0) {
        tod--; 
        cout << "El último videojuego ha sido eliminado." << endl;
    } else {
        cout << "No hay videojuegos para eliminar." << endl;
    }
}

    void mostrarInventario() override {
        if (tod == 0) cout << "El inventario está vacío." << endl;
        for (int i = 0; i < tod; i++) {
            cout << i + 1 << ". " << nom[i] << " (Stock: " << cant[i] << ")" << endl;
        }
    }

    bool estaLleno() override { return tod >= maximo; }
};