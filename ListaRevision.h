#ifndef LISTAREVISION_H_INCLUDED
#define LISTAREVISION_H_INCLUDED

#include "Revision.h"


typedef struct nodoR { Revision info;
                       nodoR * sig;
                     } nodoL;

typedef nodoL * listaRevision;



void Crear(listaRevision &L);

Revision Primero(listaRevision L);

void InsFront(listaRevision &L, Revision r);

boolean EsVacia(listaRevision L);

/// UltimoRecu: Dada una lista, devuelve su último elemento
///PRECONDICION: L no es vacia
Revision UltimoRecu(listaRevision L);

///PerteneceRecu: Dada una lista y un número entero, devuelve TRUE si dicho entero pertenece a la lista y FALSE en caso contrario.
boolean PerteneceRecu(listaRevision L, Revision r);

/// InsBackRecu: Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackRecu(listaRevision &L, int valor);

///Mustra todas las revisiones de la lista de revisiones en una linea
void ListarRevisiones(listaRevision L);

///Dado el código de un expediente, listar todas las revisiones correspondientes a dicho
void ListarRevisionesPorCodigoExpediente(listaRevision L, long int cod);

void EliminarRevisionesPorExpediente(listaRevision &L, long int codigoExp);

//long int codigoExpedienteMayorCantRevisiones(listaRevision L);

int cantRevisonesEntreFechas(listaRevision L, Fecha f1, Fecha f2);

void cantRevisionesCadaTipo(listaRevision L, int &cantTipo1, int &cantTipo2, int &cantTipo3);


#endif // LISTAREVISION_H_INCLUDED
