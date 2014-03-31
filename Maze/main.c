#include <stdlib.h>
#include <gtk/gtk.h>
#include <pthread.h>

#include "Casilla.h"
#include "Matriz.h"
#include "Lista.h"
#include "laberinto.h"
#include "raton.h"
#include "pila.h"
#include "cola.h"


int main (int argc, char *argv[])
{
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  int cantQuesos = atoi(argv[3]);
  int cantVenenos = atoi(argv[4]);

  if((3 < cantVenenos || cantVenenos <= 0) || (0 > cantQuesos || cantQuesos > (m*n))){
    printf("La cantidad de venenos debe estar entre 0 y 3\n");
    printf("La cantidad de quesos debe de ser menor a %d\n",m*n);
    return 0;
  }

  Casilla** matrizLog = crearMatrizAleatoria(m,n,cantQuesos,cantVenenos);
  matrizLog = camino(matrizLog,m,n);

  GtkWidget *win;
  gtk_init(&argc,&argv);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_widget_set_size_request(win, m*40, n*40);
  g_signal_connect(win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
  //set_icon_from_file("icono.png");
  GtkWidget*** matriz = (GtkWidget***)malloc(m*sizeof(GtkWidget**));
  int i;
  for(i = 0;i < m; i++){
    matriz[i] = (GtkWidget**)malloc(n*sizeof(GtkWidget*));
  }

  GtkWidget* matrizGraph = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(win),matrizGraph);

  /*GtkWidget* label1 = gtk_label_new(NULL);
  gtk_label_set_markup (GTK_LABEL (label1), "<small>Puto</small>");
  gtk_container_add(GTK_CONTAINER(win),label1);*/

  gtk_widget_show(matrizGraph);
  //gtk_widget_show(label1);
  gtk_widget_show(win);

  int recFila,recColumna;
  for(recFila = 0; recFila < m; recFila++){
    for(recColumna = 0; recColumna < n; recColumna++){
        matriz[recFila][recColumna] = gtk_image_new_from_file("3.png");
        gtk_grid_attach(GTK_GRID(GTK_CONTAINER(matrizGraph)),matriz[recFila][recColumna],recColumna,recFila,1,1);
        gtk_widget_show(matriz[recFila][recColumna]);
    }
  }

  callThread(matrizLog,matriz,m,n);
  printf("Lo que sea");
  int seed = time(NULL);
  srand(seed);

  pRaton ratonProf;
  ratonProf = (pRaton)malloc(sizeof(raton));
  ratonProf->x = (rand() % m) + 1;;
  ratonProf->y = (rand() % n) + 1;;
  ratonProf->velocidad = 1;
  ratonProf->matriz = matrizLog;
  Pila pila = NULL;
  matrizLog[ratonProf->x][ratonProf->y].ratonProf = true;
  printf("Empezo en %d , %d",ratonProf->x,ratonProf->y);
  Push(&pila,&ratonProf->matriz[ratonProf->x][ratonProf->y]);
  profundidad(&ratonProf,&pila);

//  pRaton ratonAnch;
//    ratonAnch = (pRaton)malloc(sizeof(raton));
//    ratonAnch->x = (rand() % m) + 1;
//    ratonAnch->y = (rand() % n) + 1;
//    printf("Empezo en %d , %d",rato)
//    ratonAnch->velocidad = 1;
//    ratonAnch->matriz = matriz;
//    matriz[1][0].ratonAnch = true;


  gtk_main ();

  free(matriz);
  return 0;
}
