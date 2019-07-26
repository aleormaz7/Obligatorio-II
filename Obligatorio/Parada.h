#ifndef PARADA_H_INCLUDED
#define PARADA_H_INCLUDED

#include "Ciudad.h"


typedef struct{ int numero;
                Ciudad ciudad;
            }Parada;


/// Retorna un entero con el numero de la parada
int DarNumero(Parada p);

/// Retorna la ciudad de la parada
Ciudad DarCiudad(Parada p);


/// Muestra por pantalla los datos de la parada
void MostrarParada(Parada p);

/// Muestra por pantalla los datos de la parada, se muestra con otro formato
void MostrarParadaAlternativo(Parada p);

/// Carga los datos correspondientes a la parada
void CargarParada(Parada &p, int numParada, Ciudad ciudParada);

#endif // PARADA_H_INCLUDED
