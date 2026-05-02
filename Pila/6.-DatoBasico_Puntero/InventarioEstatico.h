//Ejercicio6
#include "VideojuegoBase.h"

class InventarioEstatico : public VideojuegoBase {
private:
    string nom[5];    
    int cant[5];    
    int tod;             
    int max;              

public:
    InventarioEstatico() {
        max = 5;
        tod = 0;
    }

    void agregarJuego(string nombre, int cantidad) override {
        if (!estaLleno()) {
            nom[tod] = nombre;
            cant[tod] = cantidad;
            tod++;
            cout << "El Juego '" << nombre << "'Fue agregado al inventario estático." << endl;
        } else {
            cout << " Error: El inventario está lleno." << endl;
        }
    }

    void mostrarInventario() override {
        if (tod == 0) {
            cout << "El inventario está vacío." << endl;
            return;
        }
        cout << "\n--- INVENTARIO ESTÁTICO DE VIDEOJUEGOS ---" << endl;
        for (int i = 0; i < tod; i++) {
            cout << i + 1 << ". " << nom[i] << " | Stock: " << cant[i] << endl;
        }
    }
    void eliminar() override{
        if(tod > 0){
            tod--;
            cout << "El último videojuego ha sido eliminado." << endl;
    } else {
        cout << "No hay videojuegos para eliminar." << endl;
        }
    }

    bool estaLleno() override {
        return tod >= max;
    }
};