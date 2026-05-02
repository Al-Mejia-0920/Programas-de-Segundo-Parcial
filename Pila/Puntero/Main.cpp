#include "SistemaCon.h"

int main() {
    int cant;
    cout << "   SISTEMA DE GESTION DINAMICA (PUNTEROS)   " << endl;    
    cout << "¿Cuantos registros desea ingresar? ";
    cin >> cant;

    SistemaBase* miSistema = new SistemaCon();

    for (int i = 0; i < cant; i++) {
        string nom, mod;
        int ed, an;
        float pre;
        char gen;

        cout << "\n--- Registro " << i + 1 << " ---" << endl;
        cout << "Nombre Persona: "; cin >> nom;
        cout << "Edad: "; cin >> ed;
        cout << "Genero (M/F): "; cin >> gen;
        miSistema->agregarPersona(nom, gen, ed);

        cout << "Modelo Coche: "; cin >> mod;
        cout << "Precio: "; cin >> pre;
        cout << "Anio: "; cin >> an;
        miSistema->agregarCoche(mod, pre, an);
    }

    miSistema->mostrarDatos();

    delete miSistema; 
    return 0;
}