#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

Entidad::Entidad() { id = -1; }
Entidad::Entidad(int _id) { id = _id; }
int Entidad::getId() const { return id; }
void Entidad::mostrar() const { cout << "  [" << id << "]\n"; }

Ciudad::Ciudad() : Entidad() { nombre = ""; estado = ""; }
Ciudad::Ciudad(int _id, string _n, string _e) : Entidad(_id) { nombre = _n; estado = _e; }
string Ciudad::getNombre() const { return nombre; }
string Ciudad::getEstado() const { return estado; }
bool Ciudad::estaVacia() const { return id == -1; }
void Ciudad::mostrar() const { cout << "  Nodo [" << nombre << "]\n"; }

Conexion::Conexion() { idOrigen = -1; idDestino = -1; activa = false; nombreArista = ""; peso = 0; }
Conexion::Conexion(int o, int d, string nomArista, int p) {
    idOrigen = o; idDestino = d; nombreArista = nomArista; peso = p; activa = true;
}
int Conexion::getOrigen() const { return idOrigen; }
int Conexion::getDestino() const { return idDestino; }
string Conexion::getNombreArista() const { return nombreArista; }
int Conexion::getPeso() const { return peso; }
void Conexion::mostrarConexion(string o, string d) const {
    cout << "  " << o << " -> " << d << " via '" << nombreArista << "' (p: " << peso << ")\n";
}

AristaGrafo::AristaGrafo(int o, int d, string nomArista, int p) : Conexion(o, d, nomArista, p) {}
void AristaGrafo::mostrarConexion(string o, string d) const {
    cout << "  [" << o << "] --(" << nombreArista << ", peso:" << peso << ")--> [" << d << "]\n";
}

EstructuraGrafo::EstructuraGrafo(string _tipo) {
    totalC = 0; totalA = 0; tipo = _tipo;
    for (int i = 0; i < MAX_A; i++) aristas[i] = NULL;
}

EstructuraGrafo::~EstructuraGrafo() {
    for (int i = 0; i < totalA; i++) {
        delete aristas[i];
        aristas[i] = NULL;
    }
}

int EstructuraGrafo::getTotalC() const { return totalC; }
int EstructuraGrafo::getTotalA() const { return totalA; }
Ciudad EstructuraGrafo::getCiudad(int i) const { return ciudades[i]; }
Conexion* EstructuraGrafo::getArista(int i) const { return aristas[i]; }

int EstructuraGrafo::indicePorId(int id) const {
    for (int i = 0; i < totalC; i++) {
        if (ciudades[i].getId() == id) return i;
    }
    return -1;
}

int EstructuraGrafo::indicePorNombre(string nom) const {
    for (int i = 0; i < totalC; i++) {
        if (ciudades[i].getNombre() == nom) return i;
    }
    return -1;
}

void EstructuraGrafo::agregarCiudad(int id, string n, string e) {
    if (totalC >= MAX_N) return;
    ciudades[totalC] = Ciudad(id, n, e);
    totalC++;
}

int EstructuraGrafo::buscarCiudad(string nombre) const {
    return indicePorNombre(nombre);
}

void EstructuraGrafo::mostrarCiudades() const {
    cout << "\nNodos registrados:\n";
    for (int i = 0; i < totalC; i++) ciudades[i].mostrar();
}

char EstructuraGrafo::extraerAtributoChar(string linea, string atributo) {
    string token = atributo + "=\"";
    size_t pos = linea.find(token);
    if (pos != string::npos) return linea[pos + token.length()];
    return ' ';
}

string EstructuraGrafo::extraerAtributoString(string linea, string atributo) {
    string token = atributo + "=\"";
    size_t pos = linea.find(token);
    if (pos != string::npos) {
        size_t inicio = pos + token.length();
        size_t fin = linea.find("\"", inicio);
        return linea.substr(inicio, fin - inicio);
    }
    return "";
}

void EstructuraGrafo::cargarCatalogoXML(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "[!] Error: No se pudo abrir el archivo XML." << endl;
        return;
    }

    string linea;
    int idContador = 1;

    while (getline(archivo, linea)) {
        if (linea.find("<nodo") != string::npos) {
            char idNodo = extraerAtributoChar(linea, "id");
            string nombreNodo(1, idNodo);
            if (idNodo != ' ' && buscarCiudad(nombreNodo) == -1) {
                agregarCiudad(idContador++, nombreNodo, "XML_Nodo");
            }
        }
        else if (linea.find("<arista") != string::npos) {
            char origChar = extraerAtributoChar(linea, "origen");
            char destChar = extraerAtributoChar(linea, "destino");
            string idArista = extraerAtributoString(linea, "id");
            string pesoStr = extraerAtributoString(linea, "peso");

            if (origChar != ' ' && destChar != ' ' && !idArista.empty() && !pesoStr.empty()) {
                string oStr(1, origChar);
                string dStr(1, destChar);
                int idxO = buscarCiudad(oStr);
                int idxD = buscarCiudad(dStr);

                if (idxO != -1 && idxD != -1) {
                    int realIdO = ciudades[idxO].getId();
                    int realIdD = ciudades[idxD].getId();
                    int p = stoi(pesoStr);
                    agregarArista(realIdO, realIdD, idArista, p);
                }
            }
        }
    }
    archivo.close();
    cout << "[OK] Red completa cargada desde el XML con exito." << endl;
}

void EstructuraGrafo::dijkstra(string inicio, string fin) const {
    int idxInicio = indicePorNombre(inicio);
    int idxFin = indicePorNombre(fin);

    if (idxInicio == -1 || idxFin == -1) {
        cout << "[!] Error: El nodo origen o destino no existen." << endl;
        return;
    }

    int dist[MAX_N];
    int previo[MAX_N];
    bool visitado[MAX_N];
    string aristaPrevio[MAX_N];

    for (int i = 0; i < totalC; i++) {
        dist[i] = 999999;
        previo[i] = -1;
        visitado[i] = false;
    }

    dist[idxInicio] = 0;

    for (int count = 0; count < totalC; count++) {
        int min = 999999, u = -1;
        for (int i = 0; i < totalC; i++) {
            if (!visitado[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1 || u == idxFin) break;

        visitado[u] = true;
        int idU = ciudades[u].getId();

        for (int i = 0; i < totalA; i++) {
            if (aristas[i]->getOrigen() == idU) {
                int idV = aristas[i]->getDestino();
                int v = indicePorId(idV);

                if (v != -1 && !visitado[v]) {
                    if (dist[u] != 999999 && dist[u] + aristas[i]->getPeso() < dist[v]) {
                        dist[v] = dist[u] + aristas[i]->getPeso();
                        previo[v] = u;
                        aristaPrevio[v] = aristas[i]->getNombreArista();
                    }
                }
            }
        }
    }

    if (dist[idxFin] == 999999) {
        cout << "\nNo existe ninguna ruta transitable desde " << inicio << " hasta " << fin << "." << endl;
        return;
    }

    cout << "\nRuta mas corta desde " << inicio << " hasta " << fin << " | Peso Total: " << dist[idxFin] << endl;
    vector<string> camino;
    int actual = idxFin;
    while (actual != idxInicio) {
        int p = previo[actual];
        string ar = aristaPrevio[actual];
        camino.insert(camino.begin(), ciudades[p].getNombre() + " --(" + ar + ")--> " + ciudades[actual].getNombre());
        actual = p;
    }
    for (size_t i = 0; i < camino.size(); i++) cout << "  " << camino[i] << endl;
}

Grafo::Grafo() : EstructuraGrafo("dirigido") {}

void Grafo::agregarArista(int o, int d, string nomArista, int p) {
    if (totalA >= MAX_A) return;
    aristas[totalA] = new AristaGrafo(o, d, nomArista, p);
    totalA++;
}

void Grafo::mostrarEstructura() const {
    cout << "\nConexiones del digrafo cargadas:\n";
    if (totalA == 0) {
        cout << "No hay conexiones registradas.\n";
        return;
    }
    for (int i = 0; i < totalA; i++) {
        string origen = ciudades[indicePorId(aristas[i]->getOrigen())].getNombre();
        string destino = ciudades[indicePorId(aristas[i]->getDestino())].getNombre();
        aristas[i]->mostrarConexion(origen, destino);
    }
}
