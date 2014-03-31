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
  int valor;
}Casilla;

#endif
