#include "cola.h"

void Anadir(cNodo *co, cNodo nue)
{
    cNodo nuevo = nue;
    if(*co == NULL){
        nuevo->siguiente = NULL;
        *co = nuevo;
    }
    else{
        cNodo aux = (*co);
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->siguiente = NULL;
    }
}

void Extraer(cNodo *prim){
    if(*prim != NULL){
        cNodo aux = *prim;
        *prim = aux->siguiente;
        aux->siguiente = NULL;
    }
}
