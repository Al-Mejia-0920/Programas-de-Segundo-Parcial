#include <iostream>
#include <string>
#include <cctype>
#include "Digrafo.h"

using namespace std;

Digrafo miDigrafo;

int main() {
    miDigrafo.cargarCatalogoXML("red.xml");

    cout << "\n=== CONFIGURACION DE LA RED ===" << endl;
    miDigrafo.mostrarCiudades();
    miDigrafo.mostrarEstructura();

    cout << "\n=== DETECTAR RUTA OPTIMA ===" << endl;
    string nInicio, nFin;
    int criterio;

    cout << "Punto de Partida (Nodo inicial): ";
    cin >> nInicio;
    nInicio[0] = toupper(nInicio[0]);

    cout << "Punto de Destino (Nodo final): ";
    cin >> nFin;
    nFin[0] = toupper(nFin[0]);

    cout << "Seleccione criterio de optimizacion (1. Tiempo / 2. Costo): ";
    cin >> criterio;

    if (criterio != 1 && criterio != 2) {
        criterio = 1;
    }

    miDigrafo.dijkstra(nInicio, nFin, criterio);

    return 0;
}
