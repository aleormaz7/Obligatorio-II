#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "Boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

void cargarFecha(Fecha &f);///cargo una fecha

void mostrarFecha(Fecha f);///muestro una fecha

boolean fechaValida(Fecha f);///determino si una fecha es valida

boolean fechaMayor(Fecha f1, Fecha f2);///Retorna si la fecha 1 es mayor a la fecha 2
///Precondicion: f1 y f2 son fechas validas.

boolean fechaIgual(Fecha f1, Fecha f2);///Retorna si las son iguales
///Precondicion: f1 y f2 son fechas validas.

int darDia(Fecha f);///devuelve dia

int darMes(Fecha f);///devuelve mes

int darAnio(Fecha f);///devuelve anio


#endif // FECHA_H_INCLUDED
