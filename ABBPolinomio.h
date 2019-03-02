#ifndef ABBPOLINOMIO_H_INCLUDED
#define ABBPOLINOMIO_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoA { Polinomio info;
    nodoA * hizq;
    nodoA * hder;
} nodoABB;

typedef nodoABB * ABBPolinomio;

void ABBPolinomioCrear(ABBPolinomio &a);
///Crear ABB

boolean ABBPolinomioEsVacio(ABBPolinomio a);
///retorna si es abb es vacio.

Polinomio ABBPolinomioDarRaiz(ABBPolinomio a);
///retorno raiz

ABBPolinomio ABBPolinomioDarHijoIzq(ABBPolinomio a);
///retorna hijo izquierdo

ABBPolinomio ABBPolinomioDarHjoDer(ABBPolinomio a);
///retorna hijo derecho.

void ABBPolinomioListar(ABBPolinomio a);
///Precondición: árbol no sea vacío.

boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio);

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p);
///Precondición: polinomio no debe existir en el árbol.

Polinomio darPolinomio(ABBPolinomio a, String nombrePol);
///Precondición: nombrePolinomio existe en el ÁBB.

void ABBPolinomioEliminar(ABBPolinomio &a);
///Precondicion: a no sea vacio.


#endif // ABBPOLINOMIO_H_INCLUDED
