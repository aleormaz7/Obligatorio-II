#ifndef LISTAREVISION_H_INCLUDED
#define LISTAREVISION_H_INCLUDED

#include "Revision.h"


typedef struct nodoR { Revision info;
                       nodoR * sig;
                     } nodoL;

typedef nodoL * listaRevision;

void Crear(listaRevision &L);
///Crea la lista

boolean listaRevisionesEsVacia(listaRevision l);
///Retorna si la lista de revisiones esta vacia o no.

Revision Primero(listaRevision L);
///Retorna la primer revision de la lista

void InsFront(listaRevision &L, Revision r);
///inserta una revision al inicio de la lista

void InsBackRecu(listaRevision &L, Revision r);
///inserta una revision al final de la lista

///Elimina las revisiones de un expediente
void EliminarRevisionesPorExpediente(listaRevision &L, long int codigoExp);

///Muestra todas las revisiones de la lista en una linea
void ListarRevisiones(listaRevision L);

///Dado el código de un expediente, listar todas las revisiones correspondientes al mismo
void ListarRevisionesPorCodigoExpediente(listaRevision L, long int cod);
///Precondicion: Cod sea de un expediente que exista en el ABB de expedietes

int cantRevisonesEntreFechas(listaRevision L, Fecha f1, Fecha f2);///Lista las revisiones entre el rago de fechas(incluidas)
///Precondicion: f1 y f2 validas y f1 < f2

void cantRevisionesCadaTipo(listaRevision L, int &cantTipo1, int &cantTipo2, int &cantTipo3);
///Retorna la cantidad de revisiones de cada tipo.

int cntRevisionesCodigoExp(listaRevision l, long int codRev);
///Retorna la cantidad de revisiones de un codigo de expediente


void bajarRevisiones(listaRevision lr, String nomArch);

void levantarRevisiones(listaRevision &lr, String nomArch);


#endif // LISTAREVISION_H_INCLUDED
