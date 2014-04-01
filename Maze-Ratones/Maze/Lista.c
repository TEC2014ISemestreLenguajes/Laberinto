#ifndef LISTA_C
#define LISTA_C
#include "Lista.h"
void Insertar(Lista *l, int x,int y,int menor,int pared){
   pNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->x = x;
   nuevo->y = y;
   nuevo->menor = menor;
   nuevo->pared = pared;

   /* Si la lista está vacía */
   if(ListaVacia(*l)) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *l;
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *l = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *l;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(anterior->siguiente)
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
}
/*
void Borrar(Lista *lista, int v) {
   pNodo anterior, nodo;

   nodo = *lista;
   anterior = NULL;
   while(nodo && nodo->valor < v) {
      anterior = nodo;
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { /* Borrar el nodo
      if(!anterior) /* Primer elemento
         *lista = nodo->siguiente;
      else  /* un elemento cualquiera
         anterior->siguiente = nodo->siguiente;
      free(nodo);
   }
}
*/
int ListaVacia(Lista lista) {
   return (lista == NULL);
}
/*
void BorrarLista(Lista *lista) {
   pNodo nodo;

   while(*lista) {
      nodo = *lista;
      *lista = nodo->siguiente;
      free(nodo);
   }
}
*/
void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {
         printf("%d -> ", nodo->menor);
         nodo = nodo->siguiente;
     }
     printf("\n");
   }
}
#endif
