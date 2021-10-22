#include "linea.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int cantl = 0;

struct nodo_linea
{
    int indice;
    int cantpl;
    linea sig;
    linea ant;
    Cadena *pal;
};

//1)Inserta una nueva línea vacía al final del texto.
TipoRetorno InsertarLineaEnLinea(linea &l, linea &lu)
{

    if (l == NULL && lu == NULL) // Cuando no tengo lineas
    {
        linea l = new (nodo_linea);
        l->pal = NULL;
        l->ant = NULL;
        l->sig = NULL;
        cantl += 1; // Cantidad de lineas igual a 1
        l->indice = cantl;
        lu = l;
        /*--------------- [DEBUG] ---------------*/
        cout << "\nl->pal: " << l->pal << endl;
        cout << "\nl->ant: " << l->ant << endl;
        cout << "\nl->sig: " << l->sig << endl;
        cout << "\nNODO L: " << l << endl;
        cout << "\nNODO LU: " << lu << endl;
        cout << "\nINDICE L: " << l->indice << endl;
        cout << "\nINDICE LU: " << lu->indice << endl;
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
        cout << "\nPRIMER NODO CREADO" << endl;
    }
    else
    { // Insertar resto de los nodos
        lu->sig = new (nodo_linea);
        lu->sig->ant = lu;
        lu = lu->sig;
        lu->sig = NULL;
        lu->pal = NULL;
        cantl++;
        lu->indice = cantl; // Cantidad de lineas >= 2
        /*chanchada
        l = lu;
        l = lu->ant;*/
        /*--------------- [DEBUG] ---------------*/
        cout << "\nlu->pal: " << lu->pal << endl;
        cout << "\nlu->ant: " << lu->ant << endl;
        cout << "\nlu->sig: " << lu->sig << endl;
        cout << "\nNODO L: " << l << endl;
        cout << "\nNODO LU: " << lu << endl;
        cout << "\nINDICE L: " << l->indice << endl;
        cout << "\nINDICE LU: " << lu->indice << endl;
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
        cout << "\nRESTO DE LOS NODOS CREADOS" << endl;
    }
    return OK;
}
//2)Inserta una nueva línea vacía en la posición indicada.
TipoRetorno InsertarLineaEnPosicionEnLinea(linea &l, linea &lu, Posicion posicionLinea)
{
    //varios nodos
    if ((posicionLinea > 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    {
        linea aux2 = new (nodo_linea);
        linea aux = l;
        linea aux3 = l;
        /*--------------- [DEBUG] ---------------*/
        cout << "\nINDICE DE L: " << l->indice << endl;
        cout << "\nINDICE DE AUX: " << aux->indice << endl;
        cout << "\nPOSICION LINEA: " << posicionLinea << endl;
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
        while (static_cast<unsigned int>(aux->indice) != posicionLinea)
            aux = aux->sig;
        aux3 = aux->ant;
        aux->ant = aux2;
        aux2->sig = aux;
        aux2->ant = aux3;
        aux3->sig = aux2;
        aux2->indice = posicionLinea;
        cantl++;
        while (aux2->sig != NULL)
        {
            aux2 = aux2->sig;
            posicionLinea++;
            aux2->indice = posicionLinea;
            cout << "\nindice: " << aux2->indice << endl;
        }
        cout << "\nNUEVA CANTIDAD DE LINEAS: " << cantl << endl;
        return OK;
    }
    //inertar en el primero
    else if (posicionLinea == 1 && posicionLinea <= static_cast<unsigned int>(cantl))
    {
        //un solo nodo
        if (cantl == 1)
        {
            /*--------------- [DEBUG] ---------------*/
            cout << "\nlu->pal: " << lu->pal << endl;
            cout << "\nlu->ant: " << lu->ant << endl;
            cout << "\nlu->sig: " << lu->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
            l->ant = new (nodo_linea);
            l->ant->sig = l;
            l = l->ant;
            l->ant = NULL;
            l->indice = posicionLinea;
            posicionLinea++;
            lu->indice = posicionLinea;
            cantl++;
            /*--------------- [DEBUG] ---------------*/
            cout << "\nlu->pal: " << lu->pal << endl;
            cout << "\nlu->ant: " << lu->ant << endl;
            cout << "\nlu->sig: " << lu->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
            cout << "\nSIGUIENTE NODO CREADO" << endl;
        }
        //varios nodos insertando en el primero
        else
        {
            l->ant = new (nodo_linea);
            l = l->ant;
            l->ant = NULL;
            l->sig = lu->ant;
            l->indice = posicionLinea;
            posicionLinea++;
            l->sig->indice = posicionLinea;
            posicionLinea++;
            lu->indice = posicionLinea;
            cantl++;
            /*--------------- [DEBUG] ---------------*/
            cout << "\nlu->pal: " << lu->pal << endl;
            cout << "\nlu->ant: " << lu->ant << endl;
            cout << "\nlu->sig: " << lu->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
            cout << "\nSIGUIENTE NODO CREADO" << endl;
        }
        return OK;
    }
    else
        return ERROR;
}
//3)Borrar una linea en la poscion idicada
TipoRetorno BorrarPosLineaIndicadaEnLinea(linea &l, Posicion posicionLinea)
{
    linea aux = l;

    if ((posicionLinea > 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    { //Si existen lineas en la posicion que nos pasan
        linea aux2 = l;
        linea aux3 = l;
        if (posicionLinea == static_cast<unsigned int>(cantl))
        {                                        //si estoy en el ultimo nodo
            while (static_cast<unsigned int>(aux->indice) != posicionLinea) //No llegue a la linea que tengo que borrar
                aux = aux->sig;
            if (aux->pal != NULL)
            {
                for (int i = 0; i <= (MAX_CANT_PALABRAS_X_LINEA - 1); i++)
                {
                    if (aux->pal[i] != NULL)
                    {
                        delete[] aux->pal[i]; //Borro la palabra
                        aux->pal[i] = NULL;   //Lo apunto a NULL
                    }
                }
                delete[] aux->pal;
                aux->pal = NULL;
                aux2 = aux->ant;
                aux2->sig = NULL;
                cantl--;
                delete aux;
                return OK;
            }
            else
            {
                aux2 = aux->ant;
                aux2->sig = NULL;
                cantl--;
                delete aux;
                return OK;
            }
        }
        else
        {
            while (static_cast<unsigned int>(aux->indice) != posicionLinea) //Si estoy en los nodos del medio y no llegue a la linea que tengo que borrar
                aux = aux->sig;
            if (aux->pal == NULL)
            { //Si no tengo ninguna palabra
                aux3 = aux->ant;
                aux3->sig = aux->sig;
                aux2 = aux->sig;
                aux2->ant = aux->ant;
                aux2->indice--;
                cantl--;
                while (aux2->sig != NULL)
                { //Desplazo las lineas que le siguen hacia arriba
                    aux2 = aux2->sig;
                    aux2->indice--;
                }
                delete aux;
                return OK;
            }
            else
            {
                for (int i = 0; i <= (MAX_CANT_PALABRAS_X_LINEA - 1); i++)
                {
                    if (aux->pal[i] != NULL)
                    {
                        delete[] aux->pal[i]; //Borro la palabra
                        aux->pal[i] = NULL;   //Lo apunto a NULL
                    }
                }
                delete[] aux->pal;
                aux->pal = NULL;
                aux2 = aux->ant;
                aux3 = aux->sig;
                aux2->sig = aux3;
                aux3->ant = aux2;
                aux3->indice--;
                delete aux;
                cantl--;
                while (aux3->sig != NULL)
                {
                    aux3 = aux3->sig;
                    aux3->indice--;
                }
                return OK;
            }
        }
    }
    else if ((posicionLinea == 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    {
        if (cantl == 1)
        { //hay un nodo solo
            if (l->pal == NULL)
            {
                delete aux;
                cantl--;
                return OK;
            }
            else
            {
                for (int i = 0; i <= (MAX_CANT_PALABRAS_X_LINEA - 1); i++)
                {
                    if (l->pal[i] != NULL)
                    {
                        delete[] l->pal[i]; //Borro la palabra
                        l->pal[i] = NULL;   //Lo apunto a NULL
                    }
                }
                delete[] l->pal;
                l->pal = NULL;
                delete l;
                return OK;
            }
        }
        else if (l->pal == NULL)
        { //hay mas nodos y no tengo palabras en l
            linea aux2 = l;
            aux2 = aux->sig;
            aux2->ant = NULL;
            aux2->indice--;
            cantl--;
            delete l;
            return OK;
        }
        else
        {
            linea aux2 = l;
            for (int i = 0; i <= (MAX_CANT_PALABRAS_X_LINEA - 1); i++)
            {
                if (l->pal[i] != NULL)
                {
                    delete[] l->pal[i]; //Borro la palabra
                    l->pal[i] = NULL;   //Lo apunto a NULL
                }
            }
            delete[] l->pal;
            l->pal = NULL;
            aux2 = aux->sig;
            aux2->ant = NULL;
            aux2->indice--;
            cantl--;
            delete l;
            return OK;
        }
    }
    else
        return ERROR;
}
//4) Borra todas las líneas del texto.
TipoRetorno BorrarLineas(linea &l, linea &lu)
{
    while (l != NULL)
    {
        linea aux = l;
        if (l->pal != NULL)
        {
            for (int i = 0; i < aux->cantpl; i++)
            {
                if (l->pal[i] != NULL)
                {
                    delete[] l->pal[i]; // Borro la palabra
                    l->pal[i] = NULL;   // Lo apunto a NULL
                }
            }
            delete[] aux->pal;
            aux->pal = NULL;
            l = l->sig;
            delete aux;
        }
        else
        {
            l = l->sig;
            delete aux;
        }
    }
    cantl = 0;
    l = NULL;
    lu = NULL;
    /*--------------- [DEBUG] ---------------*/
    cout << "\nNODO L: " << l << endl;
    cout << "\nNODO LU: " << lu << endl;
    cout << "\nINDICE L: " << l->indice << endl;
    cout << "\nINDICE LU: " << lu->indice << endl;
    cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
    cout << "\nLINEAS ELIMINADAS" << endl;
    return OK;
}
//5)Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTextoEnL(linea &l, Cadena palabraABorrar)
{
    linea aux = l;
    if (cantl == 1)
    {                         //Un nodo solo
        if (aux->pal == NULL) //No hay ninguna palabra
            return OK;
        else
        { //Hay almenos una palabra
            for (int i = 0; i < aux->cantpl; i++)
            {
                if (aux->pal[i] != NULL)
                {
                    if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                    {                         //Comparo la palabra a borrar con las que tengo
                        delete[] aux->pal[i]; //Borro la palabra
                        aux->pal[i] = NULL;   //Lo apunto a NULL
                        aux->cantpl--;
                    }
                }
            }
            for (int i = aux->cantpl; i > 0; i--)
            { //Comprimo la linea
                for (int n = MAX_CANT_PALABRAS_X_LINEA - 1; n > 0; n--)
                {
                    if (aux->pal[n] != NULL)
                    { //Si hay palabra
                        if (aux->pal[n - 1] == NULL)
                        {                                  //Y la ant esta vacia
                            aux->pal[n - 1] = aux->pal[n]; //Cambio
                            aux->pal[n] = NULL;
                        }
                    }
                }
            }
            return OK;
        }
    }
    else
    { //Hay mas nodos
        do
        {
            if (aux->pal == NULL) //No hay ninguna palabra
                return OK;
            else
            {
                for (int i = 0; i < aux->cantpl; i++)
                {
                    if (aux->pal[i] != NULL)
                    {
                        if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                        {                         //Comparo la palabra a borrar con las que tengo
                            delete[] aux->pal[i]; //Borro la palabra
                            aux->pal[i] = NULL;
                            aux->cantpl--; //Lo apunto a NULL
                        }
                    }
                }
                for (int i = aux->cantpl; i > 0; i--)
                { //Comprimo la linea
                    for (int n = MAX_CANT_PALABRAS_X_LINEA - 1; n > 0; n--)
                    {
                        if (aux->pal[n] != NULL)
                        { //Si hay palabra
                            if (aux->pal[n - 1] == NULL)
                            {                                  //Y la sig esta vacia
                                aux->pal[n - 1] = aux->pal[n]; //Cambio
                                aux->pal[n] = NULL;
                            }
                        }
                    }
                }
                aux = aux->sig;
            }
        }while (aux != NULL);
        return OK;
    }
}
//6)Imprime el texto por pantalla.
TipoRetorno ImprimirTextoEnL(linea &l)
{

    linea aux = l;

    if (cantl == 0)
    {
        cout << "Texto Vacio" << endl;
        return OK;
    }
    else
    {
        do
        {
            if (aux->pal != NULL)
            {
                cout << "\n\t" << aux->indice << ": ";
                for (int i = 0; i < aux->cantpl; i++)
                {
                    if (aux->pal[i] != NULL)
                    {
                        cout << aux->pal[i];
                    }
                }
            }
            else
                cout << "\n\t" << aux->indice << ": ";
            aux = aux->sig;
        } while (aux != NULL);
        return OK;
    }
}

//7) Comprime las palabras del texto.
//(8Inserta una palabra en una línea.
/*TipoRetorno InsertarPalabraEnL(linea &l, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar)
{

    linea aux = l;
    linea aux2 = l;
    int tam = strlen(palabraAIngresar);
    int tam2 = 10, aux1 = 0;
    posicionPalabra = posicionPalabra - 1;

    if (posicionLinea >= static_cast<unsigned int>(cantl))
    {
        while (static_cast<unsigned int>(aux->indice) != posicionLinea)
            aux = aux->sig;
        if ((posicionPalabra >= 1) && (posicionPalabra <= static_cast<unsigned int>(aux->cantpl) + 1)) //Si la posicion es valida y no se pasa de palabras en la linea
        {

            if (aux->cantpl == 0)
            {                                                //si hay 0 palabras en la linea
                aux->pal[posicionPalabra] = new (char[tam]); // nose si era necesario
                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                aux->cantpl++;
            }

            for (int i = 0; i < (MAX_CANT_PALABRAS_X_LINEA); i++)
            {
                if (aux->cantpl < MAX_CANT_PALABRAS_X_LINEA) //Si hay palabras y hay lugar en la linea
                {
                    if (i == posicionPalabra)
                    {
                        if (aux->pal[posicionPalabra] == NULL)
                        { //Si no hay una palabra en esa posicion
                            aux->pal[posicionPalabra] = new (char[tam]);
                            strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                            aux->cantpl++;
                            return OK;
                        }
                        else if (aux->pal[i + 1] == NULL) //Si ya hay una palabra en la posicion y no hay mas palabras desp
                        {
                            aux->pal[i + 1] = aux->pal[i];
                            aux->pal[i] = new (char[tam]);
                            strcpy(aux->pal[i], palabraAIngresar);
                            aux->cantpl++;
                            return OK;
                        }
                        else //Si hay una palabra y hay mas desp
                        {

                            while (aux->pal[i] != NULL)
                            {
                                int x = i;
                                x++;
                            }
                            if (posicionPalabra != 0)
                            {
                                for (int n = x; n > posicionPalabra; n--)
                                    aux->pal[n] = aux->pal[n - 1];
                                aux->pal[posicionPalabra] = new (char[tam]);
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                            }
                            else
                            {
                                for (int n = x; n >= posicionPalabra; n--)
                                    aux->pal[n] = aux->pal[n - 1];
                                aux->pal[posicionPalabra] = new (char[tam]);
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                            }
                            return OK;
                        }
                    }
                } //Si no hay lugar en la linea
                else
                {
                    aux2 = aux->sig; //Paso a la sig linea con aux3
                    do
                    {
                        if (aux2->cantpl < MAX_CANT_PALABRAS_X_LINEA) //Si ya existe la linea y hay lugar
                        {
                            while (aux2->pal[0] != NULL)
                            {
                                int x = i;
                                x++;
                            }
                            if (posicionPalabra != 0)
                            {
                                for (int n = x; n >= posicionPalabra; n--)
                                    aux->pal[n] = aux->pal[n - 1];
                                aux->pal[posicionPalabra] = new (char[tam]);
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                                aux1 = 1;
                            }
                            else
                            {
                                for (int n = x; n >= posicionPalabra; n--)
                                    aux->pal[n] = aux->pal[n - 1];
                                aux->pal[posicionPalabra] = new (char[tam]);
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                                aux1 = 1;
                            }
                        }
                        else if (aux->cantpl >= MAX_CANT_PALABRAS_X_LINEA) //Si hay palabras y no hay mas lugar en la linea
                        {
                            if (aux == NULL) //Si no existe otra linea
                            {
                                linea aux2 = new (nodo_linea);
                                aux->sig = aux2;
                                aux2->ant = aux;
                                aux2->indice = posicionLinea + 1;
                                cantl++;
                                aux2->pal = new (Cadena[MAX_CANT_PALABRAS_X_LINEA]);
                                aux->pal[MAX_CANT_PALABRAS_X_LINEA] = aux2->pal[0];

                                while (aux->pal[i] != NULL)
                                {
                                    int x = i;
                                    x++;
                                    i = x;
                                }

                                for (int n = x; n > posicionPalabra; n--)
                                    aux->pal[n] = aux->pal[n - 1];
                                aux->pal[posicionPalabra] = new (char[tam]);
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                                aux1 = 1;
                                return OK;
                            }
                            else //Si ya existe otra linea y esta llena paso a la sig y repito

                                aux = aux->sig;
                            aux1 = 0;
                        }

                    } while (aux1 != 1);
                }
            }

            return OK;
        }
        return ERROR;
    }
    return ERROR;
}
*/
//9)Borra la palabra en la posicion indicada
TipoRetorno BorrarPalabraEnL(linea &l, Posicion posicionLinea, Posicion posicionPalabra)
{
    linea aux = l;
    int i = 0;
    posicionPalabra = posicionPalabra - 1;
    if ((posicionLinea >= 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    { //Si la posicion de la linea existe
        if ((posicionPalabra >= 0) && (posicionPalabra <= static_cast<unsigned int>(aux->cantpl)))
        {                                        //Si la posicion de la palabra existe
            while (posicionLinea != static_cast<unsigned int>(aux->indice)) //Si mi posicion de la linea no es la que quiero
                aux = aux->sig;
            if (aux->pal != NULL)
            {                                //Tengo palabras
                while (posicionPalabra != static_cast<unsigned int>(i)) //Si no esoty en la palabra a borrar
                    i++;
                delete[] aux->pal[i]; //Borro la palbra que quiero
                while ((i + 1 <= (MAX_CANT_PALABRAS_X_LINEA) && (aux->pal[i + 1] != NULL)))
                { //Si en la sigueinte posicion hay una palabra y no me paso del maximo
                    aux->pal[i] = aux->pal[i + 1];
                    i++;
                }
                if (i == (MAX_CANT_PALABRAS_X_LINEA))
                { //Si llegue a final de linea y pongo NULL
                    aux->pal[i] = NULL;
                    return OK;
                }
                else
                {
                    aux->pal[i] = NULL; //si no llegue a final de linea y tengoq  poner NULL
                    return OK;
                }
            }
            else
                return OK;
        }
        else
            return ERROR;
    }
    else
        return ERROR;
}
//10)Borrar todas la ocurrencias de una palabra si existe en la linea
TipoRetorno BorrarOcurrenciasEnLinea(linea &l, Posicion posicionLinea, Cadena(palabraABorrar))
{
    linea aux = l;
    if ((posicionLinea >= 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    {
        while (posicionLinea != static_cast<unsigned int>(aux->indice)) //Si mi posicion de la linea no es la que quiero
            aux = aux->sig;
        if (aux->pal != NULL)
        {
            for (int i = 0; i < aux->cantpl; i++)
            {
                if (aux->pal[i] != NULL)
                {
                    if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                    {                         //Comparo la palabra a borrar con las que tengo
                        delete[] aux->pal[i]; //Borro la palabra
                        aux->pal[i] = NULL;   //Lo apunto a NULL
                        aux->cantpl--;
                    }
                }
            }
            int pasadas = aux->cantpl;
            while (pasadas != 0)
            {
                for (int tope = MAX_CANT_PALABRAS_X_LINEA - 1; tope > 0; tope--)
                {
                    if (aux->pal[tope] != NULL)
                    {
                        if (aux->pal[tope - 1] == NULL)
                        {
                            aux->pal[tope - 1] = aux->pal[tope];
                            aux->pal[tope] = NULL;
                        }
                    }
                }
                pasadas--;
            }
        }
        return OK;
    }
    else
        return ERROR;
}
//11)Imprime la línea por pantalla.
TipoRetorno ImprimirLineaEnL(linea &l, Posicion posicionLinea)
{

    linea aux = l;

    while (static_cast<unsigned int>(aux->indice) != posicionLinea)
        aux = aux->sig;

    cout << "\n\t" << posicionLinea << ": ";

    return OK;
}
