#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"
#include "Boolean.h"

typedef struct nodoT { Termino info;
                        nodoT * Sig;
                      } nodoTermino;

typedef nodoTermino * ListaTerminos;

boolean listaTerminosEsVacia(ListaTerminos listaT);

void listaTerminosResto(ListaTerminos &listaT); /*borrar 1er valor*/
/*Precondición: lista no vacía*/

void listaTerminosCrear(ListaTerminos &listaT);

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente ordenado por grado*/

void listaTerminosMostrar(ListaTerminos listaT);

long int evaluarPolinomio(ListaTerminos listaT, int valor);

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

//void levantarTerminos(file * f, ListaTerminos &listaT);

//void bajarTerminos(file * f, ListaTerminos listaT);

boolean representaPolinomioNulo(ListaTerminos listaT);
/*Precondicion: listaT no es vacia */

void reduceListaTerminos(ListaTerminos listaT, ListaTerminos &listaResultante);
/*Precondicion: listaT no es vacia && listaT no representa un ponilomio nulo*/

int mayorGradoListaTerminos(ListaTerminos listaT);
/*Precondicion: listaT no es vacia */

ListaTerminos listaTerminosCopiar(ListaTerminos listaT);

void destuirListaTerminos(ListaTerminos listaT);
/*Precondicion: listaT no es vacia*/

void controlTerminoIndependienteNoNulo(ListaTerminos &listaT);
/*Precondicion: listaT no es vacia*/

#endif // LISTATERMINOS_H_INCLUDED
