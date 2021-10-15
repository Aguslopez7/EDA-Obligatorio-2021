#ifndef LINEA_H
#define LINEA_H

#include "definiciones.h"

typedef struct nodo_linea * linea;


linea CrearLinea();

//insertar linea al final
TipoRetorno InsertarLineaEnTextoUlt(linea &l);

#endif