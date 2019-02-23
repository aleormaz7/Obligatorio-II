#ifndef ABBPOLINOMIO_H_INCLUDED
#define ABBPOLINOMIO_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoA { Polinomio info;
    nodoA * hizq;
    nodoA * hder;
} nodo;

typedef nodo * ABBPolinomio;

void Crear(ABBPolinomio &a);

boolean esVacio(ABBPolinomio a);

Polinomio darRaiz(ABBPolinomio a);

ABBPolinomio darHijoIzq(ABBPolinomio a);

ABBPolinomio darHjoDer(ABBPolinomio a);

void ListarABB(ABBPolinomio a);
//Precondición: árbol no sea vacío

boolean existe(ABBPolinomio a, String nombrePolinomio);

void insertar(ABBPolinomio &a, Polinomio p);
//Precondición: polinomio no debe existir en el árbol

boolean existeEnArbol(ABBPolinomio a, String s);

Polinomio obtenerPolinomio(ABBPolinomio a, String s);
//Precondición: s existe en el Árbol

void Eliminar (ABBPolinomio &a);
//Precondicion: a no sea vacio



#endif // ABBPOLINOMIO_H_INCLUDED
