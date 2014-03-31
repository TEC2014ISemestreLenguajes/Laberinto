#ifndef MATRIZ_C
#define MATRIZ_C

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Casilla.h"
#include "Matriz.h"

Casilla** crearMatrizAleatoria(int m,int n,int quesos,int venenos){
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
      if((rand()%2)+1 == 1 && venenos != 0){
        matriz[i][j].veneno = true;
        venenos --;
      }
      if((rand()%2)+1 > 1 && matriz[i][j].veneno == false && quesos != 0){
        matriz[i][j].queso = true;
        quesos --;
      }
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

    Insertar(&lis,0,0,matriz[0][0].valor,-1);
    matriz[0][0].visita = true;
    pNodo aux,nmenor;
    aux = (pNodo)malloc(sizeof(tipoNodo));
    nmenor = (pNodo)malloc(sizeof(tipoNodo));
    for(i =1; i <= (m*n);i++){
        aux = lis;
        nmenor->menor = 101;


        while(aux){
            pNodo aux2 = buscarMenor(aux,matriz,m,n);
            //printf("%d -> ",aux->menor);
            if(aux2->menor < nmenor->menor){
                nmenor = aux2;

            }
            aux = aux->siguiente;
        }

        //printf("\n");

        int a = nmenor->x;
        int b = nmenor->y;
        int pared = nmenor->pared;
        int menor = nmenor->menor;

        matriz[a][b].visita = true;
        switch(pared){
            case 1:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    matriz[a][b].paredAbajo = false;
                    matriz[a+1][b].paredArriba = false;
                    }
                else{
                matriz[a][b].paredAbajo = 0;
                matriz[a + 1][b].paredArriba = 0;
                break;
                }
            }
            case 2:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    matriz[a][b].paredIzquierda = false;
                    matriz[a][b-1].paredDerecha = false;
                    }
                else{
                matriz[a][b].paredIzquierda = 0;
                matriz[a][(b-1)].paredDerecha = 0;
                }
                break;
            }
            case 3:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
                    matriz[a][b].paredArriba = false;
                    matriz[a-1][b].paredAbajo = false;
                    }
                else{
                matriz[a][b].paredArriba = 0;
                matriz[a-1][b].paredAbajo = 0;
                }
                break;
            }
            case 4:{
                if(a < 0 || a > m-1 || b < 0 || b > n-1){
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

    }
    return matriz;
}

void verCamino(Casilla ** matriz,int m ,int n){
    int i;
    for(i = 0; i < m ; i++){
        int j;
        for(j =0; j <n ; j ++){
            printf("Matriz[%d][%d] -%d-%d-%d-%d",i,j,matriz[i][j].paredArriba,matriz[i][j].paredDerecha, matriz[i][j].paredAbajo,matriz[i][j].paredIzquierda);
        } printf("\n");
    }
}

#endif
