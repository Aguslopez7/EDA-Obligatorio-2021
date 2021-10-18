#include "linea.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int cantl=0;

struct nodo_linea
{ 
   int indice;
   linea sig;
   linea ant;
   Cadena * pal;
};

//Crea la estructura del linea
linea CrearLinea(){
    linea l = new (nodo_linea);
    l->pal = new(Cadena[MAX_CANT_PALABRAS_X_LINEA]);
    l->ant = NULL;
    l->sig = NULL;
    l->indice=1;
    //l->pal=CrearPalabra();
    cantl+=1;                           //Cantidad de lineas igual a 1
    return l;
}

//insertar linea al final
TipoRetorno InsertarLineaEnTextoUlt(linea &l){
    
    linea aux2= new(nodo_linea);
    linea aux=l;

    if(l->sig == NULL && l->ant == NULL){                       //Insertar 2do nodo 
        aux->sig = aux2;
        aux2->sig = NULL;
        aux2->ant = l;
        aux2->indice = cantl+1;               //Cantidad de lineas igual a 2       
        cout << "\nINDICE DE L: "<< l->indice <<endl;
        cout << "\nINDICE DE AUX2: " << aux2->indice <<endl;   
        cantl++;  
        cout << "\nCANTIDAD DE LINEAS: "<< cantl <<endl; 
    }
    else{                             //Insertar resto de los nodos 
        while(aux->sig!=NULL)
            aux = aux->sig;
        aux->sig = aux2;
        aux2->sig = NULL;
        aux2->ant = aux;
        aux2->indice = cantl+1;
        cout << "\nINDICE DE AUX2: " << aux2->indice << endl;
        cantl++;                                                 //Cantidad de lineas >=3
        cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
    }
    return OK;
}

TipoRetorno InsertarLineaEnPosicion(linea &l, Posicion posicionLinea)
{
    linea aux2 = new (nodo_linea);
    linea aux = l;

    cout << "\nINDICE DE L: " << l->indice << endl;
    cout << "\nINDICE DE AUX: " << aux->indice << endl;
    cout << "\nPOSICION LINEA: " << posicionLinea << endl;
    cout << "\nCANTIDAD DE LINEAS: " << cantl << endl;
    
    //varios nodos
    if ((posicionLinea > 1) && (posicionLinea <= static_cast<unsigned int>(cantl)))
    //if (posicionLinea > 1 && posicionLinea <= cantl) 
    {
        linea aux3 = l;
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
            cout << "\npos linea: " << cantl << endl;  
        }
        cout << "\nNUEVA CANTIDAD DE LINEAS: " << cantl << endl;  
        return OK;
    }
    //inertar en el primero
    else if (posicionLinea == 1 && posicionLinea <= static_cast<unsigned int>(cantl))
    {
        //un solo nodo
        if (cantl==1)
        {
            aux2->ant = NULL;
            aux->ant = aux2;
            aux2->sig = aux;
            l = aux2;
            cout << "\nINDICE L: " << l->indice << endl; 
            aux->indice = posicionLinea++;
            cantl++;
        }
        //varios nodos inertando en el primero
        else
        {
            aux->ant = aux2;
            aux2->sig = aux;
            aux2->ant = NULL;
            l = aux2;
            aux->indice = posicionLinea++;
            cout << "\nINDICE L: " << aux->indice << endl; 
            cantl++;
        }
    }
    else
        return ERROR;
}

TipoRetorno ImprimirLinea(linea &l, Posicion posicionLinea){

    linea aux=l;
    
    while(static_cast<unsigned int>(aux->indice) != posicionLinea)
        aux=aux->sig;

    cout<<"\n\t" << posicionLinea << ": ";
    cout<<"\n\tINDICE: " << aux->indice << endl;
    
    return OK;
}