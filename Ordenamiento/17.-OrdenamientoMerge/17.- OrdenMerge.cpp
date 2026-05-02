#include "abstracta.h"
#include <iostream>
#include <cstdio>

int main() {
    int opc = 0;
    Competidor competidores[10];

    for (int i = 0; i < 10; i++) {
        int tempID;
        string tempNom;
        float tempH;

        cout << "\nCompetidor " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> tempID;
        cin.ignore();

        cout << "Nombre: ";
        getline(cin, tempNom);

        cout << "Altura: ";
        cin >> tempH;

        competidores[i] = Competidor(tempID, tempNom, tempH);
    }

    cout << "\n--- LISTA ORIGINAL ---" << endl;
    for (int i = 0; i < 10; i++) {
        cout << competidores[i].id << ", " << competidores[i].nom << ", " << competidores[i].h << endl;
    }

    printf("\nIngresa el valor por el cual quieres acomodar: \n 1.- ID \n 2.-Nombre \n 3.-Altura\n");
    scanf("%d", &opc);

    mergeS(competidores, 0, 9, opc);

    cout << "\n--- LISTA ORDENADA ---" << endl;
    for (int i = 0; i < 10; i++) {
        cout << competidores[i].id << ", " << competidores[i].nom << ", " << competidores[i].h << endl;
    }

    return 0;
}
