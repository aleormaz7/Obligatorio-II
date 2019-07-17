#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED
#include "String.h"

typedef struct{ int codigoCiudad;/*0,1,2,etc*/
                String nombreCiudad;/*Montevideo,Canelones,etc*/
              } Ciudad;


void DarNombre(Ciudad c, String &nombre);

int DarCodigo(Ciudad c);

void MostrarCiudad(Ciudad c);

void CargarCiudad(Ciudad &c);

#endif // CIUDAD_H_INCLUDED
