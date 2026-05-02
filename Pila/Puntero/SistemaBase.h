#ifndef SISTEMABASE_H
#define SISTEMABASE_H

#include <iostream>
#include <string>
using namespace std;

struct Coche {
    string modelo;
    float precio;
    int anio;
    Coche* siguiente; 
    Coche(string m, float p, int a) : modelo(m), precio(p), anio(a), siguiente(nullptr) {}
};

struct Persona {
    string nombre;
    char genero;
    int edad;
    Persona* siguiente;
    Persona(string n, char g, int e) : nombre(n), genero(g), edad(e), siguiente(nullptr) {}
};

class SistemaBase {
public:
    virtual void agregarPersona(string n, char g, int e) = 0;
    virtual void agregarCoche(string m, float p, int a) = 0;
    virtual void mostrarDatos() = 0;
    virtual ~SistemaBase() {} 
};

#endif