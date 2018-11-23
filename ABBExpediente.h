#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED


#include "Expediente.h"

typedef struct nodoE{ Expediente info;
                      nodoE * hizq;
                      nodoE * hder;
                    } nodoA;

typedef nodoA * ABBExpediente;

///Crear
void CrearABB(ABBExpediente &a);

///Pertenece
///Saber si un elemento pertenece al ABB, versión iterativa
boolean Pertenece(ABBExpediente a, Expediente e);

///Insert
///PRECONDICION: el valor no existía previamente en el ABB
void Insert(ABBExpediente &a, Expediente e);



#endif // ABBEXPEDIENTE_H_INCLUDED
