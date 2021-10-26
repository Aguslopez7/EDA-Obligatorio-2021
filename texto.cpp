#include "texto.h"
#include "linea.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_texto
{
    linea primeral;
    linea ultimal;
};

/*--------------------- Funciones --------------------*/

//Crea la estructura del texto
texto CrearTexto(){
    texto t = new (nodo_texto);
    t->primeral = NULL;
    t->ultimal = NULL;
    cout << "\n\tt->primeral: " << t->primeral << endl;
    cout << "\tt->ultimal: " << t->ultimal << endl;
    cout << "\tt: " << t << endl;
    return t;
}

//1)Insertar linea al final
TipoRetorno InsertarLineaEnTexto(texto &t){
    return InsertarLineaEnLinea(t->primeral,t->ultimal);
}

//2)Insertar linea en la posicion indicada
TipoRetorno InsertarLineaEnPosicionEnT(texto &t, Posicion posicionLinea){
    return InsertarLineaEnPosicionEnLinea(t->primeral,t->ultimal,(posicionLinea));
}

//3)Borrar una linea en la poscion idicada
TipoRetorno BorrarPosLineaIndicadaEnT (texto &t, Posicion posicionLinea){
    return BorrarPosLineaIndicadaEnLinea(t->primeral,(posicionLinea));
}

//4) Borra todas las líneas del texto.
TipoRetorno BorrarTodoT(texto &t){
    return BorrarLineas(t->primeral,t->ultimal);
}

//5)Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTextoEnT (texto &t, Cadena palabraABorrar){
    return BorrarOcurrenciasPalabraEnTextoEnL(t->primeral,palabraABorrar);
}

//6)
TipoRetorno ImprimirTextoEnT(texto &t){
    return ImprimirTextoEnL(t->primeral);
}

//7)
TipoRetorno ComprimirTextoEnT(texto &t){
    return ComprimirTextoEnL(t->primeral,t->ultimal);
}

//8)
TipoRetorno InsertarPalabraEnT(texto &t,Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
    return InsertarPalabraEnL(t->primeral,(posicionLinea),(posicionPalabra), (palabraAIngresar));
}

//9)
TipoRetorno BorrarPalabraEnT(texto &t, Posicion posicionLinea, Posicion posicionPalabra){
    return BorrarPalabraEnL(t->primeral,(posicionLinea),(posicionPalabra));
}

//10)
TipoRetorno BorrarOcurrenciasPalabraEnLineaEnT(texto &t, Posicion posicionLinea, Cadena palabraABorrar){
    return BorrarOcurrenciasEnLinea(t->primeral,(posicionLinea),(palabraABorrar));
}

//11)
TipoRetorno ImprimirLineaEnT(texto &t, Posicion posicionLinea){
    return ImprimirLineaEnL(t->primeral,(posicionLinea));
}

/*TipoRetorno DestruirT(texto &t){
    return DestruirL(t->primeral,t->ultimal);
}*/