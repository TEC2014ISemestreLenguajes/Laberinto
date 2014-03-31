#ifndef COLA_H
#define COLA_H
#include <stdlib.h>
#include <stdio.h>
#include "Casilla.h"

typedef struct Cola {
   struct Casilla* elem;
   struct Cola* siguiente;
}Cola;

typedef Cola* cNodo;


/* Funciones con colas: */
void Anadir(cNodo* cola,cNodo nuevo);
void Extraer(cNodo *primero);
#endif
