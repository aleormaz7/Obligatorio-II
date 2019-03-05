#ifndef _TERMINO
#define _TERMINO

#include "String.h"

typedef struct {long int coef;
                int grado;
               } Termino;

void CrearTermino(Termino &t, long int coef, int grado);

void MostrarTermino(Termino t);

long int DarCoefTermino(Termino t);

int DarGradoTermino(Termino t);

void BajarTermino(Termino t, FILE * f);

void LevantarTermino(Termino &t, FILE * f);

#endif // TERMINO_H_INCLUDED
