#ifndef CASILLA_H
#define CASILLA_H
#include <stdbool.h>

typedef struct Casilla{
  bool paredArriba;
  bool paredAbajo;
  bool paredDerecha;
  bool paredIzquierda;
  bool visita;
  bool queso;
  bool veneno;
  bool ratonProf;
  bool ratonAnch;
  bool raton1;
  bool raton2;
  bool raton3;
  int valor;
  int x;
  int y;
  struct Casilla *siguiente;
}Casilla;

typedef Casilla *piNodo;
typedef Casilla *Pila;
#endif
