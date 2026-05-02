#ifndef BURBUJABASE_H
#define BURBUJABASE_H

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

class BurbujaBase {
public:
    virtual void cargarDatos() = 0;
    virtual void ordenarTodo() = 0;
    virtual void mostrarTodo() = 0;
    virtual ~BurbujaBase() {} // Destructor virtual
};

#endif