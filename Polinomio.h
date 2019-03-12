#ifndef _POLINOMIO
#define _POLINOMIO

#include "ListaTerminos.h"

typedef struct { String nombre;
                 ListaTerminos listaTerminos;
               } Polinomio;

void crearPolinomio(Polinomio &p,String nombre, ListaTerminos lst);

void darListaTerminosPolinomio(Polinomio p, ListaTerminos &listaT);
/* devuelve lista de terminos del polinomio */

void mostrarPolinomio(Polinomio p);
/* muestra nombre y lista de terminos del polinomio */

void darNombrePolinomio(Polinomio p, String &s);
/* devuelve nombre del polinomio */

void borrarPolinomio(Polinomio &p);
/* borra nombre y lista de terminos del polinomio*/


#endif // POLINOMIO_H_INCLUDED
