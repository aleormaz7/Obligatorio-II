#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED

#include "Fecha.h"
#include "String.h"
#include "Resultante.h"

typedef struct { Fecha fechaRealizado;
                 String descripcion;
                 long int codigoExpediente;
                 Resultante resultadoRev;
               } Revision;


void cargarRevision(Revision &r, long int codigo, Fecha f);
///Carga la informacion de la revision

void mostrarRevision(Revision r);
///Muestra la informacion de la revision

Fecha darFechaRev(Revision r);
///Retorna la fecha de la revision

void darDescripcion(Revision r, String &s);
///Retorna la descripcion de la revision

Resultante darResultanteRevision(Revision r);
///Retorna el resultante de la revision

long int darCodigoExpedienteDeRevision(Revision r);
///Retorna el codigo del expediente de la revision

#endif // REVISION_H_INCLUDED
