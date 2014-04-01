#ifndef MATRIZ_H
#define MATRIZ_H
#include "Lista.h"

Casilla** crearMatrizAleatoria(int m,int n,int quesos,int venenos);
pNodo buscarMenor(pNodo nodo, Casilla** matriz, int m , int n);
Casilla ** camino(Casilla** matriz,int m,int n);
void verCamino(Casilla ** matriz,int m ,int n);
#endif
