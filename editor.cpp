// Estructuras de Datos y Algoritmos - Obligatorio 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.c
// Modulo de implementacion de editor.

#include <string.h>
#include <iostream>
#include "editor.h"
#include "texto.h"
#include "diccionario.h"

using namespace std;

struct nodo_editor{
    texto t;
    //diccionario d;
};

editor CrearEditor(){
// Crea la estructura editor.
    cout << "\n\tESTRUCTURA DEL EDITOR\n";
    cout << "\t─────────────────────\n";
    editor e = new(nodo_editor);
    e->t = CrearTexto();
    //e->d = CrearDicccionario;
    cout << "\te->t: " << e->t << endl;
    //cout << "e->d: " << e->d << endl;
    return e;
}

//1)
TipoRetorno InsertarLinea(editor & e){
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.
	return InsertarLineaEnTexto(e->t);
}
//2)
TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea){
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return InsertarLineaEnPosicionEnT(e->t,(posicionLinea));
}
//3)
TipoRetorno BorrarLinea(editor & e, Posicion posicionLinea){
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return BorrarPosLineaIndicadaEnT(e->t,(posicionLinea));
}
//4)
TipoRetorno BorrarTodo(editor & e){
// Borra todas las líneas del texto.
// Ver más detalles en la letra del obligatorio.
	return BorrarTodoT(e->t);
}
//5)
TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en el texto.
// Ver más detalles en la letra del obligatorio.
	return BorrarOcurrenciasPalabraEnTextoEnT(e->t,palabraABorrar);
}
//6)
TipoRetorno ImprimirTexto(editor & e){
// Imprime el texto por pantalla.
// Ver más detalles en la letra del obligatorio.
	return ImprimirTextoEnT(e->t);
}
//7)
TipoRetorno ComprimirTexto(editor & e){
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}
//8)
TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;//InsertarPalabraEnT(e->t,(posicionLinea), (posicionPalabra), (palabraAIngresar));
}
//9)
TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	return  BorrarPalabraEnT(e->t,(posicionLinea), (posicionPalabra));
}
//10)
TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.
	return BorrarOcurrenciasPalabraEnLineaEnT(e->t,(posicionLinea), (palabraABorrar));
}
//11)
TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea){
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.
	return ImprimirLineaEnT(e->t,(posicionLinea));
}

TipoRetorno IngresarPalabraDiccionario(editor & e, Cadena palabraAIngresar){
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar){
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirDiccionario(editor & e){
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirTextoIncorrecto(editor & e){
// Muestra las palabras del texto que no se encuentran en el diccionario.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}
//hola

TipoRetorno ImprimirUltimasPalabras(editor & e){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno DestruirEditor(editor & e){
// Destruye la estructura editor y libera la memoria asociada.
	return NO_IMPLEMENTADA;
}

