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

///Elimina las revisiones de un expediente
void EliminarRevisionesPorExpediente(listaRevision &L, long int codigoExp);

///Muestra todas las revisiones de la lista en una linea
void ListarRevisiones(listaRevision L);

///Dado el código de un expediente, listar todas las revisiones correspondientes al mismo
void ListarRevisionesPorCodigoExpediente(listaRevision L, long int cod);


int cantRevisonesEntreFechas(listaRevision L, Fecha f1, Fecha f2);///Lista las revisiones entre el rago de fechas(incluidas)
///Precondicion: f1 y f2 validas u f1 < f2

void cantRevisionesCadaTipo(listaRevision L, int &cantTipo1, int &cantTipo2, int &cantTipo3);
///Retorna la cantidad de revisiones de cada tipo.

#endif // LISTAREVISION_H_INCLUDED
