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
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    Casilla** matriz = crearMatrizAleatoria(m,n);
    matriz = camino(matriz,m,n);

    return 0;

}
