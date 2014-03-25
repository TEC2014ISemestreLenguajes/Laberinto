#include "Lista.h"

void inicializacion (Lista *lista){
		lista->inicio = NULL;
		lista->fin = NULL;
}

/*inserción al final de la lista */
int ins_fin_lista (Lista * lista, int x ,int y){

  Nodo_t *nuevo_elemento;
  nuevo_elemento = (Nodo_t*) malloc (sizeof(Nodo_t));
  nuevo_elemento->x = x;
  nuevo_elemento->y = y;
  nuevo_elemento->sig = NULL;

  if (lista->inicio==NULL) {
         lista->inicio = nuevo_elemento;
         lista->fin = nuevo_elemento;
         }
      else {

           lista->fin->sig = nuevo_elemento;
           lista->fin = nuevo_elemento;
      }
  return 0;
}
int ins_nodo(Lista * lista, Nodo_t * nodo)
{
    if (lista->inicio==NULL) {
         lista->inicio = nodo;
         lista->fin = nodo;
         }
    else {

           lista->fin->sig = nodo;
           lista->fin = nodo;
      }
  return 0;
}
