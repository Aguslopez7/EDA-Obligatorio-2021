#include "linea.h"
#include "palabra.h"
#include <stdio.h>

struct nodo_linea
{ 
   int indice;
   linea sig;
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
        aux2->indice+=l->indice;
    }
    else{                             //hay mas lineas
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=aux2;
        aux2->sig=NULL;
        aux2->indice+=aux->indice;
    }
    return OK;
}