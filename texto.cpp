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
    t->ultimal = t->primeral;
    //t->primeral = NULL;
    //t->ultimal = NULL;
    return t;
}

//Inserta la linea al final del texto
TipoRetorno InsertarLineaEnTexto(texto &t){
    return InsertarLineaEnTextoUlt(t->ultimal);
}

TipoRetorno ImprimirLineaT(texto &t, Posicion posicionLinea){

    return ImprimirLinea(t->primeral,(posicionLinea));
}
TipoRetorno InsertarLineaEnPosicionT(texto &t, Posicion posicionLinea){

    return InsertarLineaEnPosicion(t->primeral,(posicionLinea));
}
//hola