#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"
#include "Boolean.h"

typedef struct nodoT { Termino info;
                        nodoT * Sig;
                      } nodoTermino;

typedef nodoTermino * ListaTerminos;

Boolean listaTerminosEsVacia(ListaTerminos listaT);

void listaTerminosResto(ListaTerminos &listaT); /*borrar 1er valor*/
/*Precondición: lista no vacía*/

void listaTerminosCrear(ListaTerminos &listaT);

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente ordenado por grado*/

void listaTerminosMostrar(ListaTerminos t);

int evaluarPolinomio(ListaTerminos listaT, int valor);

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void levantarTerminos(file * f, ListaTerminos &listaTerminos);

void bajarTerminos(file * f, ListaTerminos ListaTerminos);

Boolean representaPolinomioNulo(ListaTerminos ListaTerminos);

ListaTerminos reducePolinomio(ListaTerminos listaTerminos);

#endif // LISTATERMINOS_H_INCLUDED
