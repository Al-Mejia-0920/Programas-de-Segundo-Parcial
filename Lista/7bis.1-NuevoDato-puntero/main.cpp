#include <iostream>
#include "concreta.h"

using namespace std;

int main()
{
    Lista L;
    int op,edad;
    float peso;
    string nombre;

   do
    {
        cout<<"\n----MENU---\n";
        cout<<"\n1.Agregar persona\n";
        cout<<"\n2.Quitar persona\n";
        cout<<"\n3.Mostrar lista\n";
        cout<<"\n4.Ver tamano de la lista\n";
        cout<<"\n5.Salir\n";
        cout<<"Opcion : ";
        cin >>op;

        switch(op)
        {
        case 1:
            cout <<"Nombre : ";cin>>nombre;
            cout <<"Edad : ";cin>>edad;
            cout <<"Peso : ";cin>>peso;
            L.agregar(nombre,edad,peso);
            break;

        case 2:
            L.quitar();
            break;

        case 3:
            L.mostrar();
            break;

        case 4:
            L.tam();
            break;

        case 5:
            cout <<"Saliendo del programa...";
            break;

        default:
            cout <<"Opcion no valida";
        }

    } while(op != 5);
    return 0;
}
