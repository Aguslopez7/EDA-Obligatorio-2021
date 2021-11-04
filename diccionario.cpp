#include "diccionario.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

// Estructura del diccionario
struct nodo_abb
{
	char *pal;
	dicc iz;
	dicc de;
};

/*--------------------- Funciones --------------------*/

dicc CrearDiccionario()
{
	// Crea un arbol binario de busqueda vacio.
	return NULL;
}

// 12) Agrega una palabra al diccionario.
TipoRetorno IngresarPalabraDiccionarioD(dicc &d, Cadena palabraAIngresar)
{
	// Inserta a la palabra en el arbol binario de busqueda.
	int tam = strlen(palabraAIngresar);
	if (d == NULL)
	{
		d = new (nodo_abb);
		d->pal = new char[tam + 1];
		strcpy(d->pal, palabraAIngresar);
		// cout << "\nPALABRA INGRESADA: " << d->pal << endl;
		d->iz = NULL;
		d->de = NULL;
	}
	else
	{
		/*-------------------- [DEBUG] --------------------
        cout << "\n--------------------------------------" << endl;
		cout << "\nd->pal" << d->pal << endl;
		cout << "\nPALABRA A INGRESAR: " << palabraAIngresar << endl;
		cout << "\nstrmcp: "<< strcmp(palabraAIngresar, d->pal) << endl;
		cout << "\nPRIMER NODO CREADO" << endl;
        cout << "\n--------------------------------------" << endl;*/
		if (strcasecmp(palabraAIngresar, d->pal) == 0)
			return ERROR;
		else if (strcasecmp(palabraAIngresar, d->pal) < 0)
		{
			// cout << "toy en la izq" << endl;
			return IngresarPalabraDiccionarioD(d->iz, palabraAIngresar);
		}
		else
		{
			// cout << "toy en la dere" << endl;
			return IngresarPalabraDiccionarioD(d->de, palabraAIngresar);
		}
	}
	return OK;
}

// 13) Borra una palabra del diccionario.
TipoRetorno BorrarPalabraDiccionarioD(dicc &d, Cadena palabraABorrar)
{
	if (d->pal != NULL)
	{
		/*-------------------- [DEBUG] --------------------
        cout << "\n--------------------------------------" << endl;
		cout << "\nd->pal" << d->pal << endl;
		cout << "\nPALABRA A BORRAR: " << palabraABorrar << endl;
		cout << "\nstrmcp: " << strcasecmp(palabraABorrar, d->pal) << endl;
		cout << "\n--------------------------------------" << endl;*/
		if (strcasecmp(palabraABorrar, d->pal) == 0)
		{
			d = BorrarPalabra(d, palabraABorrar);
		}
		else if (strcasecmp(palabraABorrar, d->pal) < 0)
		{
			BorrarPalabraDiccionarioD(d->iz, palabraABorrar);
		}
		else
		{
			BorrarPalabraDiccionarioD(d->de, palabraABorrar);
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

// 13) Funciones Auxiliares

dicc min_de(dicc & d)
{
    if (d->iz == NULL){
        dicc aux = d;
        d = d->de;
        return aux;

    }else
        return min_de(d->iz);
}

dicc max_iz(dicc & d)
{
    if (d->de == NULL){
        dicc aux = d;
        d = d->iz;
        return aux;
    }else
        return max_iz(d->de);
}

int profundidad(dicc d)
{
    if (d == NULL)
        return 0;
    else
        return 1 + max(profundidad(d->iz), profundidad(d->de));
}

dicc BorrarPalabra(dicc &d, Cadena pal)
{
	// Elimina x en el arbol binario de busqueda.
	dicc aux;
	if ((d->iz == NULL) && (d->de == NULL))
	{ // es hoja
		delete d;
		return NULL;
	}
	else if (d->iz == NULL)
	{
		aux = d->de;
		delete d;
		return aux;
	}
	else if (d->de == NULL)
	{
		aux = d->iz;
		delete d;
		return aux;
	}
	else
	{
		if (profundidad(d->iz) > profundidad(d->de))
			aux = max_iz(d->iz);
		else
			aux = min_de(d->de);
		aux->iz = d->iz;
		aux->de = d->de;
		delete d;
		return aux;
	}
}

// 14) Muestra las palabras del diccionario alfabeticamente.
TipoRetorno ImprimirDiccionarioD(dicc &d)
{
	if (d == NULL)
	{
		cout << "Diccionario vacio" << endl;
	}
	else
		ImprimirDiccionarioDAux(d);
	return OK;
}

// 14) Funcion Auxiliar
void ImprimirDiccionarioDAux(dicc d)
{
	if (d != NULL)
	{
		ImprimirDiccionarioDAux(d->iz);
		cout << "\n\t" << d->pal;
		ImprimirDiccionarioDAux(d->de);
	}
}

// 16) Imprime las últimas palabras ingresadas.
TipoRetorno ImprimirUltimasPalabras()
{
	return NO_IMPLEMENTADA;
}

bool PertenecePalabraDicc(dicc d, Cadena pal)
{
	if (d == NULL)
	{
		return false;
	}
	else if (strcasecmp(pal, d->pal) == 0)
		return true;
	else if (strcasecmp(pal, d->pal) > 0)
		PertenecePalabraDicc(d->de, pal);
	else
		PertenecePalabraDicc(d->iz, pal);
}