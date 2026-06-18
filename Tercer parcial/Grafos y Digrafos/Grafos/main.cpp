#include <iostream>
#include <string>
#include <cctype>
#include "Grafo.h"

using namespace std;

Grafo miDigrafo;

int main() {
    miDigrafo.cargarCatalogoXML("red.xml");

    cout << "\n=== CONFIGURACION DE LA RED ===" << endl;
    miDigrafo.mostrarCiudades();
    miDigrafo.mostrarEstructura();

    cout << "\n=== DETECTAR RUTA OPTIMA ===" << endl;
    string nInicio, nFin;
    cout << "Punto de Partida (Nodo inicial): ";
    cin >> nInicio;
    nInicio[0] = toupper(nInicio[0]);

    cout << "Punto de Destino (Nodo final): ";
    cin >> nFin;
    nFin[0] = toupper(nFin[0]);

    miDigrafo.dijkstra(nInicio, nFin);

    return 0;
}
