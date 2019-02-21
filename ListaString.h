#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED

#include "String.h"


typedef struct nodoS  { String info;
                        nodoS * Sig;
                      } nodoString;

typedef nodoString * ListaString;


void CrearListaString(ListaString &L);
///Crea la lista vacia

void InsBackListaString(ListaString &L, String s);
///inserta un String al final de la lista

void partirString(String s, ListaString &ls);
///Recibe un String, y retorna una lista con cada String que se encuentran separados por espacio
/*Precondicion: el largo del String sea > 0 */

int LargoListaString (ListaString L);
///Retorna el largo de la lista.

void destruirListaString(ListaString &ls);
///Libera la menoria dinamica referente a la misma
/*Preconducion Ls no es vacia*/

boolean CoeficientesEnteros(ListaString ls);
///Controla que todos los String que se coindicen con coefientes, representen un entero
/*Precondicion: Primer String de lista sea “crear” y el largo de la lista sea mayor a 2*/

void obtenerString(ListaString ls, int pos, String &s);
///Retorna el String almacenado en una pocicion dada de la lista
/*Precondicion: posicion <= al largo de lista*/

void MostrarListaString (ListaString L);

#endif // LISTASTRING_H_INCLUDED
