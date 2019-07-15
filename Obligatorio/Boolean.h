#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

#include <stdio.h>

const int TAM = 4;

typedef enum {FALSE,TRUE} boolean;

typedef boolean ArrayBooleanos[TAM];

void CargarBoolean(boolean &b);///carga un booleano

void MostrarBoolean(boolean b);///mostrar un booleano

void CargarArrayBooleanosEnFalse(ArrayBooleanos &arreBoleanos);

void MostrarArrayBooleanos(ArrayBooleanos arreBoleanos);

#endif // BOOLEAN_H_INCLUDED
