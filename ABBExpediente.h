#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "Expediente.h"

typedef struct nodoE{ Expediente info;
                      nodoE * hizq;
                      nodoE * hder;
                    } nodoA;

typedef nodoA * ABBExpediente;

void CrearABB(ABBExpediente &a); ///Crea el ABB de expedientes

boolean AbbExpientesEsVacio(ABBExpediente a);
///retirna si el ABB de expedientes es vacio o no

boolean PerteneceExpPorCod(ABBExpediente a, long int cod); ///Retirna si Expediente pertenece al ABB, por su codigo de expediente

void InsertABBExp(ABBExpediente &a, Expediente e);///Inserta un expedientes en el ABB
///PRECONDICION: el Expediente no existe previamente en el ABB

Expediente minimoExpediente (ABBExpediente a); ///Retorna el expediente con el minimo codigo de codigo
/// Precondición : el árbol a  NO está vacío

Expediente maximoExpediente (ABBExpediente a) ; ///Retirna el expediente con el maximo codigo de expediente
/// Precondición : el árbol a  NO está vacío

void borrarMinimoExpedienete (ABBExpediente &a); ///Borra del ABB el expediente con el minimo codigo.
/// Precondición : el árbol a  NO está vacío

void borrarABBExpedientePorCodigo (long int cod , ABBExpediente &a); ///Borra el expediente con el codigo ingresado del ABB
/// Precondición : el Expediente está en el árbol

void ListarExpedientesOrdenados(ABBExpediente a);///Lista los expedientes del ABB ordenados por si codigo de expediente.

int cntExpedientesEscribano(ABBExpediente a, String apellido);///Retorna la cantidad de expedientes, coincidentes con el apellido ingresado

void bajarExpedientes(ABBExpediente a,String nomArch); ///Baja los expedientes del ABB al archivo .dat indicado

void bajarExpedientesRec(ABBExpediente a,FILE * f); /// Baja el expediente al archivo

void levantarExpedientes(ABBExpediente &a,String nomArch); ///Levanta los expedientes desde el archivo .dat indicado

long int codExpMasRevisiones(ABBExpediente a);///Retorna el codigo del expediente con mas cantidad de revisiones.
///funcion que interactua con la lista de revisiones.
///Precondicion: ABB de expedientes y lista de reviciones No vacios

#endif // ABBEXPEDIENTE_H_INCLUDED
