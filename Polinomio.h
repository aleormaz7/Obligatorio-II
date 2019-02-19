#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "String.h"
#include "ListaTerminos.h"

typedef struct { String nombre;
                 ListaTerminos Terminos;
               } Polinomio;

void polinomioCrear(Polinomio &p, String nombre, ListaTerminos listaT);

void darListaTerminos(Polinomio p, ListaTerminos &listaT);

void mostrarPolinomio(Polinomio p);

void darNombre (Polinomio p, String &s);

void borrar();

#endif // POLINOMIO_H_INCLUDED
