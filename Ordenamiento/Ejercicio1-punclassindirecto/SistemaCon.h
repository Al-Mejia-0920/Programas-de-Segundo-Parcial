#ifndef SISTEMACON_H
#define SISTEMACON_H

#include "SistemaBase.h"

class SistemaCon : public SistemaBase {
private:
    Persona* cabezaP; 
    Coche* cabezaC;

public:
    SistemaCon() : cabezaP(nullptr), cabezaC(nullptr) {}

    void agregarPersona(string n, char g, int e) override {
        Persona* nueva = new Persona(n, g, e);
        nueva->siguiente = cabezaP; 
        cabezaP = nueva;          
    }

    void agregarCoche(string m, float p, int a) override {
        Coche* nuevo = new Coche(m, p, a);
        nuevo->siguiente = cabezaC;
        cabezaC = nuevo;
    }

    void mostrarDatos() override {
        cout << "\n--- LISTA DE PERSONAS ---" << endl;
        Persona* tempP = cabezaP;
        while (tempP != nullptr) {
            cout << "Nombre: " << tempP->nombre << " | Edad: " << tempP->edad << endl;
            tempP = tempP->siguiente;
        }

        cout << "\n--- LISTA DE COCHES ---" << endl;
        Coche* tempC = cabezaC;
        while (tempC != nullptr) {
            cout << "Modelo: " << tempC->modelo << " | Precio: $" << tempC->precio << endl;
            tempC = tempC->siguiente;
        }
    }

    ~SistemaCon() {
        while (cabezaP != nullptr) {
            Persona* t = cabezaP;
            cabezaP = cabezaP->siguiente;
            delete t;
        }
        while (cabezaC != nullptr) {
            Coche* t = cabezaC;
            cabezaC = cabezaC->siguiente;
            delete t;
        }
    }
};

#endif