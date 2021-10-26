#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "definiciones.h"

typedef struct nodo_abb * dicc;

//12) Agrega una palabra al diccionario.
TipoRetorno IngresarPalabraDiccionario(Cadena palabraAIngresar, dicc ab);

//13) Borra una palabra del diccionario.
TipoRetorno BorrarPalabraDiccionario(Cadena palabraABorrar);

//14) Muestra las palabras del diccionario alfabéticamente.
TipoRetorno ImprimirDiccionario();

//15) Muestra las palabras del texto que no se encuentran en el diccionario.
TipoRetorno ImprimirTextoIncorrecto();

//16) Imprime las últimas palabras ingresadas.
TipoRetorno ImprimirUltimasPalabras();

#endif