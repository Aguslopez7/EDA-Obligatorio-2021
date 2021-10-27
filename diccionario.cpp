#include "diccionario.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

//Estructura del diccionario
struct nodo_abb
{
	char *pal;
	dicc iz;
	dicc de;
};

/*--------------------- Funciones --------------------*/

dicc CrearDiccionario(){
// Crea un arbol binario de busqueda vacio.
	return NULL;
}

//12) Agrega una palabra al diccionario.
TipoRetorno IngresarPalabraDiccionarioD(dicc &d, Cadena palabraAIngresar){
// Inserta a la palabra en el arbol binario de busqueda.
	int tam = strlen(palabraAIngresar);
	if (d == NULL){
		d = new(nodo_abb);
		d->pal = new char [tam];
		strcpy(d->pal, palabraAIngresar);
		cout << "\nPRIMERA PALABRA INGRESADA: " << d->pal << endl;
		d->iz = NULL;
		d->de = NULL;
	}else if (strcmp(palabraAIngresar, d->pal) == 0)
		return ERROR;
	else if (palabraAIngresar < d->pal)
		return IngresarPalabraDiccionarioD(d->iz, palabraAIngresar);
	else
		return IngresarPalabraDiccionarioD(d->de, palabraAIngresar);
	return OK;
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