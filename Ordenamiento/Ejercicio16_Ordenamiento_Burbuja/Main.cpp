#include "burbujaCon.h"

int main() {
    int n;
    cout<<"Agregaras varios como un numero,letra,nombre,edad, "<<endl;
    cout << "Cuantos elementos (no maximo de  10): ";
    cin >> n;

    BurbujaBase* miLista = new BurbujaCon(n);

    miLista->cargarDatos();
    miLista->ordenarTodo();
    miLista->mostrarTodo();

    delete miLista; 
    return 0;
}