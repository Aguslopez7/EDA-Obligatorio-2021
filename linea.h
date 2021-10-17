#ifndef LINEA_H
#define LINEA_H

#include "definiciones.h"

typedef struct nodo_linea * linea;

linea CrearLinea();

//1)Insertar linea al final
TipoRetorno InsertarLineaEnTextoUlt(linea &l);

//2)Insertar linea en la posicion indicada
TipoRetorno InsertarLineaEnPosicion(linea &l, Posicion posicionLinea);

//11)Imprime la linea en la posicion indicada
TipoRetorno ImprimirLinea(linea &l, Posicion posicionLinea);

#endif