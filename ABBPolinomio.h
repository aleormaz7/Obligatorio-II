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
///Precondici�n: ABB NO vac�o

ABBPolinomio ABBPolinomioDarHijoIzq(ABBPolinomio a);///retorna hijo izquierdo
///Precondici�n: ABB NO vac�o

ABBPolinomio ABBPolinomioDarHjoDer(ABBPolinomio a);///retorna hijo derecho.
///Precondici�n: ABB NO vac�o

void ABBPolinomioListar(ABBPolinomio a);///Lista los polinimios almacenados en el ABB, se listas en Orden
///Precondici�n: �rbol no sea vac�o.

///Retorna TRUE si en el ABB existe un polinimion con el nombrePolinomio
boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio);

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p);///Inserta el Polinomio ordendo alfabeticamente segun el nombre del mismo
///Precondici�n: Polinomio no existe en ABB.

Polinomio darPolinomio(ABBPolinomio a, String nombrePol);///retorna el Polinomio deseado
///Precondici�n: Polinomio existe en ABB.

void ABBPolinomioEliminar(ABBPolinomio &a);///Elimina cada uno de los Polinomios de ABB, liberando la memoria dinamica utilizada.
///Precondicion: ABB no sea vacio.

#endif // ABBPOLINOMIO_H_INCLUDED
