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

void mostrarRevision(Revision r);

//boolean ExisteRevision(Revision r);

Fecha darFechaRev(Revision r);

void darDescripcion(Revision r, String &s);

Resultante darResultanteRevision(Revision r);

long int darCodigoExpedienteDeRevision(Revision r);



#endif // REVISION_H_INCLUDED
