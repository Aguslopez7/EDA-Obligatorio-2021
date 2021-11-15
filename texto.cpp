#include "texto.h"
#include "linea.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_texto
{
    linea primeral;
    linea ultimal;
    Cadena *ultpal;
};

/*--------------------- Funciones --------------------*/

// Crea la estructura del texto
texto CrearTexto()
{
    texto t = new (nodo_texto);
    t->primeral = CrearLinea();
    t->ultimal = t->primeral;
    t->ultpal = NULL;
    cout << "\n\tt->primeral: " << t->primeral << endl;
    cout << "\tt->ultimal: " << t->ultimal << endl;
    cout << "\tt: " << t << endl;
    return t;
}

// 1)Insertar linea al final
TipoRetorno InsertarLineaEnTexto(texto &t)
{
    return InsertarLineaEnLinea(t->primeral, t->ultimal);
}

// 2)Insertar linea en la posicion indicada
TipoRetorno InsertarLineaEnPosicionEnT(texto &t, Posicion posicionLinea)
{
    return InsertarLineaEnPosicionEnLinea(t->primeral, t->ultimal, (posicionLinea));
}

// 3)Borrar una linea en la poscion idicada
TipoRetorno BorrarPosLineaIndicadaEnT(texto &t, Posicion posicionLinea)
{
    return BorrarPosLineaIndicadaEnLinea(t->primeral, (posicionLinea));
}

// 4) Borra todas las líneas del texto.
TipoRetorno BorrarTodoT(texto &t)
{
    return BorrarLineas(t->primeral, t->ultimal);
}

// 5)Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTextoEnT(texto &t, Cadena palabraABorrar)
{
    return BorrarOcurrenciasPalabraEnTextoEnL(t->primeral, palabraABorrar);
}

// 6)
TipoRetorno ImprimirTextoEnT(texto &t)
{
    return ImprimirTextoEnL(t->primeral);
}

// 7)
TipoRetorno ComprimirTextoEnT(texto &t)
{
    return ComprimirTextoEnL(t->primeral, t->ultimal);
}

// 8)
TipoRetorno InsertarPalabraEnT(texto &t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar)
{
    return InsertarPalabraEnL(t->primeral, t,  (posicionLinea), (posicionPalabra), (palabraAIngresar));
}

// 9)
TipoRetorno BorrarPalabraEnT(texto &t, Posicion posicionLinea, Posicion posicionPalabra)
{
    return BorrarPalabraEnL(t->primeral, (posicionLinea), (posicionPalabra));
}

// 10)
TipoRetorno BorrarOcurrenciasPalabraEnLineaEnT(texto &t, Posicion posicionLinea, Cadena palabraABorrar)
{
    return BorrarOcurrenciasEnLinea(t->primeral, (posicionLinea), (palabraABorrar));
}

// 11)
TipoRetorno ImprimirLineaEnT(texto &t, Posicion posicionLinea)
{
    return ImprimirLineaEnL(t->primeral, (posicionLinea));
}

// 15) Muestra las palabras del texto que no se encuentran en el diccionario.
TipoRetorno ImprimirTextoIncorrectoT(texto &t, dicc &d)
{
    return ImprimirTextoIncorrectoL(t->primeral, d);
}

// 16) Imprime las últimas palabras ingresadas.
TipoRetorno ImprimirUltimasPalabrasT(texto &t)
{
    if (t->ultpal == NULL)
        cout<<"\n\tNo se ingresaron palabras"<< endl;
	else
       for (int i=0; i< MAX_CANT_ULTIMAS_PALABRAS; i++){
        cout<<"\n\t"<< t->ultpal[i];
    }
    return OK;
}

void ImprimirUltimasPalabrasAux (texto &t, Cadena palabraAIngresar)
{
    int tam = strlen(palabraAIngresar);
    if (t->ultpal == NULL)
    { //todavia no ingrese ninguna palabra
        t->ultpal = new (Cadena[MAX_CANT_ULTIMAS_PALABRAS]); //me creo el arreglo
        for (int i = 0; i < (MAX_CANT_ULTIMAS_PALABRAS - 1); i++)
        {
            t->ultpal[i] = NULL;
        }
        t->ultpal[0] = new char[tam];
        strcpy(t->ultpal[0], palabraAIngresar);
    }
    else
    {
        for (int tope = (MAX_CANT_ULTIMAS_PALABRAS - 1); tope > 0; tope--)
        {
            if (t->ultpal[tope] == NULL)
            {
                if (t->ultpal[tope - 1] != NULL)
                {
                    t->ultpal[tope] = t->ultpal[tope - 1];
                    t->ultpal[tope - 1] = NULL;
                }
            }
            else
            {
                delete[] t->ultpal[tope];
                t->ultpal[tope] = NULL;
                if (t->ultpal[tope - 1] != NULL)
                {
                    t->ultpal[tope] = t->ultpal[tope - 1];
                    t->ultpal[tope - 1] = NULL;
                }
            }
        }
        t->ultpal[0] = new char[tam];
        strcpy(t->ultpal[0], palabraAIngresar);
    }
}

void DestruirT(texto &t)
{
    DestruirL(t->primeral, t->ultimal);
    if(t->ultpal != NULL){
        for (int i = 0; i < MAX_CANT_ULTIMAS_PALABRAS ; i++)                //borro ultimas palabras
        {    
            delete[] t->ultpal[i]; //Borro la palabra
            t->ultpal[i] = NULL;   //Lo apunto a NULL             
        }
        t->ultpal = NULL;
    }
    delete t;
}