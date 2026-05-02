#include "abstracta.h"

Competidor::Competidor() {}

Competidor::Competidor(int _id, string _nom, float _h) {
    id = _id;
    nom = _nom;
    h = _h;
}

void mergeID(Competidor arr[], int izq, int m, int der) {
    int n1 = m - izq + 1;
    int n2 = der - m;
    Competidor L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeN(Competidor arr[], int izq, int m, int der) {
    int n1 = m - izq + 1;
    int n2 = der - m;
    Competidor L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i].nom <= R[j].nom) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeH(Competidor arr[], int izq, int m, int der) {
    int n1 = m - izq + 1;
    int n2 = der - m;
    Competidor L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i].h <= R[j].h) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeS(Competidor arr[], int izq, int der, int opc) {
    if (izq < der) {
        int m = izq + (der - izq) / 2;
        mergeS(arr, izq, m, opc);
        mergeS(arr, m + 1, der, opc);
        switch (opc) {
            case 1: mergeID(arr, izq, m, der); break;
            case 2: mergeN(arr, izq, m, der); break;
            case 3: mergeH(arr, izq, m, der); break;
        }
    }
}
