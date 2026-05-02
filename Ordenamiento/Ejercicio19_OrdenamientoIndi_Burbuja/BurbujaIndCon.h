#ifndef BURBUJAINDCON_H
#define BURBUJAINDCON_H

#include "BurbujaIndBase.h"

class BurbujaIndCon : public BurbujaIndBase {
private:
    int nums[10];
    char letras[10];
    Persona gente[10];
    
    int* pNums[10];
    char* pLetras[10];
    Persona* pGente[10];
    
    int cantidad;

    void ordenarEnterosInd() {
        for(int i = 0; i < cantidad - 1; i++) {
            for(int j = 0; j < cantidad - i - 1; j++) {
                if(*pNums[j] > *pNums[j+1]) {
                    swap(pNums[j], pNums[j+1]);
                }
            }
        }
    }

    void ordenarCharsInd() {
        for(int i = 0; i < cantidad - 1; i++) {
            for(int j = 0; j < cantidad - i - 1; j++) {
                if(*pLetras[j] > *pLetras[j+1]) {
                    swap(pLetras[j], pLetras[j+1]);
                }
            }
        }
    }

    void ordenarPersonasInd() {
        for(int i = 0; i < cantidad - 1; i++) {
            for(int j = 0; j < cantidad - i - 1; j++) {
                if(pGente[j]->edad > pGente[j+1]->edad) {
                    swap(pGente[j], pGente[j+1]);
                }
            }
        }
    }

public:
    BurbujaIndCon(int n) {
        cantidad = (n > 10) ? 10 : n;
        for(int i = 0; i < cantidad; i++) {
            pNums[i] = &nums[i];
            pLetras[i] = &letras[i];
            pGente[i] = &gente[i];
        }
    }

    void cargarDatos() override {
        cout << "\n--- Ingreso de Datos ---" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "Numero [" << i + 1 << "]: "; cin >> nums[i];
            cout << "Letra [" << i + 1 << "]: "; cin >> letras[i];
            string nom; int ed;
            cout << "Nombre Persona " << i + 1 << ": "; cin >> nom;
            cout << "Edad Persona " << i + 1 << ": "; cin >> ed;
            gente[i] = Persona(nom, ed);
        }
    }

    void ordenarIndirecto() override {
        ordenarEnterosInd();
        ordenarCharsInd();
        ordenarPersonasInd();
    }

    void mostrarOriginal() override {
        cout << "\n--- DATOS ORIGINALES (Memoria Intacta) ---" << endl;
        for(int i = 0; i < cantidad; i++) cout << nums[i] << " "; cout << "\n";
        for(int i = 0; i < cantidad; i++) cout << letras[i] << " "; cout << "\n";
        for(int i = 0; i < cantidad; i++) gente[i].imprimir(); cout << "\n";
    }

    void mostrarOrdenado() override {
        cout << "\n--- RESULTADOS ORDENADOS (Manejo Indirecto) ---" << endl;
        for(int i = 0; i < cantidad; i++) cout << *pNums[i] << " "; cout << "\n";
        for(int i = 0; i < cantidad; i++) cout << *pLetras[i] << " "; cout << "\n";
        for(int i = 0; i < cantidad; i++) pGente[i]->imprimir(); cout << "\n";
    }
};

#endif