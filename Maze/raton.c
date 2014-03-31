#include "raton.h"
void profundidad(pRaton *raton, Pila *pila){
    piNodo nodo = *pila;
    pRaton rat = *raton;
	if(nodo == NULL){

	}
	else{
        printf("%d->",rat->matriz[rat->x][rat->y].valor);
		if(rat->matriz[rat->x][rat->y].paredArriba == 0 ){
			if(rat->matriz[(rat->x) - 1][rat->y].ratonProf == false){
                //printf("%d->",rat->matriz[rat->x][rat->y].valor);
                rat->matriz[(rat->x) - 1][rat->y].ratonProf = true;
                Push(pila, &rat->matriz[(rat->x)-1][rat->y]);
                rat->x = (rat->x) - 1;
                profundidad(&rat,&nodo);
                rat->x = (rat->x) + 1;
			}
		}
		if(rat->matriz[rat->x][rat->y].paredDerecha == 0 ){
			if(rat->matriz[rat->x][(rat->y) +1].ratonProf == false){
                //printf("%d->",rat->matriz[rat->x][rat->y].valor);
                rat->matriz[rat->x][rat->y+1].ratonProf = true;
                Push(pila, &rat->matriz[rat->x][rat->y]);
                rat->y = rat->y + 1;
                profundidad(&rat,&nodo);
                rat->y = rat->y - 1;
			}
		}
		if(rat->matriz[rat->x][rat->y].paredAbajo == 0 ){
			//printf("No tengo pared abajo\n");
			if(rat->matriz[(rat->x) + 1][rat->y].ratonProf == false){
                //printf("%d->",rat->matriz[rat->x][rat->y].valor);
                rat->matriz[rat->x + 1][rat->y].ratonProf = true;
                Push(pila, &rat->matriz[rat->x][rat->y]);
                rat->x = rat->x + 1;
                profundidad(&rat,&nodo);
                rat->x = rat->x - 1;
			}
		}
		if(rat->matriz[rat->x][rat->y].paredIzquierda == 0 ){
			//printf("No tengo pared Izquierda\n");
			if(rat->matriz[rat->x][(rat->y)-1].ratonProf == false){
                //printf("%d->",rat->matriz[rat->x][rat->y].valor);
                rat->matriz[rat->x][rat->y-1].ratonProf = true;
                Push(pila, &rat->matriz[rat->x][rat->y]);
                rat->y = rat->y - 1;
                profundidad(&rat,&nodo);
                rat->y = rat->y + 1;
			}
		}
		//Llamar a mover raton
		piNodo nodo2 = Pop(pila);
	}
}

void anchura(cNodo *cola, Casilla** matriz){
    if(*cola != NULL){
        cNodo nodo = *cola;
        Extraer(cola);
        printf("%d->",nodo->elem->valor);
        printf("\nCola ");
        if(nodo->elem->paredArriba == false){
            int x = nodo->elem->x -1;
            int y = nodo->elem->y;
            printf("\n Arriba");
            if(matriz[x][y].ratonAnch == false){
                cNodo aux = malloc(sizeof(cNodo));
                aux->elem = &matriz[x][y];
                aux->elem->ratonAnch = true;
                Anadir(cola,aux);
            }
        }
        if(nodo->elem->paredDerecha == false){
            int x = nodo->elem->x;
            int y = nodo->elem->y+1;
            printf("\n Abajo");
            if(matriz[x][y].ratonAnch == false){
                cNodo aux2 = malloc(sizeof(cNodo));
                aux2->elem = &matriz[x][y];
                aux2->elem->ratonAnch = true;
                Anadir(cola,aux2);
            }
        }
        if(nodo->elem->paredAbajo == false){
            int x = nodo->elem->x+1;
            int y = nodo->elem->y;
            if(matriz[x][y].ratonAnch == false){
                cNodo aux3 = malloc(sizeof(cNodo));
                aux3->elem = &matriz[x][y];
                aux3->elem->ratonAnch = true;
                Anadir(cola,aux3);
            }
        }
        if(nodo->elem->paredIzquierda == false){
            int x = nodo->elem->x;
            int y = nodo->elem->y-1;
            if(matriz[x][y].ratonAnch == false){
                cNodo aux4 = malloc(sizeof(cNodo));
                aux4->elem = &matriz[x][y];
                aux4->elem->ratonAnch = true;
                Anadir(cola,aux4);
            }
        }

        cNodo  nodo2 = *cola;
        printf("Cola -");
        while(nodo2 != NULL)
        {
            printf("%d-",nodo2->elem->valor);
            nodo2 = nodo2->siguiente;
        }
        printf("\n");
        int variable;
        printf("Revise el programa: ");
        scanf("%i", &variable);
        anchura(cola,matriz);
    }

}
        /*
        if(nodo->paredDerecha == 0){
            if(rat->matriz[m][n+1].ratonAnch == false){
                cNodo este = &rat->matriz[m][n+1];
                primero = Anadir(primero,ultimo,este);
            }
        }
        if(nodo->paredAbajo== 0){
            if(rat->matriz[m+1][n].ratonAnch == false){
                cNodo este = &rat->matriz[m+1][n];
                primero = Anadir(primero,ultimo,este);
            }
        }
        if(nodo->paredIzquierda == 0){
            if(rat->matriz[m][n-1].ratonAnch == false){
                cNodo este = &rat->matriz[m][n-1];
                primero = Anadir(primero,ultimo,este);
            }
        }
        */
        //printf("Ultimo %d\n",ultimo->valor);
        //if(!primero){
        //anchura(*cola,**matriz);
        //}

    //}
    //printf("Saio\n");
//}
//*/
/*
void ramdon(pRaton raton){
    return void;
}*/
