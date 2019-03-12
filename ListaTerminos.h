#ifndef _LISTATERMINOS
#define _LISTATERMINOS

#include "Termino.h"
#include "String.h" ///Se hace este include, por los procedimientos de bajar y levantar de archivo

typedef struct nodoT { Termino info;
                        nodoT * Sig;
                      } nodoTermino;

typedef nodoTermino * ListaTerminos;

void listaTerminosCrear(ListaTerminos &listaT); ///crea la lista de terminos

boolean listaTerminosEsVacia(ListaTerminos listaT);///retorna TRUE si la lista de terminos es vacia

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente el termino en la lista, ordenado de mayor a menor por grado*/

void listaTerminosMostrar(ListaTerminos listaT);///Lista los terminos de la lista
/*Precondicion: ListaTerminos no es vacia*/

long int evaluarPolinomio(ListaTerminos listaT, int valor);
///evalua el Polinomio(su lista de terminos) para el valor numerico entero ingresado, retornando el valor resultante
/*Precondicion: ListaTerminos no es vacia y grado mayor o*/

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);
///recibe dos polinomios(sus listas de terminos), los suma y crea otro con el resultado de la operacion

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);
///recibe dos polinomios(sus listas de terminos), los multiplica y crea otro con el resultado de la operacion

boolean representaPolinomioNulo(ListaTerminos listaT);
///Retorna si Polinomio(su lista de terminos) representa un Polinomio NULO
/*Precondicion: listaT no es vacia */

void reduceListaTerminos(ListaTerminos listaT, ListaTerminos &listaResultante);
///Recibe una lista de terminos, resultante de una multiplicacion de dos Polinomios, y retorna una nueva con la reduccion de la misma
/*Precondicion: listaT no es vacia && listaT no representa un ponilomio nulo*/

void listaTerminosCopiar(ListaTerminos listaTOri,ListaTerminos &listaResu);
///copia Termino por termino, una lista de terminos

void destuirListaTerminos(ListaTerminos &listaT);///Libera la memoria dinamica de una lista de Terminos
/*Precondicion: listaT no es vacia*/

void controlTerminoIndependienteNoNulo(ListaTerminos &listaT);
/// Verifica si tiene grado mayor a 0 y termino independiente igual a 0
/// en caso de tenerlo, se elimina. La idea es que no queden terminos independientes nulos cuando no es el polinomio nulo
/*Precondicion: listaT no es vacia*/

boolean esRaiz(ListaTerminos listaT, int valor);
///retorna TRUE si el resultado de evular una lista de terminos para un valor numerico entero, es igual a 0
/*Precondicion: ListaTerminos no es vacia y grado mayor o*/

///Levanta la lista de terminos del archivo
void levantarListaTerminos(ListaTerminos &lT,String nomArch);

///Baja la lista de terminos al archivo
void bajarListaTerminos(ListaTerminos lt, String nomArch);
/*Precondicion: */

///Inserta el termino al final de la lista
void InsBackListaTermino(ListaTerminos &L, Termino t);

#endif // LISTATERMINOS_H_INCLUDED
