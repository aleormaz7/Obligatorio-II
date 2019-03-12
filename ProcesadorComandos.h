#ifndef _PROCESADORCOMANDOS
#define _PROCESADORCOMANDOS

#include "ListaString.h"
#include "ABBPolinomio.h"
#include "Archivo.h"

///crear el Polinimio a partir de la lista de String
void comandoCrear(ABBPolinomio &abb, ListaString ls);

///a partir de la lista de String, suma dos polinomios y genera otro con el resultado
void comandoSumar(ABBPolinomio &abb, ListaString ls);

///a partir de la lista de String, multiplica dos polinomios y genera otro con el resultado
void comandoMultiplicar(ABBPolinomio &abb, ListaString ls);

///a partir de la lista de String, evalua un polinomio para un valor entero
void comandoEvaluar(ABBPolinomio abb, ListaString ls);

///a partir de la lista de String, evalua si el numero el valor entero
void comandoEsRaiz(ABBPolinomio abb, ListaString ls);

///lista los polinomios contenidos en memoria(ABB) ordenados alfabeticamente por su nombre
void comandoMostrar(ABBPolinomio abb, ListaString ls);

///a partir de la lista de String, guarda en un archivo .txt un polinomio exitente en memoria
void comandoGuardar(ABBPolinomio abb, ListaString ls);

///a partir de la lista de String, recupera un polinomio de un archivo .txt y lo carga en el ABB
void comandoRecuperar(ABBPolinomio &abb, ListaString ls);

///libera la memoria dinamica utilzada en la ejecucion del programa
void comandoSalir(ABBPolinomio &abb, boolean &fin, ListaString ls);

#endif // PROCESADORCOMANDOS_H_INCLUDED
