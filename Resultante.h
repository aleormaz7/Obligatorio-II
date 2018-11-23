#ifndef RESULTANTE_H_INCLUDED
#define RESULTANTE_H_INCLUDED

//#include "Revision.h"
#include <stdio.h>

typedef enum {SATISFACTORIO, INCOMPLETA, PENDIENTE} Resultante;


void CargarResultante(Resultante &r);

void MostrarResultante(Resultante r);


#endif // RESULTANTE_H_INCLUDED
