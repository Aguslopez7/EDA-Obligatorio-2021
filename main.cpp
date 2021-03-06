// Estructuras de Datos y Algoritmos - Obligatorio 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Programa Principal Obligatorio

#include "editor.h"
#include <string.h>
#include <stdio.h> 
#include <iostream>
#include <unistd.h>

// Colors Codes
#define COLOR_G "\033[32m"
#define COLOR_Y "\033[33m" 
#define COLOR_SB "\033[36m"
#define COLOR_BW "\033[1;37m"
#define COLOR_R "\033[0;31m"
#define COLOR_P "\033[0;35m"
#define COLOR_RESET "\033[0m"

using namespace std;

// Imprime todos los comandos disponibles.
void comandos(){
		cout << "\n\t╔═════════════════════════════════════════╗\n";
		cout << COLOR_SB << "\t║           ♦ EDITOR DE TEXTO ♦           ║" << COLOR_RESET << endl;
		cout << "\t╚═════════════════════════════════════════╝\n";
        cout << COLOR_G << "\n\tCOMANDOS DISPONIBLES\n" << COLOR_RESET << endl;;
		cout << "\t> InsertarLinea()\n";
		cout << "\t> InsertarLineaEnPosicion(Posicion posicionLinea)\n";
		cout << "\t> BorrarLinea(Posicion posicionLinea)\n";
		cout << "\t> BorrarTodo()\n";
		cout << "\t> BorrarOcurrenciasPalabraEnTexto(Cadena palabraABorrar)\n";
		cout << "\t> ImprimirTexto()\n";
		cout << "\t> ComprimirTexto()\n";
		cout << "\t> InsertarPalabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar)\n";
		cout << "\t> BorrarPalabra(Posicion posicionLinea, Posicion posicionPalabra)\n";
		cout << "\t> BorrarOcurrenciasPalabraEnLinea(Posicion posicionLinea, Cadena palabraABorrar)\n";
		cout << "\t> ImprimirLinea(Posicion posicionLinea)\n";
		cout << "\t> IngresarPalabraDiccionario(Cadena palabraAIngresar)\n";
		cout << "\t> BorrarPalabraDiccionario(Cadena palabraABorrar)\n";
		cout << "\t> ImprimirDiccionario()\n";
		cout << "\t> ImprimirTextoIncorrecto()\n";
		cout << "\t> ImprimirUltimasPalabras()\n";
		cout << "\t> comandos\n";
		cout << "\t> salir\n" << endl;
}

int main(){
	char * comando = new(char[MAX_COMANDO]);
	TipoRetorno retorno;
	bool ejecutado = false;
	char * pch, * pch1, * pch2;
	
	editor e = CrearEditor();

	bool salir = false;

	comandos();

	do{
		fflush(stdin);
		ejecutado = false;
		cout << "\tIngrese un comando\n";
		cout << "\t──────────────────\n\n";
		cout << COLOR_BW "\t> " << COLOR_RESET;

		fgets (comando, MAX_COMANDO, stdin); // leo la linea entera del comando. 
		pch = strtok (comando,"( ,)\n");

		if (strcasecmp (pch, "InsertarLinea") == 0){
				retorno = InsertarLinea(e);
				ejecutado = true;
		}else if (strcasecmp (pch, "InsertarLineaEnPosicion") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = InsertarLineaEnPosicion(e, atoi(pch));;
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarLinea") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = BorrarLinea(e, atoi(pch));
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarTodo") == 0){
			retorno = BorrarTodo(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "BorrarOcurrenciasPalabraEnTexto") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = BorrarOcurrenciasPalabraEnTexto(e, pch);
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "ImprimirTexto") == 0){
			retorno = ImprimirTexto(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "ComprimirTexto") == 0){
			retorno = ComprimirTexto(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "InsertarPalabra") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				pch1 = strtok (NULL, "(,)\n");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)\n");
					if (pch2 != NULL){
						retorno = InsertarPalabra(e, atoi(pch), atoi(pch1), pch2);
						ejecutado = true;
					}else
						cout << " - ERROR: Faltan Parametros.\n";
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarPalabra") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				pch1 = strtok (NULL, "(,)\n");
				if (pch1 != NULL){
					retorno = BorrarPalabra(e, atoi(pch), atoi(pch1));
					ejecutado = true;
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarOcurrenciasPalabraEnLinea") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				pch1 = strtok (NULL, "(,)\n");
				if (pch1 != NULL){
					retorno = BorrarOcurrenciasPalabraEnLinea(e, atoi(pch), pch1);
					ejecutado = true;
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "ImprimirLinea") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = ImprimirLinea(e, atoi(pch));
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "IngresarPalabraDiccionario") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = IngresarPalabraDiccionario(e, pch);
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarPalabraDiccionario") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = BorrarPalabraDiccionario(e, pch);
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "ImprimirDiccionario") == 0){
			retorno = ImprimirDiccionario(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "ImprimirTextoIncorrecto") == 0){
			retorno = ImprimirTextoIncorrecto(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "ImprimirUltimasPalabras") == 0){
			retorno = ImprimirUltimasPalabras(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "comandos") == 0){
			comandos();
		}else if (strcasecmp (pch, "salir") == 0){
			cout << COLOR_P <<"\n\t- Has salido del programa!\n\n" << COLOR_RESET;
			salir = true;			
		}else{
			cout << COLOR_R <<  "\n>Comando Incorrecto.\n\n" << COLOR_RESET;
			retorno = ERROR;
		}
		if (ejecutado){
				if (retorno == OK)
					cout << COLOR_G << "\n\t> OK\n\n" << COLOR_RESET;
				else if (retorno == ERROR)
					cout << COLOR_R << "\n\t> ERROR\n\n" << COLOR_RESET;
				else
					cout << COLOR_Y << "\n\t> NO IMPLEMENTADA\n\n" << COLOR_RESET;
		}

	}while (!salir);
	
	retorno = DestruirEditor(e);
	if (retorno == OK)
		cout << " - Memoria liberada con exito.\n\n";
	else if (retorno == ERROR)
		cout << " - Error al liberar memoria.\n\n";
	else
		cout << " - Operacion DestruirEditor NO IMPLEMENTADA\n\n";

	delete [] comando;
	sleep(1.5);
	system("clear");
}