#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
   int x;
   int y;
   int pared;
   int menor;
   struct _nodo *siguiente;
} tipoNodo;


typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int x,int y,int menor,int pared);
int ListaVacia(Lista l);
void MostrarLista(Lista l);
#endif
