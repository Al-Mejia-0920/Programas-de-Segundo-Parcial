#ifndef ABSTRACTA_H
#define ABSTRACTA_H

#include <iostream>
#include <string>

using namespace std;

class Competidor {
public:
    int id;
    string nom;
    float h;

    Competidor();
    Competidor(int _id, string _nom, float _h);
};

void mergeID(int indices[], Competidor arr[], int izq, int m, int der);
void mergeN(int indices[], Competidor arr[], int izq, int m, int der);
void mergeH(int indices[], Competidor arr[], int izq, int m, int der);
void mergeS(int indices[], Competidor arr[], int izq, int der, int opc);

#endif
