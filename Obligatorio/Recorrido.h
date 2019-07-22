#ifndef RECORRIDO_H_INCLUDED
#define RECORRIDO_H_INCLUDED


#include "Parada.h"

typedef struct nodoR {  Parada parada;
                        nodoR * sig;
                    } NodoRecorrido;

typedef struct {
    NodoRecorrido * prim;
    NodoRecorrido * ult;
} Recorrido;


void CrearRecorrido(Recorrido &r);

void InsBackRecorrido(Recorrido &r, Parada p);

boolean RecorridoVacio(Recorrido &r);

int LargoRecorrido(Recorrido r);//Devuelve la cantidad de elementos de la secuencia.

void MostrarRecorrido(Recorrido r);

//void CargarRecorrido(Recorrido &r);

void MostrarOrigen(Recorrido r);

void MostrarDestino(Recorrido r);

//Precondición: !EsVacia(r)
Parada Destino (Recorrido r);



#endif // RECORRIDO_H_INCLUDED
