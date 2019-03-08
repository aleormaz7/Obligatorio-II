#ifndef _LISTATERMINOS
#define _LISTATERMINOS

#include "Termino.h"
#include "Boolean.h"

typedef struct nodoT { Termino info;
                        nodoT * Sig;
                      } nodoTermino;

typedef nodoTermino * ListaTerminos;

boolean listaTerminosEsVacia(ListaTerminos listaT);

void listaTerminosCrear(ListaTerminos &listaT);

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente ordenado por grado*/

void listaTerminosMostrar(ListaTerminos listaT);

long int evaluarPolinomio(ListaTerminos listaT, int valor);
/*Precondicion: ListaTerminos no es vacia y grado mayor o*/

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

boolean representaPolinomioNulo(ListaTerminos listaT);
/*Precondicion: listaT no es vacia */

void reduceListaTerminos(ListaTerminos listaT, ListaTerminos &listaResultante);
/*Precondicion: listaT no es vacia && listaT no representa un ponilomio nulo*/

void listaTerminosCopiar(ListaTerminos listaTOri,ListaTerminos &listaResu);

void destuirListaTerminos(ListaTerminos &listaT);
/*Precondicion: listaT no es vacia*/

void controlTerminoIndependienteNoNulo(ListaTerminos &listaT);
/*Precondicion: listaT no es vacia*/

boolean esRaiz(ListaTerminos listaT, int valor);
/*Precondicion: ListaTerminos no es vacia y grado mayor o*/

void levantarListaTerminos(ListaTerminos &lT,String nomArch);

void bajarListaTerminos(ListaTerminos lt, String nomArch);

void InsBackListaTermino(ListaTerminos &L, Termino t);

#endif // LISTATERMINOS_H_INCLUDED
