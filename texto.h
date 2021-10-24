#ifndef TEXTO_H
#define TEXTO_H

#include "definiciones.h"

typedef struct nodo_texto * texto;

/*--------------------- Funciones --------------------*/

texto CrearTexto();

//1)Insertar linea al final
TipoRetorno InsertarLineaEnTexto(texto &t);

//2)Insertar linea en la posicion indicada
TipoRetorno InsertarLineaEnPosicionEnT(texto &t, Posicion posicionLinea);

//3)Borrar una linea en la poscion idicada
TipoRetorno BorrarPosLineaIndicadaEnT (texto &t, Posicion posicionLinea);

//4) Borra todas las líneas del texto.
TipoRetorno BorrarTodoT(texto &t);

//5)Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTextoEnT (texto &t, Cadena palabraABorrar);   

//6)Imprime el texto por pantalla.
TipoRetorno ImprimirTextoEnT(texto &t);

//7) Comprime las palabras del texto.

//(8Inserta una palabra en una línea.
TipoRetorno InsertarPalabraEnT(texto &t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);

//9)Borra la palabra en la posicion indicada
TipoRetorno BorrarPalabraEnT (texto &t, Posicion posicionLinea, Posicion posicionPalabra);

//10) Borra todas las ocurrencias de una palabra en la línea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLineaEnT(texto &t, Posicion posicionLinea, Cadena palabraABorrar);

//11)Imprime la línea por pantalla.
TipoRetorno ImprimirLineaEnT(texto &t, Posicion posicionLinea);

//TipoRetorno DestruirT(texto &t);

#endif