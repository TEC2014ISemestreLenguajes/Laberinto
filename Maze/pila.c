#include "pila.h"

void Push(Pila *pila, Casilla * v)
{
   v->siguiente = *pila;
   *pila = v;
}

piNodo Pop(Pila *pila)
{
   piNodo nodo;
   nodo = *pila;
   if(!nodo) return nodo;
   *pila = nodo->siguiente;
   return nodo;
}
