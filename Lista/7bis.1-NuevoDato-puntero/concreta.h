#ifndef CONCRETA_H_INCLUDED
#define CONCRETA_H_INCLUDED

#include "abstracta.h"

class Lista : public dadlista
{
public:

    Lista(){
        inicio = NULL;
        i = 0;
    }
    void agregar(string n,int e,float p)
    {
        Nodo* nuevo = new Nodo();
        nuevo->nombre = n;
        nuevo->edad = e;
        nuevo->peso = p;

        nuevo->siguiente = inicio;
        inicio = nuevo;
        i++;
        cout<<"---Agregado correctamente---";
    }

    void quitar()
    {
        if(inicio != NULL)
        {
            Nodo* aux = inicio;
            inicio = inicio->siguiente;
            delete aux;
            i--;
            cout<<"Se ha eliminado....";
        } else
        {
            cout<<"No hay nada que borrar....";
        }
    }

    void mostrar()
    {
        Nodo* aux = inicio;
        if(aux == NULL)
        {
            cout<<"Lista vacia...";
        }
        while (aux != NULL)
        {
            cout<<"\nNombre : "<<aux->nombre;
            cout<<"\nEdad : "<<aux->edad;
            cout<<"\nPeso : "<<aux->peso;
            aux = aux->siguiente;
        }
    }

    void tam()
    {
        cout <<"\nHay "<<i<<" Personas en la lista";
    }
};


#endif // CONCRETA_H_INCLUDED
