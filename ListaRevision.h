#ifndef LISTAREVISION_H_INCLUDED
#define LISTAREVISION_H_INCLUDED


#include "Revision.h"


typedef struct nodoR { Revision info;
                       nodoR * sig;
                     } nodoL;

typedef nodoL * listaRevision;

///RECURSIVO:
///a) LargoRecu: Dada una lista, devuelve su largo (la cantidad de elementos de la lista).
int LargoRecu(listaRevision L);

///b) UltimoRecu: Dada una lista, devuelve su último elemento
///PRECONDICION: L no es vacia
int UltimoRecu(listaRevision L);

///c) ContarRecu: Dada una lista y un número entero, devuelve la cantidad de veces que dicho entero aparece en la lista.
int ContarRecu(listaRevision L, int valor);

///d) PerteneceRecu: Dada una lista y un número entero, devuelve TRUE si dicho entero pertenece a la lista y FALSE en caso contrario.
boolean PerteneceRecu(listaRevision L, int valor);

///e) SustituirRecu: Dada una lista y dos números enteros, sustituye cada ocurrencia del
///   primer entero en la lista por el segundo entero.
void SustituirRecu(listaRevision &L, int num1, int num2);

///f) MaximoRecu: Dada una lista, devuelve el mayor entero almacenado en ella.
int MaximoRecu(listaRevision L);

///h) InsBackRecu: Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackRecu(listaRevision &L, int valor);


#endif // LISTAREVISION_H_INCLUDED
