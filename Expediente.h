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
///Muestra los datos del expediente

void mostrarExpedienteConsultaOrdenados(Expediente e);
///Muestra los datos del expediente en una sola linea

long int darCodigoExpediente(Expediente e);
///Retorna el codigo del expediente

void darCaratula(Expediente e, String &s);
///Retorna la caratula del expediente

void darNombreEscribano(Expediente e, String &s);
///Retorna el nombre del escribano del expediente

void darApellidoEscribano(Expediente e, String &s);
///Retorna el apellido del escribano del expediente

int darCntPaginas(Expediente e);
///Retorna la cantidad de paginas del expediente

void bajarExpedienteArchivo(Expediente e,FILE * f);
///Baja al archivo .dat los datos del expediente

void levantarExpedienteArchivo(Expediente &e,FILE * f);
///Levanta del archivo .dat los datos del expediente

#endif // EXPEDIENTE_H_INCLUDED
