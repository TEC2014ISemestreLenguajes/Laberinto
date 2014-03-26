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
                if((b+1 <= n)&&(matriz[a][b+1].visita == false)){
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
                if((a+1 <= m)&&(matriz[a+1][b].visita == false)){
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
    printf(":s");
    int i;
    Lista lis = NULL;
    //lis = (Lista)malloc(sizeof(tipoNodo)*(m*n));

    Insertar(&lis,0,0,matriz[0][0].valor,-1);
    matriz[0][0].visita = true;


    for(i =2; i <= (m*n);i++){
        pNodo aux,nmenor;
        aux = (pNodo)malloc(sizeof(tipoNodo));
        nmenor = (pNodo)malloc(sizeof(tipoNodo));
        aux = lis;
        nmenor->menor = 101;
        int j = 1;

        while(aux){
            pNodo aux2 = buscarMenor(aux,matriz,m,n);
            printf("%d -> ",aux->menor);
            if(aux2->menor < nmenor->menor){
                nmenor = aux2;

            }
            aux = aux->siguiente;
        }
        free(aux);

        printf("\n");
        int a = nmenor->x;
        int b = nmenor->y;
        int pared = nmenor->pared;
        int menor = nmenor->menor;
        //free(aux);
        free(nmenor);
        printf("Salio, pared %d \n" ,pared);
        matriz[a][b].visita = true;
        switch(pared){
            case 1:{
                matriz[a][b].paredAbajo = 0;
                matriz[a + 1][b].paredArriba = 0;
            }
            case 2:{
                matriz[a][b].paredIzquierda = 0;
                matriz[a][b-1].paredDerecha = 0;
            }
            case 3:{
                matriz[a][b].paredArriba = 0;
                matriz[a-1][b].paredAbajo = 0;
            }
            case 4:{
                matriz[a][b].paredDerecha = 0;
                matriz[a][b+1].paredIzquierda = 0;
            }
        }

        Insertar(&lis,a,b,menor,pared);

        /*printf("For i = %d \n",i);
        int c;
        for(c = 0; c < 5; c++){
            if(matriz[0][c].paredIzquierda != 0){
                printf("║ ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
        for(c = 0; c <5 ; c++){
            if(matriz[c][0].paredAbajo != 0){
                printf(" T ");
            }
            else{
                printf("  ");
            }
        }*/
    }
    return matriz;
}
#endif
