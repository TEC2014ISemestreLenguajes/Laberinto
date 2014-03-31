#include <stdlib.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include "Casilla.h"

typedef struct laberinto{
    Casilla** matrizLogica;
    GtkWidget*** matrizGrafica;
    int filas;
    int columnas;
}laberinto;

char* elegirImagen(char* original,bool queven);
void* updateCasilla(void* parametro);
void callThread(Casilla** matrizLogica, GtkWidget*** matriz,int filasLog,int columLog);
void verificarCasilla(int coordX,int coordY,laberinto* maze,bool paredArriba,bool paredAbajo,bool paredDerecha,bool paredIzquierda, char* nombreImagen);
