#ifndef MATRIZ_H
#define MATRIZ_H

Casilla** crearMatrizAleatoria(int m, int n, int quesos, int venenos);
pNodo buscarMenor(pNodo nodo, Casilla** matriz, int m , int n);
void verCamino(Casilla** matriz, int m, int n);

#endif // MATRIZ_H
