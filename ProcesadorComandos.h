#ifndef _PROCESADORCOMANDOS
#define _PROCESADORCOMANDOS

#include "ListaString.h"
#include "ABBPolinomio.h"
#include "Archivo.h"

///crear el Polinimio a partir de la lista de String
void comandoCrear(ABBPolinomio &abb, ListaString ls);

///Suma dos polinomios y genera otro con el resultado
void comandoSumar(ABBPolinomio &abb, ListaString ls);

///Multiplica dos polinomios y genera otro con el resultado
void comandoMultiplicar(ABBPolinomio &abb, ListaString ls);

///Evalua un polinomio, para el valor entero
void comandoEvaluar(ABBPolinomio abb, ListaString ls);

///Evalua si el numero el valor entero
void comandoEsRaiz(ABBPolinomio abb, ListaString ls);

///lista los polinomios contenidos en memoria(ABB) ordenados alfabeticamente por su nombre
void comandoMostrar(ABBPolinomio abb, ListaString ls);

///Guarda un polinomio exitente en memoria en el archivo
void comandoGuardar(ABBPolinomio abb, ListaString ls);

///recupera un polinomio de un archivo y lo carga en el ABB
void comandoRecuperar(ABBPolinomio &abb, ListaString ls);

///libera la memoria dinamica
void comandoSalir(ABBPolinomio &abb, boolean &fin, ListaString ls);

#endif // PROCESADORCOMANDOS_H_INCLUDED
