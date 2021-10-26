#include "diccionario.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//La estructura del diccionario
struct nodo_abb{
	int dato;
	dicc iz;
	dicc de;
};

/*--------------------- Funciones --------------------*/

//12) Agrega una palabra al diccionario.
TipoRetorno IngresarPalabraDiccionario(Cadena palabraAIngresar, dicc ab){
// Inserta a la palabra en el arbol binario de busqueda.
	/*if (ab == NULL){
		ab = new(nodo_abb);
		ab->dato =x;
		ab->iz = NULL;
		ab->de = NULL;
	}else if (x < ab->dato)
		ab->iz = insertar(x, ab->iz);
	else
		ab->de = insertar(x, ab->de);
	return ab;*/
	return NO_IMPLEMENTADA;
}

// 13) Borra una palabra del diccionario.
TipoRetorno BorrarPalabraDiccionario(Cadena palabraABorrar)
{
	return NO_IMPLEMENTADA;
}

// 14) Muestra las palabras del diccionario alfabéticamente.
TipoRetorno ImprimirDiccionario()
{
	return NO_IMPLEMENTADA;
}

// 15) Muestra las palabras del texto que no se encuentran en el diccionario.
TipoRetorno ImprimirTextoIncorrecto()
{
	return NO_IMPLEMENTADA;
}

// 16) Imprime las últimas palabras ingresadas.
TipoRetorno ImprimirUltimasPalabras()
{
	return NO_IMPLEMENTADA;
}