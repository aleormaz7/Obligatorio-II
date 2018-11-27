#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "Expediente.h"

typedef struct nodoE{ Expediente info;
                      nodoE * hizq;
                      nodoE * hder;
                    } nodoA;

typedef nodoA * ABBExpediente;


void CrearABB(ABBExpediente &a); ///Crear

boolean PerteneceExpPorCod(ABBExpediente a, long int cod); ///Saber si Expediente pertenece al ABB, por su codigo de expediente

void InsertABBExp(ABBExpediente &a, Expediente e); ///PRECONDICION: el Expediente no existe previamente en el ABB

Expediente minimoExpediente (ABBExpediente a) ; /// Precondición : el árbol a  NO está vacío

Expediente maximoExpediente (ABBExpediente a) ; /// Precondición : el árbol a  NO está vacío

void borrarMinimoExpedienete (ABBExpediente &a); /// Precondición : el árbol a  NO está vacío

void borrarABBExpedientePorCodigo (long int cod , ABBExpediente &a); /// Precondición : el Expediente está en el árbol

void ListarExpedientesOrdenados(ABBExpediente a);

int cntExpedientesEscribano(ABBExpediente a, String apellido);

void bajarExpedientes(ABBExpediente a);



#endif // ABBEXPEDIENTE_H_INCLUDED
