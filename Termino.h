#ifndef _TERMINO
#define _TERMINO

#include <stdio.h> ///se incluye por el FILE

typedef struct {long int coef;
                int grado;
               } Termino;

void CrearTermino(Termino &t, long int coef, int grado);
///Recibe un coeficiente y su grado, y crea el termino con dichos valores

void MostrarTermino(Termino t);
///Desplega en pantalla la informacion del termino

long int DarCoefTermino(Termino t);
///retorna el coeficiente del termino

int DarGradoTermino(Termino t);
///retorna el grado del termino

void BajarTermino(Termino t, FILE * f);
///Baja el termino al archivo

void LevantarTermino(Termino &t, FILE * f);
///Levanta el termino desde el archivo

#endif // TERMINO_H_INCLUDED
