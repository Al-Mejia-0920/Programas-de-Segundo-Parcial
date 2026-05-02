#ifndef ABSTRACTA_H
#define ABSTRACTA_H

#include <string>
#include <iostream>

using namespace std;

class Competidor {
public:
    int id;
    string nom;
    float h;

    Competidor();
    Competidor(int _id, string _nom, float _h);
};

void mergeID(Competidor arr[], int izq, int m, int der);
void mergeN(Competidor arr[], int izq, int m, int der);
void mergeH(Competidor arr[], int izq, int m, int der);
void mergeS(Competidor arr[], int izq, int der, int opc);

#endif
