#ifndef RESULTANTE_H_INCLUDED
#define RESULTANTE_H_INCLUDED


#include <stdio.h>

typedef enum {SATISFACTORIO, INCOMPLETA, PENDIENTE} Resultante;


void CargarResultante(Resultante &r);///Carga el resultante

void MostrarResultante(Resultante r);///Muestra el resultante


#endif // RESULTANTE_H_INCLUDED
