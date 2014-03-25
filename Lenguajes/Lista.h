#ifndef LISTA_H
#define LISTA_H

# include <stdio.h>

typedef struct Nodo {
       int x;
       int y;
       int pared;
       int menor;
       struct Nodo* sig;
}Nodo_t;

typedef struct Lista {
		Nodo_t *inicio;
		Nodo_t *fin;
}Lista;

void inicializacion (Lista *lista);

int ins_fin_lista (Lista * lista,int x ,int y);
int ins_nodo(Lista * lista, Nodo_t * nodo);
#endif
