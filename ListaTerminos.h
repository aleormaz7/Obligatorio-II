#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"
#include "Boolean.h"

typedef struct nodoT { Termino info;
nodoT * Sig;
 } nodoTermino;

typedef nodoTermino * ListaTerminos;

Boolean Vacia(ListaTerminos listaT);

void resto(ListaTerminos &listaT); /*borrar 1er valor*/

/*Precondición: lista no vacía*/
void Crear(ListaTerminos &listaT);

void insertar(ListaTerminos &listaT, Termino t);

/*inserta recursivamente ordenado por grado*/
void mostrarListaTerminos(ListaTerminos t);

int Evaluar(ListaTerminos listaT, int valor);

void SumaPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void MultiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void LevantarTerminos(file * f, ListaTerminos &listaTerminos);

void BajarTerminos(file * f, ListaTerminos ListaTerminos);

Boolean representaPolinomioNulo(ListaTerminos ListaTerminos);

ListaTerminos Reduce(ListaTerminos listaTerminos);

#endif // LISTATERMINOS_H_INCLUDED
