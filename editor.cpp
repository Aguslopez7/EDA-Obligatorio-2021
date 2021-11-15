// Estructuras de Datos y Algoritmos - Obligatorio 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
// editor.c
// Modulo de implementacion de editor.

#include <string.h>
#include <iostream>
#include "editor.h"
#include "texto.h"
#include "diccionario.h"

using namespace std;

struct nodo_editor
{
	texto t;
	dicc d;
};

/*--------------------- Funciones --------------------*/

// Crea la estructura editor.
editor CrearEditor()
{
	cout << "\n\tESTRUCTURA DEL EDITOR\n";
	cout << "\t─────────────────────\n";
	editor e = new (nodo_editor);
	e->t = CrearTexto();
	e->d = CrearDiccionario();
	cout << "\te->t: " << e->t << endl;
	cout << "\te->d: " << e->d << endl;
	return e;
}

// 1) Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
TipoRetorno InsertarLinea(editor &e)
{
	return InsertarLineaEnTexto(e->t);
}

// 2) Inserta una nueva línea vacía en la posición indicada.
TipoRetorno InsertarLineaEnPosicion(editor &e, Posicion posicionLinea)
{
	return InsertarLineaEnPosicionEnT(e->t, (posicionLinea));
}

// 3) Borra la línea en la posición indicada.
TipoRetorno BorrarLinea(editor &e, Posicion posicionLinea)
{
	return BorrarPosLineaIndicadaEnT(e->t, (posicionLinea));
}

// 4) Borra todas las líneas del texto.
TipoRetorno BorrarTodo(editor &e)
{
	return BorrarTodoT(e->t);
}

// 5) Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor &e, Cadena palabraABorrar)
{
	return BorrarOcurrenciasPalabraEnTextoEnT(e->t, palabraABorrar);
}

// 6) Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(editor &e)
{
	return ImprimirTextoEnT(e->t);
}

// 7) Comprime las palabras del texto.
// Para implementar esta operación no debe generarse un nuevo documento.
TipoRetorno ComprimirTexto(editor &e)
{
	return ComprimirTextoEnT(e->t);
}

// 8) Inserta una palabra en una línea.
TipoRetorno InsertarPalabra(editor &e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar)
{
	return InsertarPalabraEnT(e->t, (posicionLinea), (posicionPalabra), (palabraAIngresar));
}

// 9) Borra la palabra en la posición indicada.
TipoRetorno BorrarPalabra(editor &e, Posicion posicionLinea, Posicion posicionPalabra)
{
	return BorrarPalabraEnT(e->t, (posicionLinea), (posicionPalabra));
}

// 10) Borra todas las ocurrencias de una palabra en la línea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor &e, Posicion posicionLinea, Cadena palabraABorrar)
{
	return BorrarOcurrenciasPalabraEnLineaEnT(e->t, (posicionLinea), (palabraABorrar));
}

// 11) Imprime la línea por pantalla.
TipoRetorno ImprimirLinea(editor &e, Posicion posicionLinea)
{
	return ImprimirLineaEnT(e->t, (posicionLinea));
}

// 12) Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
TipoRetorno IngresarPalabraDiccionario(editor &e, Cadena palabraAIngresar)
{
	return IngresarPalabraDiccionarioD(e->d, (palabraAIngresar));
}

// 13) Borra una palabra del diccionario.
TipoRetorno BorrarPalabraDiccionario(editor &e, Cadena palabraABorrar)
{
	return BorrarPalabraDiccionarioD(e->d, (palabraABorrar));
}

// 14) Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
TipoRetorno ImprimirDiccionario(editor &e)
{
	return ImprimirDiccionarioD(e->d);
}

// 15) Muestra las palabras del texto que no se encuentran en el diccionario.
TipoRetorno ImprimirTextoIncorrecto(editor &e)
{
	return ImprimirTextoIncorrectoT(e->t, e->d);
}

// 16) Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
TipoRetorno ImprimirUltimasPalabras(editor &e)
{
	return ImprimirUltimasPalabrasT(e->t);

}

// Destruye la estructura editor y libera la memoria asociada.
TipoRetorno DestruirEditor(editor &e)
{
	DestruirT(e->t);
	DestruirD(e->d);
	delete e;
	return OK;
}