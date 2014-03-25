#ifndef MATRIZ_C
#define MATRIZ_C

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Casilla.h"
#include "Matriz.h"

Casilla** crearMatrizAleatoria(){
  int i,j,m,n;


  printf("Ingrese el numero de filas\n");
  scanf("%d",&m);
  printf("Ingrese el numero de columas\n");
  scanf("%d",&n);

  Casilla ** matriz;
  matriz = malloc(m*sizeof(Casilla*));

  int seed = time(NULL);
  srand(seed);

  for(i=0;i<m;i++)
    matriz[i] = malloc(n*sizeof(Casilla));

  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      matriz[i][j].valor = (rand() % 100) + 1;
      matriz[i][j].paredArriba = true;
      matriz[i][j].paredAbajo = true;
      matriz[i][j].paredDerecha = true;
      matriz[i][j].paredIzquierda = true;
      matriz[i][j].visita = false;
      printf("%d\t",matriz[i][j].valor);
    }
    printf("\n");
  }
  printf("\n\n");
  return matriz;

}
Nodo_t * buscarMenor(Nodo_t* _nodo, Casilla** matriz, int m , int n){
    Nodo_t* aux;
    aux = malloc(sizeof(Nodo_t));
    int i;
    int minimo = 101;
    int fila, colum = -1;
    int pared = 0;
    for(i = 1; i <= 4; i ++){
        switch(i){
            case 1:{
                int a = _nodo->x;
                int b = _nodo->y;
                if((a -1 >= 0)&&(matriz[a-1][b].visita == false)){
                    if(matriz[a-1][b].valor < minimo){
                        minimo = matriz[a-1][b].valor;
                        fila = a-1;
                        colum = b;
                        pared = 1;
                        printf("Minimo %d\n", minimo);
                    }
                }
            }
            case 2:{
                int a = _nodo->x;
                int b = _nodo->y;
                if((b+1 <= n)&&(matriz[a][b+1].visita == false)){
                    if(matriz[a][b+1].valor < minimo){
                        minimo = matriz[a][b+1].valor;
                        fila = a;
                        colum = b+1;
                        pared = 2;
                        printf("Minimo %d\n", minimo);
                    }
                }
            }
            case 3:{
                int a = _nodo->x;
                int b = _nodo->y;
                if((a+1 <= m)&&(matriz[a+1][b].visita == false)){
                    if(matriz[a+1][b].valor < minimo){
                        minimo = matriz[a+1][b].valor;
                        fila = a+1;
                        colum = b;
                        pared = 3;
                        printf("Minimo %d\n", minimo);
                    }
                }
            }
            case 4:{
                int a = _nodo->x;
                int b = _nodo->y;
                if((b-1 >= 0)&&(matriz[a][b-1].visita == false)){
                    if(matriz[a][b-1].valor < minimo){
                        minimo = matriz[a][b-1].valor;
                        fila = a;
                        colum = b-1;
                        pared = 4;
                        printf("Minimo %d\n", minimo);
                    }
                }
            }
            default:
                break;
            /*if(i == 1){
            int a = _nodo->x;
            int b = _nodo->y;
            if((a -1 >= 0)&&(matriz[a-1][b].visita == false)){
            if(matriz[a-1][b].valor < minimo){
            printf(":D");
            minimo = matriz[a-1][b].valor;
            fila = a-1;
            colum = b;
            pared = 1;
            }
            }
            }*/
            /*switch(i){
            case 1:
            //int a = &_nodo->x;
            int b = _nodo->y;
            if((a -1 >= 0)&&(matriz[a][b]->visita == false)){
            printf("Es 1\n");
            }
            break;
            case 2:
            printf("Es 2\n");
            break;
            case 3:
            printf("Es 3\n");
            break;
            case 4:
            printf("Es 4\n");
            break;
            default:
            break;
            }*/
            }
            return aux;
        }
}
#endif
