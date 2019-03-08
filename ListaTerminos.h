#ifndef _LISTATERMINOS
#define _LISTATERMINOS

#include "Termino.h"
#include "String.h" ///Se hace este include, por los procedimientos de bajar y levantar de archivo

typedef struct nodoT { Termino info;
                        nodoT * Sig;
                      } nodoTermino;

typedef nodoTermino * ListaTerminos;

void listaTerminosCrear(ListaTerminos &listaT);

boolean listaTerminosEsVacia(ListaTerminos listaT);

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente el termino en la lista, ordenado de mayor a menor por grado*/

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

///Baja la lista de terminos al archivo
void bajarListaTerminos(ListaTerminos lt, String nomArch);
/*Precondicion: */

///Inserta el termino al final de la lista
void InsBackListaTermino(ListaTerminos &L, Termino t);

#endif // LISTATERMINOS_H_INCLUDED
