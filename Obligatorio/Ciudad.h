#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED

#include "String.h"

typedef struct{ int codigoCiudad;/*0,1,2,etc*/
                String nombreCiudad;/*Montevideo,Canelones,etc*/
              } Ciudad;

///Retorna un string con el nombre de la ciudad
void DarNombre(Ciudad c, String &nombre);

/// Retorna un entero con en codigo de la ciudad
int DarCodigo(Ciudad c);///codigo = numero ciudad (0,1)

/// Muestra en pantalla los datos de la ciudad
void MostrarCiudad(Ciudad c);

///Solicita y carga los datos necesarios de una ciudad
void CargarCiudad(Ciudad &c, int codigoCiudad);

#endif // CIUDAD_H_INCLUDED
