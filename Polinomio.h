#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "String.h"
#include "ListaTerminos.h"

typedef struct { String nombre;
ListaTerminos Terminos;
} Polinomio;

void Crear(Polinomio &p, String nombre, listaTerminos listaT);

void darListaTerminos(Polinomio p, listaTerminos &listaT);

void mostrarPolinomio(Polinomio p);

void darNombre (Polinomio p, String &s);

Boolean esNulo (Polinomio p);

void borrar()

#endif // POLINOMIO_H_INCLUDED
