#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED

#include "String.h"

typedef struct { long int codigoExpediente;
                 String caratula;
                 String nombreEscribano;
                 String apellidoEscribano;
                 int cantPaginas;
               } Expediente;

void cargarExpediente(Expediente &e,long int CodExpediente);

void mostrarExpediente(Expediente e);

long int darCodigoExpediente(Expediente e);

void darCaratula(Expediente e, String &s);

void darNombreEscribano(Expediente e, String &s);

void darApellidoEscribano(Expediente e, String &s);

int darCntPaginas(Expediente e);


#endif // EXPEDIENTE_H_INCLUDED
