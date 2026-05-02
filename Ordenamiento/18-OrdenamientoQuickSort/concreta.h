#ifndef CONCRETA_H_INCLUDED
#define CONCRETA_H_INCLUDED

#include "abstracta.h"
#include <iostream>

using namespace std;

class Lista : public dadlista
{
public:
    void agregar(int n)
    {
        if(i<20)
        {
            arreglo[i] = n;
            i++;
            cout<<"Numero guardado "<<endl;
        } else {
            cout<<"Lista llena"<<endl;
        }
    }

    void mostrar()

    {
        for (int j=0;j<i;j++)
        {
            cout<<arreglo[j]<<" ";
        }
    }

    void ordenar()
    {
        if(i > 1)
        {
            quicksort(0,i-1);
            cout<<"lista Ordenada"<<endl;
        }
    }

private:
    void quicksort(int bajo,int alto)
    {
        if (bajo < alto)
        {
            int pivote = arreglo[alto];
            int k = (bajo -1);

            for(int j = bajo;j < alto ;j++)
            {
                if (arreglo[j] < pivote)
                {
                    k++;
                    int temp = arreglo[k];
                    arreglo[k] = arreglo[j];
                    arreglo[j] = temp;
                }
            }

            int temp = arreglo[k + 1];
            arreglo[k + 1] = arreglo[alto];
            arreglo[alto] = temp;

            int pi = k + 1;

            quicksort(bajo,pi - 1);
            quicksort( pi + 1 ,alto);
        }
    }
};


#endif // CONCRETA_H_INCLUDED
