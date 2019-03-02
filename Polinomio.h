#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "String.h"
#include "ListaTerminos.h"
#include "ListaString.h"

typedef struct { String nombre;
                 ListaTerminos listaTerminos;
               } Polinomio;

void crearPolinomio(Polinomio &p, ListaString listaS);
/* crea polinomio: */

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT);
/* devuelve lista de terminos del polinomio */

void mostrarPolinomio(Polinomio p);
/* muestra nombre y lista de terminos del polinomio */

void darNombrePolinomio(Polinomio p, String &s);
/* devuelve nombre del polinomio */

void borrarPolinomio(Polinomio &p);
/* borra nombre y lista de terminos del polinomio*/

void crearPolinomioResultante(Polinomio &p,String nombre, ListaTerminos lst);


#endif // POLINOMIO_H_INCLUDED
