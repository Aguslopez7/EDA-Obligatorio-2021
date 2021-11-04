#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "definiciones.h"

typedef struct nodo_abb * dicc;

/*--------------------- Funciones --------------------*/

dicc CrearDiccionario();

// 12) Agrega una palabra al diccionario.
TipoRetorno IngresarPalabraDiccionarioD(dicc &d, Cadena palabraAIngresar);

// 13) Borra una palabra del diccionario.
TipoRetorno BorrarPalabraDiccionarioD(dicc &d, Cadena palabraABorrar);

// 13) Funciones Auxiliares
dicc BorrarPalabra(dicc &d, Cadena pal);
dicc min_de(dicc & d);
dicc max_iz(dicc & d);
int profundidad(dicc d);

//14) Muestra las palabras del diccionario alfabéticamente.
TipoRetorno ImprimirDiccionarioD(dicc &d);

// 14) Funcion Auxiliar
void ImprimirDiccionarioDAux(dicc d);

// 15) Funcion auxiliar
bool PertenecePalabraDicc(dicc d, Cadena pal);

// 16) Imprime las últimas palabras ingresadas.
TipoRetorno ImprimirUltimasPalabras();

#endif