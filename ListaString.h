#ifndef _LISTASTRING
#define _LISTASTRING

#include "String.h"
#include "ListaTerminos.h"


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
/*Preconducion: Ls no es vacia*/

boolean CoeficientesEnteros(ListaString ls);
///Retorna TRUE si todos los Stings de la lista representan un valor numerico entero
/*Precondicion: largo de la lista sea > 0*/

void obtenerString(ListaString ls, int pos, String &s);
///Retorna el String almacenado en una pocicion dada de la lista
/*Precondicion: posicion <= al largo de lista*/

void ListaStringAListaTerminos(ListaString ls, ListaTerminos &Lst);
///Recibe un lista de String y retorna una lista de Terminos coeficientes/Grado.
/*Precondicion: Largo de Ls >0 && todos sus nodos representan valores numericos enteros*/


#endif // LISTASTRING_H_INCLUDED
