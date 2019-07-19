#ifndef LINEA_H_INCLUDED
#define LINEA_H_INCLUDED

#include "Recorrido.h"

typedef struct { String numeroLinea;
                 Recorrido recorrido;
                } Linea;

void DarCodigoLinea(Linea l,String &nomLinea);

Recorrido DarRecorrido(Linea l);

void MostrarLinea(Linea l);

void CargarLinea(Linea &l);

//6. Dado el c�digo que identifica a una l�nea, agregar una nueva parada a su recorrido. Se
//   debe chequear que efectivamente exista un tramo entre la nueva parada y la �ltima parada
//   registrada hasta el momento en la l�nea.
void AgregarParadaARecorridoDeLinea(Linea &l, int numeroCiudad1, int numeroCiudad2);

//7. Dado el c�digo que identifica a una l�nea, listar todas las paradas (n�mero de parada y
//   nombre de ciudad) de su recorrido.
void ListarParadasDeRecorridoEnLinea(Linea l);


#endif // LINEA_H_INCLUDED
