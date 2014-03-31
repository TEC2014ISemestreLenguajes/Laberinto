#include <stdlib.h>
#include <gtk/gtk.h>
#include <pthread.h>

#include "Casilla.h"
#include "Matriz.h"
#include "Lista.h"

typedef struct laberinto{
    Casilla** matrizLogica;
    GtkWidget*** matrizGrafica;
    int filas;
    int columnas;
}laberinto;

char* elegirImagen(char* original,bool queven){
    char* extension = "q.png";
    if(queven == true){
        extension = "v.png";
    }
    char *nombreExtension = malloc(strlen(original)+1+strlen(extension));
    strcpy(nombreExtension,original);
    strcat(nombreExtension,extension);
    printf("%s",nombreExtension);
    return nombreExtension;
}


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

  verCamino(matrizLog,m,n);

  gtk_main ();
  free(matriz);
  return 0;
}

void* updateCasilla(void* parametro){
    laberinto *maze = (laberinto*)parametro;
    int filas = maze->filas;
    int columnas = maze->columnas;
    int xLog,yLog;
    for(xLog = 0; xLog < filas; xLog++){
        //printf("%d = xLog %d = yLog %d = maze->filas %d = maze->columnas\n",xLog,yLog,filas,columnas);
        for(yLog = 0; yLog < maze->columnas; yLog++){
            verificarCasilla(xLog,yLog,maze,0,0,0,0,"fondo.png");
            verificarCasilla(xLog,yLog,maze,0,0,0,1,"7.png");
            verificarCasilla(xLog,yLog,maze,0,0,1,0,"6.png");
            verificarCasilla(xLog,yLog,maze,0,0,1,1,"15.png");
            verificarCasilla(xLog,yLog,maze,0,1,0,0,"1.png");
            verificarCasilla(xLog,yLog,maze,0,1,0,1,"2.png");
            verificarCasilla(xLog,yLog,maze,0,1,1,0,"5.png");
            verificarCasilla(xLog,yLog,maze,0,1,1,1,"12.png");
            verificarCasilla(xLog,yLog,maze,1,0,0,0,"13.png");
            verificarCasilla(xLog,yLog,maze,1,0,0,1,"9.png");
            verificarCasilla(xLog,yLog,maze,1,0,1,0,"10.png");
            verificarCasilla(xLog,yLog,maze,1,0,1,1,"8.png");
            verificarCasilla(xLog,yLog,maze,1,1,0,1,"11.png");
            verificarCasilla(xLog,yLog,maze,1,1,1,0,"4.png");
            verificarCasilla(xLog,yLog,maze,1,1,0,0,"14.png");
            printf("termine ciclo1\n");
            usleep(50000);
        }
        printf("termine ciclo2\n");
    }
    printf("termine ciclos\n");
    //return NULL;*/
}

void callThread(Casilla** matrizLogica, GtkWidget*** matriz,int filasLog,int columLog){

  pthread_t* controlador_thread;
  controlador_thread = malloc(sizeof(pthread_t));

  //printf("filasLog antes = %d ",filasLog);

  laberinto *parametro = malloc(sizeof(laberinto));
  parametro->columnas = columLog;
  parametro->filas = filasLog;
  parametro->matrizGrafica = matriz;
  parametro->matrizLogica = matrizLogica;
  //printf("filasif((rand()%100)+1 < 50 && venenos != 0){ matriz[i][j].veneno = true; venenos --; } if((rand()%100)+1 >= 50 && matriz[i][j].veneno != false &&quesos != 0){ matriz[i][j].queso = true; quesos --; }Log = %d\n",parametro->filas);

  //printf("filasLog despues = %d ",filasLog);

  pthread_create(&controlador_thread,NULL,updateCasilla,(void*)parametro);

}

void verificarCasilla(int coordX,int coordY,laberinto* maze,bool paredArriba,bool paredAbajo,bool paredDerecha,bool paredIzquierda, char* nombreImagen){
    int xLog = coordX;
    int yLog = coordY;
    if(maze->matrizLogica[xLog][yLog].paredArriba == paredArriba &&
                maze->matrizLogica[xLog][yLog].paredAbajo == paredAbajo &&
                maze->matrizLogica[xLog][yLog].paredDerecha == paredDerecha &&
                maze->matrizLogica[xLog][yLog].paredIzquierda == paredIzquierda ){
                    bool queso = maze->matrizLogica[xLog][yLog].queso;
                    bool veneno = maze->matrizLogica[xLog][yLog].veneno;
                    printf("\nCambiaron paredes 1 = %d 2 = %d 3 = %d 4 = %d del valor %d\n",
                        paredArriba,paredAbajo,paredDerecha,paredIzquierda,maze->matrizLogica[xLog][yLog].valor);
                    gtk_image_set_from_file (((GtkImage*)maze->matrizGrafica[xLog][yLog]),nombreImagen);
                if(queso||veneno){
                    if(nombreImagen == "fondo.png")
                        nombreImagen = elegirImagen("fondo",veneno);
                    if(nombreImagen == "1.png")
                        nombreImagen = elegirImagen("1",veneno);
                    if(nombreImagen == "2.png")
                        nombreImagen = elegirImagen("2",veneno);
                    if(nombreImagen == "3.png")
                        nombreImagen = elegirImagen("3",veneno);
                    if(nombreImagen == "4.png")
                        nombreImagen = elegirImagen("4",veneno);
                    if(nombreImagen == "5.png")
                        nombreImagen = elegirImagen("5",veneno);
                    if(nombreImagen == "6.png")
                        nombreImagen = elegirImagen("6",veneno);
                    if(nombreImagen == "7.png")
                        nombreImagen = elegirImagen("7",veneno);
                    if(nombreImagen == "8.png")
                        nombreImagen = elegirImagen("8",veneno);
                    if(nombreImagen == "9.png")
                        nombreImagen = elegirImagen("9",veneno);
                    if(nombreImagen == "10.png")
                        nombreImagen = elegirImagen("10",veneno);
                    if(nombreImagen == "11.png")
                        nombreImagen = elegirImagen("11",veneno);
                    if(nombreImagen == "12.png")
                        nombreImagen = elegirImagen("12",veneno);
                    if(nombreImagen == "13.png")
                        nombreImagen = elegirImagen("13",veneno);
                    if(nombreImagen == "14.png")
                        nombreImagen = elegirImagen("14",veneno);
                    if(nombreImagen == "15.png")
                        nombreImagen = elegirImagen("15",veneno);
                }
                gtk_image_set_from_file(((GtkImage*)maze->matrizGrafica[xLog][yLog]),nombreImagen);
    }
}








