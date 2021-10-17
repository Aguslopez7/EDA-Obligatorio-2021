#include "linea.h"
#include "palabra.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int cantl=0;

struct nodo_linea
{ 
   int indice;
   linea sig;
   linea ant;
   palabra pal;
};

//Crea la estructura del linea
linea CrearLinea(){
    linea l = new (nodo_linea);
    l->sig = NULL;
    l->indice=1;
    l->pal=CrearPalabra();
    return l;
}

//insertar linea al final
TipoRetorno InsertarLineaEnTextoUlt(linea &l){
    
    linea aux2= new(nodo_linea);
    linea aux=l;
    if(l->sig==NULL){                       //primera linea
        aux->sig=aux2;
        aux2->sig= NULL;
        aux2->indice=aux2->indice+l->indice;
        cout<<aux2->indice;
        cout<<l->indice;
        cantl++;
    
    }
    else{                             //hay mas lineas
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=aux2;
        aux2->sig=NULL;
        aux2->indice=aux2->indice+l->indice;
        cout<<aux2->indice;
        cantl++;
    }
    return OK;
}

TipoRetorno InsertarLineaEnPosicion(linea &l, Posicion posicionLinea)
{
    linea aux2 = new (nodo_linea);
    linea aux = l;
    linea aux3 = l;
    if ((posicionLinea >= 1) && (posicionLinea <= aux->indice))
    { 
         aux = aux->sig;

        aux3 = aux->ant;
        aux->ant = aux2;
        aux2->sig = aux;
        aux2->ant = aux3;
        aux3->sig = aux2;
        aux2->indice = posicionLinea;
        cantl++;
        while (aux2->sig != NULL)
        {
            aux2 = aux2->sig;
            aux2->indice++;
        }
        
        return OK;
    }
    else
        return ERROR;
}

TipoRetorno ImprimirLinea(linea &l, Posicion posicionLinea){

    linea aux=l;
    
    while(aux->indice != posicionLinea)
        aux=aux->sig;

    cout<<"\n\t"<<posicionLinea<<": ";
    

    return OK;
}
//hola