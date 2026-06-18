#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <string>
#include <vector>
using namespace std;

class Entidad {
public:
    Entidad();
    Entidad(int _id);
    int getId() const;
    virtual void mostrar() const;
    virtual ~Entidad() {}
    int id;
};

class Ciudad : public Entidad {
protected:
    string nombre;
    string estado;

public:
    Ciudad();
    Ciudad(int _id, string _nombre, string _estado);
    string getNombre() const;
    string getEstado() const;
    void mostrar() const;
    bool estaVacia() const;
};

class Conexion {
protected:
    int idOrigen, idDestino;
    bool activa;
    string nombreArista;
    int tiempo;
    int costo;

public:
    Conexion();
    Conexion(int o, int d, string nomArista, int t, int c);
    int getOrigen() const;
    int getDestino() const;
    string getNombreArista() const;
    int getTiempo() const;
    int getCosto() const;
    virtual void mostrarConexion(string o, string d) const;
    virtual ~Conexion() {}
};

class AristaDigrafo : public Conexion {
public:
    AristaDigrafo(int o, int d, string nomArista, int t, int c);
    void mostrarConexion(string o, string d) const;
};

class EstructuraDigrafo {
protected:
    static const int MAX_N = 50;
    static const int MAX_A = 100;

    Ciudad ciudades[MAX_N];
    Conexion* aristas[MAX_A];
    int totalC, totalA;
    string tipo;

public:
    EstructuraDigrafo(string _tipo);
    virtual ~EstructuraDigrafo();

    int getTotalC() const;
    int getTotalA() const;
    Ciudad getCiudad(int i) const;
    Conexion* getArista(int i) const;

    int indicePorId(int id) const;
    int indicePorNombre(string nom) const;

    void agregarCiudad(int id, string nombre, string estado);
    int buscarCiudad(string nombre) const;

    virtual void agregarArista(int o, int d, string nomArista, int t, int c) = 0;

    void mostrarCiudades() const;
    virtual void mostrarEstructura() const = 0;

    char extraerAtributoChar(string linea, string atributo);
    string extraerAtributoString(string linea, string atributo);
    void cargarCatalogoXML(string nombreArchivo);
    void dijkstra(string inicio, string fin, int criterio) const;
};

class Digrafo : public EstructuraDigrafo {
public:
    Digrafo();
    void agregarArista(int o, int d, string nomArista, int t, int c);
    void mostrarEstructura() const;
};

#endif
