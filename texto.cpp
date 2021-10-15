#include "texto.h"
#include "linea.h"
#include <stdio.h>

struct nodo_texto
{
    linea primeral;
    linea ultimal;
};

//Crea la estructura del texto
texto CrearTexto(){
    texto t = new (nodo_texto);
    t->primeral = CrearLinea();
    t->ultimal = NULL;
    return t;
}

//Inserta la linea al final del texto
TipoRetorno insertarLineaEnTexto(texto & t){
    //Snoc
    return NO_IMPLEMENTADA;
}