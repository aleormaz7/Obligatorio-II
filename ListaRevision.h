#ifndef LISTAREVISION_H_INCLUDED
#define LISTAREVISION_H_INCLUDED


#include "Revision.h"


typedef struct nodoR { Revision info;
                       nodoR * sig;
                     } nodoL;

typedef nodoL * listaRevision;


void Crear(listaRevision &L);

///RECURSIVO:
Revision Primero(listaRevision L);

void InsFront(listaRevision &L, Revision r);

boolean EsVacia(listaRevision L);

/// LargoRecu: Dada una lista, devuelve su largo (la cantidad de elementos de la lista).
//int LargoRecu(listaRevision L);

/// UltimoRecu: Dada una lista, devuelve su último elemento
///PRECONDICION: L no es vacia
Revision UltimoRecu(listaRevision L);

/// ContarRecu: Dada una lista y un número entero, devuelve la cantidad de veces que dicho entero aparece en la lista.
//int ContarRecu(listaRevision L, int valor);

///d) PerteneceRecu: Dada una lista y un número entero, devuelve TRUE si dicho entero pertenece a la lista y FALSE en caso contrario.
boolean PerteneceRecu(listaRevision L, Revision r);

/// SustituirRecu: Dada una lista y dos números enteros, sustituye cada ocurrencia del
///   primer entero en la lista por el segundo entero.
//void SustituirRecu(listaRevision &L, int num1, int num2);

/// MaximoRecu: Dada una lista, devuelve el mayor entero almacenado en ella.
//int MaximoRecu(listaRevision L);

/// InsBackRecu: Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackRecu(listaRevision &L, int valor);


///Mustra todas las revisiones de la lista de revisiones en una linea
void ListarRevisiones(listaRevision L);

///Dado el código de un expediente, listar todas las revisiones correspondientes a dicho
void ListarRevisionesPorCodigoExpediente(listaRevision L, long int cod);


#endif // LISTAREVISION_H_INCLUDED
