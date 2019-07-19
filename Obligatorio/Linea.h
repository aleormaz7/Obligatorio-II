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

//6. Dado el código que identifica a una línea, agregar una nueva parada a su recorrido. Se
//   debe chequear que efectivamente exista un tramo entre la nueva parada y la última parada
//   registrada hasta el momento en la línea.
void AgregarParadaARecorridoDeLinea(Linea &l, int numeroCiudad1, int numeroCiudad2);

//7. Dado el código que identifica a una línea, listar todas las paradas (número de parada y
//   nombre de ciudad) de su recorrido.
void ListarParadasDeRecorridoEnLinea(Linea l);


#endif // LINEA_H_INCLUDED
