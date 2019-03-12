#ifndef _ABBPOLINOMIO
#define _ABBPOLINOMIO

#include "Polinomio.h"

typedef struct nodoA { Polinomio info;
                        nodoA * hizq;
                        nodoA * hder;
                     } nodoABB;

typedef nodoABB * ABBPolinomio;

void ABBPolinomioCrear(ABBPolinomio &a);
///Crear ABB apuntando a NULL

boolean ABBPolinomioEsVacio(ABBPolinomio a);
///retorna si es abb es vacio.

Polinomio ABBPolinomioDarRaiz(ABBPolinomio a);///retorna el nodo raiz
///Precondición: ABB NO vacío

ABBPolinomio ABBPolinomioDarHijoIzq(ABBPolinomio a);///retorna hijo izquierdo
///Precondición: ABB NO vacío

ABBPolinomio ABBPolinomioDarHjoDer(ABBPolinomio a);///retorna hijo derecho.
///Precondición: ABB NO vacío

void ABBPolinomioListar(ABBPolinomio a);///Lista los polinimios almacenados en el ABB, se listas en Orden
///Precondición: árbol no sea vacío.

///Retorna TRUE si en el ABB existe un polinimion con el nombrePolinomio
boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio);

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p);///Inserta el Polinomio ordendo alfabeticamente segun el nombre del mismo
///Precondición: Polinomio no existe en ABB.

Polinomio darPolinomio(ABBPolinomio a, String nombrePol);///retorna el Polinomio deseado
///Precondición: Polinomio existe en ABB.

void ABBPolinomioEliminar(ABBPolinomio &a);///Elimina cada uno de los Polinomios de ABB, liberando la memoria dinamica utilizada.
///Precondicion: ABB no sea vacio.

#endif // ABBPOLINOMIO_H_INCLUDED
