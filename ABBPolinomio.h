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
//Precondici�n: �rbol no sea vac�o

boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio);

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p);
//Precondici�n: polinomio no debe existir en el �rbol

boolean existeEnArbol(ABBPolinomio a, String s);

Polinomio obtenerPolinomio(ABBPolinomio a, String s);
//Precondici�n: s existe en el �rbol

void ABBPolinomioEliminar (ABBPolinomio &a);
//Precondicion: a no sea vacio



#endif // ABBPOLINOMIO_H_INCLUDED
