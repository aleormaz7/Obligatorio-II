#ifndef ABBPOLINOMIO_H_INCLUDED
#define ABBPOLINOMIO_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoA { Polinomio info;
    nodoA * hizq;
    nodoA * hder;
} nodo;

typedef nodo * ABBPolinomio;

void ABBPolinomioCrear(ABBPolinomio &a);

boolean ABBPolinomioEsVacio(ABBPolinomio a);

Polinomio ABBPolinomioDarRaiz(ABBPolinomio a);

ABBPolinomio ABBPolinomioDarHijoIzq(ABBPolinomio a);

ABBPolinomio ABBPolinomioDarHjoDer(ABBPolinomio a);

void ListarABBPolinomio(ABBPolinomio a);
//Precondición: árbol no sea vacío

boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio);

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p);
//Precondición: polinomio no debe existir en el árbol

boolean existeEnArbol(ABBPolinomio a, String s);

Polinomio obtenerPolinomio(ABBPolinomio a, String s);
//Precondición: s existe en el Árbol

void ABBPolinomioEliminar (ABBPolinomio &a);
//Precondicion: a no sea vacio



#endif // ABBPOLINOMIO_H_INCLUDED
