#include "laberinto.h"

char* elegirImagen(char* original,int queven){
    char* extension = "q.png";
    if(queven == 1){
        extension = "v.png";
    }
    if(queven == 2){
        printf("Original %s",original);
        extension = "r1.png";
    }
    if(queven == 3){
        printf("Original %s",original);
        extension = "r2.png";
    }
    if(queven == 4){
        extension = "r3.png";
    }
    char *nombreExtension = malloc(strlen(original)+1+strlen(extension));
    strcpy(nombreExtension,original);
    strcat(nombreExtension,extension);
    return nombreExtension;
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
            usleep(50000);
        }
    }
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
  pthread_join(controlador_thread,NULL);

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
                    bool raton1 = maze->matrizLogica[xLog][yLog].raton1;
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
                 /*if(raton1){
                    if(nombreImagen == "fondo.png"||nombreImagen == "fondoq.png"||nombreImagen == "fondov.png")
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
                }*/
                maze->matrizLogica[xLog][yLog].imagen = nombreImagen;
                gtk_image_set_from_file(((GtkImage*)maze->matrizGrafica[xLog][yLog]),nombreImagen);
    }
}
