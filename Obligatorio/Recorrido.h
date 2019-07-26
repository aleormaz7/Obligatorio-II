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


/// Crea la lista de Recorrido vacia
void CrearRecorrido(Recorrido &r);

/// Inserta una parada al final de la lista
void InsBackRecorrido(Recorrido &r, Parada p);

/// Retorna TRUE si el recorrido(lista) es vacio
boolean RecorridoVacio(Recorrido &r);

/// Retorna un entero con la la cantidad de elementos(paradas) del recorrido
int LargoRecorrido(Recorrido r);

/// Muestra las paradas del recorrido
void MostrarRecorrido(Recorrido r);

/// Muestra la primer para del recorrido
void MostrarOrigen(Recorrido r);
/* Precondicion: el recorrido no es vacio -> !RecorridoVacio(r) */

/// Muestra la ultima parada del recorrido
void MostrarDestino(Recorrido r);
/* Precondicion: el recorrido no es vacio -> !RecorridoVacio(r) */

/// Retorna la ultima parada del recorrido
Parada Destino (Recorrido r);
/* Precondicion: el recorrido no es vacio -> !RecorridoVacio(r) */

#endif // RECORRIDO_H_INCLUDED
