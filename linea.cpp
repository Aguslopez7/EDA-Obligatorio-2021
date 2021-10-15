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
