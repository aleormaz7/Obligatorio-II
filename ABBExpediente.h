#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "Expediente.h"

typedef struct nodoE{ Expediente info;
                      nodoE * hizq;
                      nodoE * hder;
                    } nodoA;

typedef nodoA * ABBExpediente;


void CrearABB(ABBExpediente &a); ///Crear

boolean PerteneceExp(ABBExpediente a, Expediente e);///Saber si Expediente pertenece al ABB

boolean PerteneceExpPorCod(ABBExpediente a, long int cod); ///Saber si Expediente pertenece al ABB, por su codigo de expediente

void InsertABBExp(ABBExpediente &a, Expediente e); ///PRECONDICION: el Expediente no existe previamente en el ABB

Expediente minimoExpediente (ABBExpediente a) ; /// Precondici�n : el �rbol a  NO est� vac�o

void borrarMinimoExpedienete (ABBExpediente &a); /// Precondici�n : el �rbol a  NO est� vac�o

void borrarABBExpediente (Expediente e , ABBExpediente &a); /// Precondici�n : el Expediente est� en el �rbol

void borrarABBExpedientePorCodigo (long int cod , ABBExpediente &a); /// Precondici�n : el Expediente est� en el �rbol

void ListarExpedientesOrdenados(ABBExpediente a);



#endif // ABBEXPEDIENTE_H_INCLUDED
