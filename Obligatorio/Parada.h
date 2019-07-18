#ifndef PARADA_H_INCLUDED
#define PARADA_H_INCLUDED

#include "Ciudad.h"


typedef struct{ int numero;
                Ciudad ciudad;
            }Parada;

int DarNumero(Parada p);

Ciudad DarCiudad(Parada p);

void MostrarParada(Parada p);

void CargarParada(Parada &p);


#endif // PARADA_H_INCLUDED
