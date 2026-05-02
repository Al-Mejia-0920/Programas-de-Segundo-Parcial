//Ejercicio6
#include "InventarioEstatico.h"

int main() {
    VideojuegoBase* inventario = new InventarioEstatico(); 
    int opc;

    do {
        cout << "\n--- MENÚ VIDEOJUEGOS (Punteros Estáticos) ---" << endl;
        cout << "1. Agregar Videojuego" << endl;
        cout << "2. Mostrar Inventario" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opc;

        switch (opc){

            case 1:{
            string nom;
            int cant;
            cout << "Nombre del juego: ";
            cin.ignore(); 
            getline(cin, nom);
            cout << "Cantidad en stock: ";
            cin >> cant;
            
            inventario->agregarJuego(nom, cant); 
            break;
            }

            case 2:{
            inventario->mostrarInventario();
            break;
            }

            case 3:{
            inventario->eliminar();
            break;
            }

            case 4:{
            cout<<("Saliendo del programa...")<<endl;
                break;
            }
                
            default:
            cout<<("Opción no válida. Intenta de nuevo.")<<endl;
        }
    } while (opc != 4);   
    return 0;
}