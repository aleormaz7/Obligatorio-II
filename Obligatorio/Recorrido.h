#ifndef RECORRIDO_H_INCLUDED
#define RECORRIDO_H_INCLUDED


#include "Parada.h"

typedef struct nodoL {  Parada parada;
                        nodoL * sig;
                    } Nodo;

typedef struct {
    Nodo * prim;
    Nodo * ult;
} Recorrido;


void Crear(Recorrido &r);

void InsFront(Recorrido &r, Parada p);

boolean EsVacia(Recorrido &r);

int Largo(Recorrido r);//Devuelve la cantidad de elementos de la secuencia.



#endif // RECORRIDO_H_INCLUDED
