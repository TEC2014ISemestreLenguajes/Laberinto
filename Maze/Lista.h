#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

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
//void Borrar(Lista *l, int v);

int ListaVacia(Lista l);

//void BorrarLista(Lista *);
void MostrarLista(Lista l);


#endif // LISTA_H_INCLUDED
