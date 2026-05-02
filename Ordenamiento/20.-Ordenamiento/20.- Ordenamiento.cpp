#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Competidor {
public:
    int id;
    string nom;
    float h;

    Competidor(){}

    Competidor (int _id, string _nom, float _h){
        id = _id;
        nom = _nom;
        h = _h;
    }
};

void mergeID (int indices[], Competidor arr[], int izq, int m, int der){
    int n1 = m - izq + 1;
    int n2 = der - m;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++) { L[i] = indices[izq + i]; }
    for(int j=0; j<n2; j++) { R[j] = indices[m + 1 + j]; }

    int i=0, j=0, k=izq;
    while (i<n1 && j<n2) {
        if (arr[L[i]].id <= arr[R[j]].id){
            indices[k] = L[i];
            i++;
        } else {
            indices[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1){ indices[k] = L[i]; i++; k++; }
    while (j<n2){ indices[k] = R[j]; j++; k++; }
}

void mergeN (int indices[], Competidor arr[], int izq, int m, int der){
    int n1 = m - izq + 1;
    int n2 = der - m;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++) { L[i] = indices[izq + i]; }
    for(int j=0; j<n2; j++) { R[j] = indices[m + 1 + j]; }

    int i=0, j=0, k=izq;
    while (i<n1 && j<n2) {
        if (arr[L[i]].nom <= arr[R[j]].nom){
            indices[k] = L[i];
            i++;
        } else {
            indices[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1){ indices[k] = L[i]; i++; k++; }
    while (j<n2){ indices[k] = R[j]; j++; k++; }
}

void mergeH (int indices[], Competidor arr[], int izq, int m, int der){
    int n1 = m - izq + 1;
    int n2 = der - m;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++) { L[i] = indices[izq + i]; }
    for(int j=0; j<n2; j++) { R[j] = indices[m + 1 + j]; }

    int i=0, j=0, k=izq;
    while (i<n1 && j<n2) {
        if (arr[L[i]].h <= arr[R[j]].h){
            indices[k] = L[i];
            i++;
        } else {
            indices[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1){ indices[k] = L[i]; i++; k++; }
    while (j<n2){ indices[k] = R[j]; j++; k++; }
}

void mergeS (int indices[], Competidor arr[], int izq, int der, int opc){
    if (izq < der){
        int m = izq + (der - izq) / 2;
        mergeS (indices, arr, izq, m, opc);
        mergeS (indices, arr, m + 1, der, opc);

        switch (opc){
            case 1: mergeID (indices, arr, izq, m, der); break;
            case 2: mergeN (indices, arr, izq, m, der); break;
            case 3: mergeH (indices, arr, izq, m, der); break;
        }
    }
}

int main(){
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

    cout << "\n--- Lista Original ---" << endl;
    for (int i = 0; i < n; i++){
        cout << competidores[i].id << ", " << competidores[i].nom << ", " << competidores[i].h << endl;
    }

    printf ("\nIngresa el valor por el cual quieres acomodar: \n 1.- ID \n 2.-Nombre \n 3.-Altura\n");
    scanf ("%d", &opc);

    mergeS (indices, competidores, 0, n - 1, opc);

    cout << "\n--- Lista Ordenada ---" << endl;
    for (int i = 0; i < n; i++){
            int pos = indices[i];
            cout << competidores[pos].id << ", " << competidores[pos].nom << ", " << competidores[pos].h << endl;
    }

    delete[] competidores;
    delete[] indices;

    return 0;
}
