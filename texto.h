#ifndef TEXTO_H
#define TEXTO_H

#include "definiciones.h"

typedef struct nodo_texto * texto;

// ----- Funciones -----

texto CrearTexto();

//Inserta la linea al final del texto
TipoRetorno InsertarLineaEnTexto(texto & t);

TipoRetorno ImprimirLineaT(texto &t, Posicion posicionLinea);

TipoRetorno InsertarLineaEnPosicionT(texto &t, Posicion posicionLinea);

#endif