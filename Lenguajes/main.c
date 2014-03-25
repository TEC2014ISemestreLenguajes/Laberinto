#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Casilla.h"
#include "Matriz.h"
#include "Lista.h"

/*
 * Instituto Tecnológico de Costa Rica
 * Escuela de Ingeniería en Computación
 * Lenguajes de Programación
 * Prof. Eddy Ramírez
 * Estudiantes:
 *	José Ricardo Brenes Camacho(201236179)
 *	Melvin Sandoval Quiros(201240810)
 *
 */



int main(int argc, char* argv[])
{
    Lista * lis;
    inicializacion(lis);

    ins_fin_lista(lis,1,0);
    Casilla** matriz = crearMatrizAleatoria();
    /*Nodo_t* aux;
    aux = calloc(1,sizeof(Nodo_t));
    if(aux == NULL){
        printf("Error");
        return 0;
    }*/
    lis->inicio = buscarMenor(lis->inicio,matriz,10,10);
    //lis->inicio = buscarMenor(lis,matriz,2,2);
    //printf("Valor %d \n",matriz[0][0].paredAbajo);
    //printf("Lista %d",lis->inicio->x);
    return 0;

}
