//Ejercicio6.1
#include "InventarioDinamico.h"

int main() {
    int total;
    cout << "¿Capacidad total del inventario? ";
    while (!(cin >> total) || total <= 0) {
        cout << "Por favor, ingresa un número válido mayor a 0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    VideojuegoBase* inventario = new InventarioDinamico(total);

    int opc;
    string nombre;
    int cant;

    do {
        cout << "\n--- MENÚ VIDEOJUEGOS (Pila Dinámica) ---" << endl;
        cout << "1. Agregar Videojuego (Push)" << endl;
        cout << "2. Eliminar último (Pop)" << endl;
        cout << "3. Mostrar Inventario" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opc;

        switch(opc) {
            case 1:
                cout << "Nombre: "; 
                cin.ignore(); 
                getline(cin, nombre);
                cout << "Cantidad: "; 
                cin >> cant;
                inventario->agregarJuego(nombre, cant);
                break;
            case 2:
                inventario->eliminar(); 
                break;
            case 3:
                inventario->mostrarInventario();
                break;
            case 4:
                cout << "Liberando memoria y saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opc != 4);

    delete inventario; 
    return 0;
}