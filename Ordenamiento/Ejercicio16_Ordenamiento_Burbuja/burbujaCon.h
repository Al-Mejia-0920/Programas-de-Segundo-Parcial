#ifndef BURBUJACON_H
#define BURBUJACON_H

#include "burbujabase.h"

class BurbujaCon : public BurbujaBase {
private:
    int nums[10];
    char letras[10];
    Persona gente[10];
    int cantidad;

    void ordenarEnteros() {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - i - 1; j++) {
                if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
            }
        }
    }

    void ordenarChars() {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - i - 1; j++) {
                if (letras[j] > letras[j + 1]) swap(letras[j], letras[j + 1]);
            }
        }
    }

    void ordenarPersonas() {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - i - 1; j++) {
                if (gente[j].edad > gente[j + 1].edad) swap(gente[j], gente[j + 1]);
            }
        }
    }

public:
    BurbujaCon(int n) {
        cantidad = (n > 10) ? 10 : n;
    }

    void cargarDatos() override {
        cout << "--- Ingreso de Datos ---" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "1-.Numero [" << i + 1 << "]: "; cin >> nums[i];
            cout << "2-.Letra [" << i + 1 << "]: "; cin >> letras[i];
            string nom; int ed;
            cout << "3-.Nombre Persona " << i + 1 << ": "; cin >> nom;
            cout << "4-.Edad Persona " << i + 1 << ": "; cin >> ed;
            gente[i] = Persona(nom, ed);
        }
    }

    void ordenarTodo() override {
        ordenarEnteros();
        ordenarChars();
        ordenarPersonas();
    }

    void mostrarTodo() override {
        cout << "\nRESULTADOS ORDENADOS:" << endl;
        for (int i = 0; i < cantidad; i++) cout << nums[i] << " ";
        cout << "\n";
        for (int i = 0; i < cantidad; i++) cout << letras[i] << " ";
        cout << "\n";
        for (int i = 0; i < cantidad; i++) gente[i].imprimir();
        cout << endl;
    }
};

#endif