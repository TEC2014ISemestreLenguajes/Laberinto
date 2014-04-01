#ifndef RATON_H
#define RATON_H
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
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
void randomR(Casilla** matriz,int i, int j);
void colocarRaton(Casilla** matrizLog,int i, int j, GtkWidget*** matrizGraf,int caso);
char* elegirImagen2(char* original,int queven);
#endif
