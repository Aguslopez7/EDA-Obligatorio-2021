#ifndef LINEA_H
#define LINEA_H

#include "definiciones.h"

typedef struct nodo_linea * linea;

/*--------------------- Funciones --------------------*/

linea CrearLinea();

TipoRetorno DestruirL(linea &l, linea &lu);

//1)Insertar linea al final
TipoRetorno InsertarLineaEnLinea(linea &l, linea &lu);

//2)Insertar linea en la posicion indicada
TipoRetorno InsertarLineaEnPosicionEnLinea(linea &l, linea &lu, Posicion posicionLinea);

//3)Borrar una linea en la poscion idicada
TipoRetorno BorrarPosLineaIndicadaEnLinea (linea &l, Posicion posicionLinea);

//4) Borra todas las líneas del texto.
TipoRetorno BorrarLineas(linea &l, linea &lu);

//5)Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTextoEnL (linea &l, Cadena palabraABorrar);

//6)Imprime el texto por pantalla.
TipoRetorno ImprimirTextoEnL(linea & l);

//7) Comprime las palabras del texto.
TipoRetorno ComprimirTextoEnL(linea &l);

//(8Inserta una palabra en una línea.
TipoRetorno InsertarPalabraEnL(linea & l, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);

//9)Borra la palabra en la posicion indicada
TipoRetorno BorrarPalabraEnL (linea &l, Posicion posicionLinea, Posicion posicionPalabra);

//10) Borra todas las ocurrencias de una palabra en la línea indicada.
TipoRetorno BorrarOcurrenciasEnLinea(linea & l, Posicion posicionLinea, Cadena palabraABorrar);

//11)Imprime la línea por pantalla.
TipoRetorno ImprimirLineaEnL(linea & l, Posicion posicionLinea);

#endif