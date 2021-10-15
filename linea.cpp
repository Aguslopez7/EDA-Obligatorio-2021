#include "linea.h"
#include <stdio.h>

struct nodo_linea
{
   //cadena de caracteres  
   
   linea sig;
};

//Crea la estructura del linea
linea CrearLinea(){
    linea l = new (nodo_linea);
    l->sig = NULL;
    return l;
}

//insertar linea al final
TipoRetorno InsertarLineaEnTextoUlt(linea &l){
    linea aux2= new(nodo_linea);            
    linea aux=l;
    if(l->sig==NULL){                       //primera linea  
        aux->sig=aux2;
        aux2->sig= NULL;
    }
    else{                             //hay mas lineas
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=aux2;
        aux2->sig=NULL;
    }
    return OK;
}