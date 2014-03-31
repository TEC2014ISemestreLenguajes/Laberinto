#ifndef RATON_H
#define RATON_H
#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "Casilla.h"



typedef struct raton {
   int x;
   int y;
   bool vida;
   int velocidad;
   struct Casilla ** matriz;
} raton;

typedef raton* pRaton;

void profundidad(pRaton * raton, Pila * pila);
void anchura(cNodo *cola, Casilla** matriz);
//void ramdon(pRaton raton);
#endif
