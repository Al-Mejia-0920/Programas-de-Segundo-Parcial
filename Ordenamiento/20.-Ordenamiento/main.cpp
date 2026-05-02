#include "abstracta.h"
#include <cstdio>

int main() {
    int n;
    int opc = 0;

    cout << "Ingrese la cantidad de competidores a registrar: ";
    cin >> n;

    Competidor* competidores = new Competidor[n];
    int* indices = new int[n];

    for (int i = 0; i < n; i++) {
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
        indices[i] = i;
    }

    cout << "\n--- LISTA ORIGINAL ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << competidores[i].id << ", " << competidores[i].nom << ", " << competidores[i].h << endl;
    }

    printf("\nIngresa el valor por el cual quieres acomodar: \n 1.- ID \n 2.-Nombre \n 3.-Altura\n");
    scanf("%d", &opc);

    mergeS(indices, competidores, 0, n - 1, opc);

    cout << "\n--- LISTA ORDENADA ---" << endl;
    for (int i = 0; i < n; i++) {
        int pos = indices[i];
        cout << competidores[pos].id << ", " << competidores[pos].nom << ", " << competidores[pos].h << endl;
    }

    delete[] competidores;
    delete[] indices;

    return 0;
}
