//Ejercicio6
#ifndef VIDEOJUEGOBASE_H
#define VIDEOJUEGOBASE_H

#include <iostream>
#include <string>

using namespace std;

class VideojuegoBase {
public:
    virtual void agregarJuego(string nom, int cant) = 0;
    virtual void mostrarInventario() = 0;
    virtual bool estaLleno() = 0;
    virtual void eliminar() = 0;

    virtual ~VideojuegoBase() {}
};

#endif