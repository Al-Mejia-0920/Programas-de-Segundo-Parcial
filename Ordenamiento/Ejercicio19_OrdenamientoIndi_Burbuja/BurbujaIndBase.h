#ifndef BURBUJAINDBASE_H
#define BURBUJAINDBASE_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona() {}
    Persona(string n, int e) : nombre(n), edad(e) {}
    void imprimir() {
        cout << "[" << nombre << ", " << edad << "] ";
    }
};

class BurbujaIndBase {
public:
    virtual void cargarDatos() = 0;
    virtual void ordenarIndirecto() = 0;
    virtual void mostrarOriginal() = 0;
    virtual void mostrarOrdenado() = 0;
    virtual ~BurbujaIndBase() {} 
};

#endif