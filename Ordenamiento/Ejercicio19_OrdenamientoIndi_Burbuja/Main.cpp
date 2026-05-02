#include "BurbujaIndCon.h"

int main() {
    int n;
    cout << "  SISTEMA DE ORDENAMIENTO INDIRECTO (PUNTEROS)      " << endl;
    cout << "Cuantos elementos deseas ingresar? (max 10): ";
    
    while (!(cin >> n) || n <= 0) {
        cout << "Por favor, ingresa un numero valido mayor a 0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    BurbujaIndBase* miSistema = new BurbujaIndCon(n);

    miSistema->cargarDatos();
    miSistema->mostrarOriginal(); 
    miSistema->ordenarIndirecto();
    miSistema->mostrarOrdenado();

    delete miSistema; 
    return 0;
}