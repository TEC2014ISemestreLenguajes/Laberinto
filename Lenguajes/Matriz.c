#ifndef MATRIZ_C
#define MATRIZ_C

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Casilla.h"
#include "Matriz.h"

Casilla** crearMatrizAleatoria(int m,int n){
  int i,j;

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
pNodo buscarMenor(pNodo _nodo, Casilla** matriz, int m , int n){
    pNodo aux;
    aux = (pNodo)malloc(sizeof(tipoNodo));
    int i;
    int minimo = 101;
    int fila, colum = -1;
    int pared = 0;
    int a = _nodo->x;
    int b = _nodo->y;
    for(i = 1; i <= 4; i ++){
        switch(i){
            case 1:{
                if((a -1 >= 0)&&(matriz[a-1][b].visita == false)){
                    if(matriz[a-1][b].valor < minimo){
                        minimo = matriz[a-1][b].valor;
                        fila = a-1;
                        colum = b;
                        pared = 1;
                        //printf("Minimo %d\n", minimo);
                    }
                }
            }
            case 2:{
                if((b+1 < n)&&(matriz[a][b+1].visita == false)){
                    if(matriz[a][b+1].valor < minimo){
                        minimo = matriz[a][b+1].valor;
                        fila = a;
                        colum = b+1;
                        pared = 2;
                        //printf("Minimo %d\n", minimo);
                    }
                }
            }
            case 3:{
                if((a+1 < m)&&(matriz[a+1][b].visita == false)){
                    if(matriz[a+1][b].valor < minimo){
                        minimo = matriz[a+1][b].valor;
                        fila = a+1;
                        colum = b;
                        pared = 3;
                        //printf("Minimo %d\n", minimo);
                    }
                }
            }
            case 4:{
                if((b-1 >= 0)&&(matriz[a][b-1].visita == false)){
                    if(matriz[a][b-1].valor < minimo){
                        minimo = matriz[a][b-1].valor;
                        fila = a;
                        colum = b-1;
                        pared = 4;
                        //printf("Minimo %d\n", minimo);
                    }
                }
            }
            default:
                break;
            }
        }
    aux->x = fila;
    aux->y = colum;
    aux->menor = minimo;
    aux->pared = pared;
    aux->siguiente = NULL;
    return aux;
}
Casilla ** camino(Casilla** matriz,int m,int n){
    int i;
    Lista lis = NULL;
    //lis = (Lista)malloc(sizeof(tipoNodo)*(m*n));

    Insertar(&lis,0,0,matriz[0][0].valor,-1);
    matriz[0][0].visita = true;
    pNodo aux,nmenor;
    aux = (pNodo)malloc(sizeof(tipoNodo));
    nmenor = (pNodo)malloc(sizeof(tipoNodo));
    for(i =1; i <= (m*n);i++){
        //pNodo aux,nmenor;
        //aux = (pNodo)malloc(sizeof(tipoNodo));
        //nmenor = (pNodo)malloc(sizeof(tipoNodo));
        aux = lis;
        nmenor->menor = 101;
        //int j = 1;

        while(aux){
            pNodo aux2 = buscarMenor(aux,matriz,m,n);
            printf("%d -> ",aux->menor);
            if(aux2->menor < nmenor->menor){
                nmenor = aux2;

            }
            aux = aux->siguiente;
        }
        //free(aux);

        printf("\n");
        //printf("SI \n");
        int a = nmenor->x;
        int b = nmenor->y;
        int pared = nmenor->pared;
        int menor = nmenor->menor;
        //free(aux);
        //free(nmenor);
        //printf("Salio, pared %d \n" ,pared);
        //printf("A %d B %d \n",a,b);
        matriz[a][b].visita = true;
        switch(pared){
            case 1:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    //printf("ME SALI DEL RANGO 1\n");
                    //printf("%d = pared Arriba %d = pared Abajo \n",matriz[a+1][b].paredArriba,matriz[a][b].paredAbajo);
                    matriz[a][b].paredAbajo = false;
                    matriz[a+1][b].paredArriba = false;
                    //return matriz;
                    }
                else{
                //printf("Antes A %d B %d\n",a+1,b);
                matriz[a][b].paredAbajo = 0;
                matriz[a + 1][b].paredArriba = 0;
                break;
                }
            }
            case 2:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    //printf("ME SALI DEL RANGO 2\n");
                    //printf("%d = pared Derecha %d = pared Izquierda\n",matriz[a][b-1].paredDerecha,matriz[a][b].paredIzquierda);
                    matriz[a][b].paredIzquierda = false;
                    matriz[a][b-1].paredDerecha = false;
                    //return matriz;
                    }
                else{
                matriz[a][b].paredIzquierda = 0;
                matriz[a][(b-1)].paredDerecha = 0;
                }
                break;
            }
            case 3:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    //printf("ME SALI DEL RANGO 3 a = %d\n",a);
                    //printf("%d = pared Arriba %d = pared Abajo\n",matriz[a][b].paredArriba,matriz[a][b].paredAbajo);
                    //return matriz;
                    matriz[a][b].paredArriba = false;
                    matriz[a-1][b].paredAbajo = false;
                    //printf("%d = pared Arriba %d = pared Abajo\n",matriz[a][b].paredArriba,matriz[a][b].paredAbajo);
                    }
                else{
                matriz[a][b].paredArriba = 0;
                matriz[a-1][b].paredAbajo = 0;
                }
                break;
            }
            case 4:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    //printf("ME SALI DEL RANGO 4\n");
                    //printf("%d = pared Derecha %d = pared Izquierda\n",matriz[a][b].paredDerecha,matriz[a][b+1].paredIzquierda);
                    //return matriz;
                    matriz[a][b].paredDerecha = false;
                    matriz[a][b+1].paredIzquierda = false;
                    }
                else{
                matriz[a][b].paredDerecha = 0;
                matriz[a][b+1].paredIzquierda = 0;
                }
                break;
            }
        }

        Insertar(&lis,a,b,menor,pared);
        //printf("I = %d \n",i);

    }
    return matriz;
}
#endif
