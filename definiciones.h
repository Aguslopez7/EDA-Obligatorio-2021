#ifndef DEFINICIONES_H
#define DEFINICIONES_H

// Estructuras de Datos y Algoritmos - Obligatorio 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
// definiciones.h
// Modulo para definiciones generales del proyecto como constantes, etc.

// Tipos de Retorno
enum _retorno{
	OK, ERROR, NO_IMPLEMENTADA
};

// Tipos de Datos
typedef enum _retorno TipoRetorno;
typedef char* Cadena;
typedef unsigned int Posicion;

// Constantes
#define MAX_COMANDO 75
#define MAX_CANT_PALABRAS_X_LINEA 3
#define MAX_CANT_ULTIMAS_PALABRAS 3

// Colors Codes
#define COLOR_G "\033[32m"
#define COLOR_Y "\033[33m" 
#define COLOR_SB "\033[36m"
#define COLOR_BW "\033[1;37m"
#define COLOR_R "\033[0;31m"
#define COLOR_P "\033[0;35m"
#define COLOR_RESET "\033[0m"

#endif