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
///Precondici�n: �rbol no sea vac�o.

boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio);

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p);
///Precondici�n: polinomio no debe existir en el �rbol.

Polinomio darPolinomio(ABBPolinomio a, String nombrePol);
///Precondici�n: nombrePolinomio existe en el �BB.

void ABBPolinomioEliminar(ABBPolinomio &a);
///Precondicion: a no sea vacio.


#endif // ABBPOLINOMIO_H_INCLUDED
