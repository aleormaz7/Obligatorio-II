#ifndef DICCIONARIOCIUDADES_H_INCLUDED
#define DICCIONARIOCIUDADES_H_INCLUDED
#include "Ciudad.h"

const int B = 5;
typedef struct nodoL {  Ciudad info;
                        nodoL * sig;
                     } Nodo;
typedef Nodo * Ciudades;
typedef Ciudades DiccionarioCiudades[B];

#endif // DICCIONARIOCIUDADES_H_INCLUDED
