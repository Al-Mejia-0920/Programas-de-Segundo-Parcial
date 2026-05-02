#ifndef ABSTRACTA_H_INCLUDED
#define ABSTRACTA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
    string nombre;
    int edad;
    float peso;
    Nodo* siguiente;
};

class dadlista
{
public:
    Nodo* inicio;
    int i;
    dadlista()
    {
        inicio = NULL;
    }

    void agregar(string n,int e,float p){}
    void quitar(){}
    void mostrar(){}
    void tam(){}
};

#endif // ABSTRACTA_H_INCLUDED
