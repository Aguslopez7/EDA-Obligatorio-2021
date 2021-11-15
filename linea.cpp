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

/*--------------------- Funciones --------------------*/

linea CrearLinea(){
    return NULL;
}

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
        /*-------------------- [DEBUG] --------------------
        cout << "\n--------------------------------------" << endl;
        cout << "\nl->pal: " << l->pal << endl;
        cout << "\nl->ant: " << l->ant << endl;
        cout << "\nl->sig: " << l->sig << endl;
        cout << "\nNODO L: " << l << endl;
        cout << "\nNODO LU: " << lu << endl;
        cout << "\nINDICE L: " << l->indice << endl;
        cout << "\nINDICE LU: " << lu->indice << endl;
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
        cout << "\nPRIMER NODO CREADO" << endl;
        cout << "\n--------------------------------------" << endl;*/
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
        l = lu;
        while (l->ant != NULL)
        {
            l=l->ant;
        }
        /*-------------------- [DEBUG] --------------------
        cout << "\n--------------------------------------" << endl;
        cout << "\nlu->pal: " << lu->pal << endl;
        cout << "\nlu->ant: " << lu->ant << endl;
        cout << "\nlu->sig: " << lu->sig << endl;
        cout << "\nNODO L: " << l << endl;
        cout << "\nNODO LU: " << lu << endl;
        cout << "\nINDICE L: " << l->indice << endl;
        cout << "\nINDICE LU: " << lu->indice << endl;
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
        cout << "\nSIGUIENTE NODO CREADO" << endl;
        cout << "\n--------------------------------------" << endl;*/
    }
    return OK;
}

//2)Inserta una nueva línea vacía en la posición indicada.
TipoRetorno InsertarLineaEnPosicionEnLinea(linea &l, linea &lu, Posicion posicionLinea)
{
    //varios nodos
    if ((posicionLinea > 1) && (posicionLinea <= static_cast<unsigned int>(cantl+1)))
    {
        linea aux2 = new (nodo_linea);
        linea aux = l;
        linea aux3 = l;
        /*-------------------- [DEBUG] --------------------
        cout << "\nINDICE DE L: " << l->indice << endl;
        cout << "\nINDICE DE AUX: " << aux->indice << endl;
        cout << "\nPOSICION LINEA: " << posicionLinea << endl;
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;*/
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
        }
        //cout << "\nNUEVA CANTIDAD DE LINEAS: " << cantl << endl;
        return OK;
    }
    //inertar en el primero
    else if (posicionLinea == 1 && posicionLinea <= static_cast<unsigned int>(cantl+1))
    {
        //un solo nodo
        if (cantl == 1)
        {
            /*-------------------- [DEBUG] --------------------
            cout << "\nlu->pal: " << lu->pal << endl;
            cout << "\nlu->ant: " << lu->ant << endl;
            cout << "\nlu->sig: " << lu->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;*/
            l->ant = new (nodo_linea);
            l->ant->sig = l;
            l = l->ant;
            l->ant = NULL;
            l->indice = posicionLinea;
            posicionLinea++;
            lu->indice = posicionLinea;
            cantl++;
            /*-------------------- [DEBUG] --------------------
            cout << "\n--------------------------------------" << endl;
            cout << "\nlu->pal: " << lu->pal << endl;
            cout << "\nlu->ant: " << lu->ant << endl;
            cout << "\nlu->sig: " << lu->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
            cout << "\nSIGUIENTE NODO CREADO" << endl;
            cout << "\n--------------------------------------" << endl;*/
        }
        else if(cantl==0){
            l=new(nodo_linea);
            l->sig=NULL;
            l->ant=NULL;
            l->pal=NULL;
            l->indice=posicionLinea;
            lu=l;
            cantl++;
            /*-------------------- [DEBUG] --------------------
            cout << "\n--------------------------------------" << endl;
            cout << "\nl->pal: " << l->pal << endl;
            cout << "\nl->ant: " << l->ant << endl;
            cout << "\nl->sig: " << l->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
            cout << "\nPRIMER NODO CREADO" << endl;
            cout << "\n--------------------------------------" << endl;*/
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
            /*-------------------- [DEBUG] --------------------
            cout << "\n--------------------------------------" << endl;
            cout << "\nlu->pal: " << lu->pal << endl;
            cout << "\nlu->ant: " << lu->ant << endl;
            cout << "\nlu->sig: " << lu->sig << endl;
            cout << "\nNODO L: " << l << endl;
            cout << "\nNODO LU: " << lu << endl;
            cout << "\nINDICE L: " << l->indice << endl;
            cout << "\nINDICE LU: " << lu->indice << endl;
            cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
            cout << "\nSIGUIENTE NODO CREADO" << endl;
            cout << "\n--------------------------------------" << endl;*/

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
    int restapl=1;
    if ((posicionLinea > 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    { //Si existen lineas en la posicion que nos pasan
        linea aux2 = l;
        linea aux3 = l;
        if (posicionLinea == static_cast<unsigned int>(cantl))
        {//si estoy en el ultimo nodo
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
                aux2->indice-=restapl;
                
                while (aux2->sig != NULL)
                { //Desplazo las lineas que le siguen hacia arriba
                    aux2 = aux2->sig;
                    aux2->indice-=restapl;
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
                aux3->indice-=restapl;
                delete aux;
                cantl--;
                while (aux3->sig != NULL)
                {
                    aux3 = aux3->sig;
                    aux3->indice-=restapl;
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
                l=NULL;
                return OK;
            }
        }
        else if (l->pal == NULL)
        { //hay mas nodos y no tengo palabras en l
            
            linea aux2 = l;
            aux2 = aux->sig;
            aux2->ant = NULL;
            aux2->indice-=restapl;
            cantl--;
            l=aux2;
            delete aux;
            aux=l;
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
            aux2->indice-=restapl;
            cantl--;
            l=aux2;
            delete aux;
            aux=l;
            return OK;
        }
    }
    else
        return ERROR;
}

// 4) Borra todas las lineas
TipoRetorno BorrarLineas(linea &l, linea &lu){
    while (l != NULL){
        linea aux = l;
        if (l->pal != NULL){
            for (int i = 0; i < aux->cantpl; i++){
                if (l->pal[i] != NULL){
                    delete[] l->pal[i]; // Borro la palabra
                    l->pal[i] = NULL;   // Lo apunto a NULL
                }
            }
            delete[] aux->pal;
            aux->pal = NULL;
            l = l->sig; 
            delete aux;           
        }else{
            l = l->sig; 
            delete aux;
        }       
    }
    cantl = 0;
    l = NULL;
    lu = NULL;
    /*-------------------- [DEBUG] --------------------
    cout << "\n--------------------------------------" << endl;
    cout << "\nNODO L: " << l << endl;
    cout << "\nNODO LU: " << lu << endl;
    cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
    cout << "\nLINEAS ELIMINADAS" << endl;
    cout << "\n--------------------------------------" << endl;*/
    return OK;
}

//5)Borra todas las ocurrencias de una palabra en el texto.
TipoRetorno BorrarOcurrenciasPalabraEnTextoEnL(linea &l, Cadena palabraABorrar)
{
    linea aux = l;
    int restapl=1;
    int n = aux->cantpl;
    if (cantl == 1)
    {//Un nodo solo
        if (aux->pal != NULL) 
        { //Hay almenos una palabra           
            for (int i = 0; i < n; i++)
            {
                if (aux->pal[i] != NULL)
                {
                    if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                    {//Comparo la palabra a borrar con las que tengo
                        /*-------------------- [DEBUG] --------------------
                        cout << "\n--------------------------------------" << endl;
                        cout << "\nPALABRA BORRADA: " << aux->pal[i] << endl;
                        cout << "\n--------------------------------------" << endl;*/
                        delete[] aux->pal[i]; //Borro la palabra
                        aux->pal[i] = NULL;   //Lo apunto a NULL
                        aux->cantpl-=restapl;
                        //cout << "\nCANTIDAD DE PALABRAS PL: " << aux->cantpl << endl;
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
        } 
        return OK;
    }
    else
    { //Hay mas nodos
        do
        {
            if (aux->pal != NULL) 
            {
                for (int i = 0; i < n; i++)
                {
                    if (aux->pal[i] != NULL)
                    {
                        if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                        {//Comparo la palabra a borrar con las que tengo
                            /*-------------------- [DEBUG] --------------------
                            cout << "\n--------------------------------------" << endl;
                            cout << "\nPALABRA BORRADA MAS NODOS: " << aux->pal[i] << endl;
                            cout << "\n--------------------------------------" << endl;*/
                            delete[] aux->pal[i]; //Borro la palabra
                            aux->pal[i] = NULL;     //Lo apunto a NULL
                            aux->cantpl-=restapl; 
                            //cout << "\nCANTIDAD DE PALABRAS PL: " << aux->cantpl << endl;
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
                if(aux->sig != NULL)
                    aux = aux->sig; 
                                                 
            }

        }while (aux->sig != NULL);
        if(aux->sig==NULL){
            if (aux->pal != NULL) 
            {
                for (int i = 0; i < n; i++)
                {
                    if (aux->pal[i] != NULL)
                    {
                        if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                        {//Comparo la palabra a borrar con las que tengo
                            /*-------------------- [DEBUG] --------------------
                            cout << "\n--------------------------------------" << endl;
                            cout << "\nPALABRA BORRADA MAS NODOS: " << aux->pal[i] << endl;
                            cout << "\n--------------------------------------" << endl;*/
                            delete[] aux->pal[i]; //Borro la palabra
                            aux->pal[i] = NULL;     //Lo apunto a NULL
                            aux->cantpl-=restapl; 
                            //cout << "\nCANTIDAD DE PALABRAS PL: " << aux->cantpl << endl;
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
           }
               
        }
    }
    return OK;       
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
                        if(i==aux->cantpl - 1){
                        cout << aux->pal[i];  
                        }else
                        cout << aux->pal[i] << ", ";
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
TipoRetorno ComprimirTextoEnL(linea &l, linea &lu)
{
    linea aux = l; 
    linea aux2 = l;
    int resta = 1;
    if (cantl >= 2)
    {
        do
        {
            if (aux->pal != NULL)
            {
                while (aux->pal[MAX_CANT_PALABRAS_X_LINEA - 1] != NULL) //Si esta llena la linea sigo hasta que haya una con lugar
                    aux = aux->sig;                                     //Paso a la siguiente
                if (aux->sig->cantpl > 0)
                { //Si la sig tiene palabras
                    aux->pal[MAX_CANT_PALABRAS_X_LINEA - 1] = aux->sig->pal[0];
                    aux->sig->pal[0] = NULL;
                    aux->sig->cantpl--;
                    aux->cantpl++;
                }
                if (aux->cantpl < (MAX_CANT_PALABRAS_X_LINEA)){ // si el del medio del arreglo es vacio
                    for (int tope = (MAX_CANT_PALABRAS_X_LINEA - 1); tope > 0; tope--)
                    { //Comprimo las lineas
                        if (aux->pal[tope] != NULL)
                        {
                            if (aux->pal[tope - 1] == NULL)
                            {
                                aux->pal[tope - 1] = aux->pal[tope];
                                aux->pal[tope] = NULL;
                            }
                        }
                    }
                }
                if (aux->sig->cantpl > 0)
                { //Si tiene palabras
                    for (int tope = (MAX_CANT_PALABRAS_X_LINEA - 1); tope > 0; tope--)
                    { //Comprimo las lineas
                        if (aux->sig->pal[tope] != NULL)
                        {
                            if (aux->sig->pal[tope - 1] == NULL)
                            {
                                aux->sig->pal[tope - 1] = aux->sig->pal[tope];
                                aux->sig->pal[tope] = NULL;
                            }
                        }
                    }
                    aux = l; //vuelvo al primer nodo
                }
                else
                {
                    if (aux->sig != NULL)
                        aux = aux->sig;
                }
            }
            else
            {
                if (cantl > 2)
                {      
                    if (aux->indice == 1)
                    {
                        aux = aux->sig;
                        delete[] aux->ant;
                        aux->ant = NULL;
                        l = aux;
                        cantl--;
                        while (aux->sig != NULL)
                        {
                            aux = aux->sig;
                            aux->indice -= resta;
                        }
                    }
                    else
                    {
                        aux = aux->ant;
                        aux2 = aux2->sig->sig;
                        delete[] aux->sig;
                        cantl--;
                        aux->sig = aux2;
                        aux2->ant = aux;
                        while (aux->sig != NULL)
                        {
                            aux = aux->sig;
                            aux->indice -= resta;
                        }
                    }
                }
                else{
                    return OK;
                }
            }
        } while (aux->sig != NULL);
        if(cantl>2){
            aux=l;
            for (int i = 0; i < cantl; i++)
            { //Recorro todas las lineas
                if (aux->cantpl == 0)
                { // Si no tengo palabras borro el arreglo y la linea
                    delete[] aux->pal;
                    aux = aux->ant;
                    aux2 = aux->sig->sig;
                    delete aux->sig;
                    cantl--;
                    aux->sig = aux2;
                    aux2->ant = aux;
                    while (aux->sig != NULL)
                    {
                        aux = aux->sig;
                        aux->indice -= resta;
                    }
                }
                else{
                    aux = aux->sig;
                }
            }
        }else if (cantl==2){
            aux=l;
            for (int i = 0; i < cantl; i++)
            { //Recorro todas las lineas
                if (aux->cantpl == 0)
                { // Si no tengo palabras borro el arreglo y la linea
                    delete[] aux->pal;
                    aux = aux->ant;
                    delete aux->sig;
                    cantl--;
                    aux->sig = NULL;
                }
                else
                    aux = aux->sig;
            }
        }
        return OK;
    }
    return OK;
}

//8)Inserta una palabra en una li­nea.
TipoRetorno InsertarPalabraEnL(linea &l, texto &t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar)
{
    linea aux = l;
    int tam = strlen(palabraAIngresar);
    bool x = true;

    if (posicionLinea <= static_cast<unsigned int>(cantl)) //Verifico la posicionlinea
    {
        while (static_cast<unsigned int>(aux->indice) != posicionLinea) //voy a la linea donde quiero insertar
            aux = aux->sig;
        if ((posicionPalabra >= 1) && (posicionPalabra <= static_cast<unsigned int>(aux->cantpl) + 1)) //Si la posicion es valida y no se pasa de palabras en la linea
        {
            posicionPalabra--;
            do
            {
                if (aux->pal == NULL) //Si no tengo el arreglo
                {
                    aux->pal = new (Cadena[MAX_CANT_PALABRAS_X_LINEA]); //me creo el arreglo que contiene las palabras
                    for (int i = 0; i < (MAX_CANT_PALABRAS_X_LINEA - 1); i++)
                    { //recorro el arreglo y lo apunto a null
                        aux->pal[i] = NULL;
                    }
                    if (static_cast<unsigned int>(aux->indice) == posicionLinea)
                    { //si estoy en la linea que quiero inserto
                        aux->pal[posicionPalabra] = new char[tam];
                        strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                        aux->cantpl++;
                        /*-------------------- [DEBUG] --------------------
                        cout << "\n--------------------------------------" << endl;
                        cout << "\nNUEVA CADENA CREADA [] = " << MAX_CANT_PALABRAS_X_LINEA <<endl;
                        cout << "\nPOSICION LINEA INGRESADA: " << posicionLinea << endl;
                        cout << "\nPOSICION PALABRA INGRESADA: " << "[" << posicionPalabra << "]" << endl;
                        cout << "\nPALABRA A INGRESAR: " << palabraAIngresar << endl;
                        cout << "\nPALABRA INGRSADA: " << aux->pal[posicionPalabra] << endl;
                        cout << "\nCANTIDAD DE PALABRAS: " << aux->cantpl << endl;
                        cout << "\n--------------------------------------" << endl;*/
                        x = false;
                    }
                }
                else
                { //si tengo el arreglo de papabras
                    if (aux->cantpl < MAX_CANT_PALABRAS_X_LINEA)
                    { //si tengo lugar en la linea

                        if (static_cast<unsigned int>(aux->indice) == posicionLinea)
                        { //si estoy en la linea

                            if (aux->pal[posicionPalabra] != NULL)
                            { //si en la posicion que yo quiero ingresar ya hay una palabra
                                for (int tope = (MAX_CANT_PALABRAS_X_LINEA - 1); static_cast<unsigned int>(tope) > posicionPalabra; tope--)
                                {
                                    if (aux->pal[tope] == NULL)
                                    {
                                        if (aux->pal[tope - 1] != NULL)
                                        {
                                            aux->pal[tope] = aux->pal[tope - 1];
                                            aux->pal[tope - 1] = NULL;
                                        }
                                    }
                                }
                                aux->pal[posicionPalabra] = new char[tam];
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                                /*-------------------- [DEBUG] --------------------
                                cout << "\n--------------------------------------" << endl;
                                cout << "\nPOSICION LINEA INGRESADA: " << posicionLinea << endl;
                                cout << "\nPOSICION PALABRA INGRESADA: " << "[" << posicionPalabra << "]" << endl;
                                cout << "\nPALABRA A INGRESAR: " << palabraAIngresar << endl;
                                cout << "\nPALABRA INGRSADA: " << aux->pal[posicionPalabra] << endl;
                                cout << "\nCANTIDAD DE PALABRAS: " << aux->cantpl << endl;
                                cout << "\n--------------------------------------" << endl;*/
                                ImprimirUltimasPalabrasAux(t, palabraAIngresar);
                                return OK;
                            }
                            else
                            { //si no tengo ninguna palabra en la posicion que yo quiero ingresar
                                aux->pal[posicionPalabra] = new char[tam];
                                strcpy(aux->pal[posicionPalabra], palabraAIngresar);
                                aux->cantpl++;
                                /*-------------------- [DEBUG] --------------------
                                cout << "\n--------------------------------------" << endl;
                                cout << "\nPOSICION LINEA INGRESADA: " << posicionLinea << endl;
                                cout << "\nPOSICION PALABRA INGRESADA: " << "[" << posicionPalabra << "]" << endl;
                                cout << "\nPALABRA A INGRESAR: " << palabraAIngresar << endl;
                                cout << "\nPALABRA INGRSADA: " << aux->pal[posicionPalabra] << endl;
                                cout << "\nCANTIDAD DE PALABRAS: " << aux->cantpl << endl;
                                cout << "\n--------------------------------------" << endl;*/
                                ImprimirUltimasPalabrasAux(t, palabraAIngresar);
                                return OK;
                            }
                        }
                        else
                        { //si no estoy en la linea que quiero ingresar
                            if (aux->cantpl != 0)
                            {
                                for (int tope = (MAX_CANT_PALABRAS_X_LINEA - 1); tope > 0; tope--)
                                {
                                    if (aux->pal[tope] == NULL)
                                    {
                                        if (aux->pal[tope - 1] != NULL)
                                        {
                                            aux->pal[tope] = aux->pal[tope - 1];
                                            aux-> pal[tope-1] = NULL;
                                        }
                                    }
                                }
                            }
                            aux->pal[0] = aux->ant->pal[MAX_CANT_PALABRAS_X_LINEA - 1];
                            aux->ant->pal[MAX_CANT_PALABRAS_X_LINEA - 1] = NULL;
                            aux->ant->cantpl--;
                            aux->cantpl++;

                            aux = l;                                                        //vuelvo al primer nodo
                            while (static_cast<unsigned int>(aux->indice) != posicionLinea) //voy a la linea donde quiero insertar
                                aux = aux->sig;
                        }
                    }
                    else //Si no tengo lugar en la linea
                    {

                        if (aux->sig == NULL) //Si el siguiente no existe lo creo
                        {
                            aux->sig = new (nodo_linea);
                            aux->sig->ant = aux;
                            aux = aux->sig;
                            aux->sig = NULL;
                            aux->pal = new (Cadena[MAX_CANT_PALABRAS_X_LINEA]); //me creo el arreglo que contiene las palabras
                            for (int i = 0; i < (MAX_CANT_PALABRAS_X_LINEA - 1); i++)
                            {
                                aux->pal[i] = NULL;
                            }
                            cantl++;
                            aux->indice = cantl;
                            aux->cantpl = 0;
                        }
                        else
                        {
                            aux = aux->sig;
                        }
                    }
                }
            } while (x);
            ImprimirUltimasPalabrasAux(t, palabraAIngresar);
            return OK;
        }
        return ERROR;
    }
    return ERROR;
}

//9)Borra la palabra en la posicion indicada
TipoRetorno BorrarPalabraEnL(linea &l, Posicion posicionLinea, Posicion posicionPalabra)
{
    linea aux = l;
    int restapl = 1;
    if ((posicionLinea >= 1) && (posicionLinea <= static_cast<unsigned int>(cantl))){ //Si la posicion de la linea existe
        if ((posicionPalabra >= 1) && (posicionPalabra <= MAX_CANT_PALABRAS_X_LINEA)){                                   //Si la posicion de la palabra existe
            posicionPalabra--;
            while (posicionLinea != static_cast<unsigned int>(aux->indice)) //Si mi posicion de la linea no es la que quiero
                aux = aux->sig;

            for (int i = 0; i <= aux->cantpl; i++)
            {
                if (static_cast<unsigned int>(i) == posicionPalabra)
                {
                    delete[] aux->pal[i]; //Borro la palabra
                    aux->pal[i] = NULL;   //Lo apunto a NULL
                    aux->cantpl-=restapl;
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
        else
            return ERROR;   
    }
    else
        return ERROR;  
}

//10)Borrar todas la ocurrencias de una palabra si existe en la linea
TipoRetorno BorrarOcurrenciasEnLinea(linea &l, Posicion posicionLinea, Cadena palabraABorrar)
{
    linea aux = l;
    int restapl=1;
    if ((posicionLinea >= 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    {
        while (posicionLinea != static_cast<unsigned int>(aux->indice)) //Si mi posicion de la linea no es la que quiero
            aux = aux->sig;
        if (aux->pal != NULL)
        {
            int n = aux->cantpl;
            for (int i = 0; i < n; i++)
            {
                if (aux->pal[i] != NULL)
                {
                    /*-------------------- [DEBUG] --------------------
                    cout << "\nPALABRA EN STRING: " << aux->pal[i] << endl;
                    cout << "\nPALABRA : " << palabraABorrar << endl;
                    cout << "\nstrcmp : " << strcmp(aux->pal[i],palabraABorrar ) << endl;*/
                    if (strcmp(palabraABorrar, aux->pal[i]) == 0)
                        {                         //Comparo la palabra a borrar con las que tengo
                            /*-------------------- [DEBUG] --------------------
                            cout << "\n--------------------------------------" << endl;
                            cout << "\nPALABRA BORRADA: " << aux->pal[i] << endl;
                            cout << "\n--------------------------------------" << endl;*/
                            delete[] aux->pal[i]; //Borro la palabra
                            aux->pal[i] = NULL;   //Lo apunto a NULL
                            aux->cantpl-=restapl;
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
            return OK;
        }
        return OK;
    }
    else
        return ERROR;
}

// 11)Imprime la línea por pantalla.
TipoRetorno ImprimirLineaEnL(linea &l, Posicion posicionLinea)
{
    linea aux = l;
    if(posicionLinea <= (static_cast<unsigned int>(cantl))){
        while (static_cast<unsigned int>(aux->indice) != posicionLinea)
            aux = aux->sig;
        if (aux->pal != NULL)
        {
            cout << "\n\t" << aux->indice << ": ";
            for (int i = 0; i < aux->cantpl; i++)
            {
                if (aux->pal[i] != NULL)
                {
                    if(i==aux->cantpl - 1){
                       cout << aux->pal[i];  
                    }else
                    cout << aux->pal[i] << ", ";
                }
            }
        }
        else
            cout << "\n\t" << aux->indice << ": ";
        /*-------------------- [DEBUG] --------------------
        cout << "\n\n--------------------------------------" << endl;
        cout << "\nCANTIDAD DE PALABRAS: " << aux->cantpl << endl;
        cout << "\n--------------------------------------" << endl;*/
        return OK;
    }
    else
        return ERROR;
}

//15) Muestra las palabras del texto que no se encuentran en el diccionario.
TipoRetorno ImprimirTextoIncorrectoL(linea &l, dicc &d)
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
                        if(!PertenecePalabraDicc(d, aux->pal[i])){
                            if(i == aux->cantpl - 1)
                                cout << aux->pal[i];  
                            else
                                cout << aux->pal[i] << ", ";
                        }
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

void DestruirL(linea &l, linea &lu){
    while (l != NULL){
        linea aux = l;
        if (l->pal != NULL){
            for (int i = 0; i < aux->cantpl; i++){
                if (l->pal[i] != NULL){
                    delete[] l->pal[i]; // Borro la palabra
                    l->pal[i] = NULL;   // Lo apunto a NULL
                }
            }
            delete[] aux->pal;
            aux->pal = NULL;
            l = l->sig; 
            delete aux;           
        }else{
            l = l->sig; 
            delete aux;
        }       
    }
    cantl = 0;
    l = NULL;
    lu = NULL;
}