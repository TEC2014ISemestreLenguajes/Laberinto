#include "raton.h"

char* elegirImagen2(char* original,int queven){
    char* extension = "q.png";
    if(queven == 1){
        extension = "v.png";
    }
    if(queven == 2){
        extension = "r1.png";
    }
    if(queven == 3){
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
        if(nodo->elem->paredArriba == false){
            int x = nodo->elem->x -1;
            int y = nodo->elem->y;
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
        anchura(cola,matriz);
    }

}
void randomR(Casilla** matriz,int i, int j){
    int seed = time(NULL);
    srand(seed);
    int k = 0;
    //Mostrar Imagen;
    while(!matriz[i][j].veneno){
        int caso = (rand()%4) +1;
        printf("%d ->",matriz[i][j].valor);
        printf("\n Caso %d \n",caso);

        switch(caso){
        case 1:
            if(matriz[i][j].paredArriba == false){
                i = i -1;
            }
            break;
        case 2:
            if(matriz[i][j].paredDerecha == false){
                j = j +1;
            }
            break;
        case 3:
            if(matriz[i][j].paredAbajo == false){
                i = i +1;
            }
            break;
        case 4:
            if(matriz[i][j].paredIzquierda == false){
                j = j -1;
            }
            break;
        default:
            return;
            break;
        }
        k ++;
    }
}

void colocarRaton(Casilla** matrizLog,int i, int j, GtkWidget*** matrizGraf,int caso){
    bool raton1 = false;
    int seed = time(NULL);
    srand(seed);

    while(!raton1){
        int a = rand()%i;
        int b = rand()%j;
        if(!matrizLog[a][b].veneno&&!matrizLog[a][b].queso&&!matrizLog[a][b].raton1&&!matrizLog[a][b].raton2&&!matrizLog[a][b].raton3)
        {
            char* nombre = matrizLog[a][b].imagen;
            char* imag;

            if(nombre[0] == 'f'){
                imag = elegirImagen("fondo",caso);
                }
            else{
                if(nombre[1] == '.'){
                    char aux = nombre[0];
                    imag = elegirImagen(&aux,caso);
                }
                else{

                    char  pChar = nombre[0];
                    char  sChar = nombre[1];
                    printf("Antes %c %c \n",pChar,sChar);
                    char * nueva = malloc(strlen(&pChar)+1+strlen(&sChar));
                    strcpy(nueva,&pChar);
                    printf("La nueva : %s \n",nueva);
                    char* extension = "r1.png";
                    if(caso == 2){extension = "r1.png";}
                    if(caso == 3){extension = "r2.png";}
                    if(caso == 4){extension = "r3.png";}

                    char *nombreExtension = malloc(strlen(nueva)+1+strlen(extension));
                    strcpy(nombreExtension,nueva);
                    strcat(nombreExtension,extension);
                    imag = nombreExtension;
                }
            }
            if(caso == 2){matrizLog[a][b].raton1 = true;}
            if(caso == 3){matrizLog[a][b].raton2 = true;}
            if(caso == 4){matrizLog[a][b].raton3 = true;}
            printf("Imagen del raton%d es = %s\n",caso,imag);
            gtk_image_set_from_file((matrizGraf[a][b]),imag);
            raton1 = true;
        }
    }
    //gtk_main ();
}
