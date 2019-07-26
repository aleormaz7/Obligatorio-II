#ifndef CIUDADES_H_INCLUDED
#define CIUDADES_H_INCLUDED

#include "Ciudad.h"

const int B = 4;/*cant cubetas*/

typedef struct nodoL {  Ciudad info;
                        nodoL * sig;
                     } NodoCiudades;

typedef NodoCiudades * ListaCiudades;

typedef ListaCiudades Ciudades[B];


/// Crea el Hash de ciudades vacio
void MakeCiudades(Ciudades &C);

///Determina si en el diccionario existe la ciudad especificada por su clave (nombre)
boolean Member(Ciudades C, String nombreCiudad);

///Inserta la ciudad en el Hash
void Insert(Ciudades &C, Ciudad ciu);
/*Precondicion: la ciudad no existe en el Hash -> !Member(nomCiudad)*/


/// Retorna la ciudad correspindiente a la clave(nombre)
Ciudad FindCiudad(Ciudades C, String nomCiudad);
///Precondición: la ciudad es existe en el Hash -> member(nomCiudad)


#endif // CIUDADES_H_INCLUDED
