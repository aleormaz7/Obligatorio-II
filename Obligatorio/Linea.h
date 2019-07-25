#ifndef LINEA_H_INCLUDED
#define LINEA_H_INCLUDED

#include "Recorrido.h"

typedef struct { String numeroLinea;
                 Recorrido recorrido;
                } Linea;

/// Retorna un String con el codigo de la linea
void DarCodigoLinea(Linea l,String &nomLinea);

///Retorna el recorrido de la linea
Recorrido DarRecorrido(Linea l);

///Muestra en pantalla la informacion corresponiente a la linea
void MostrarLinea(Linea l);

/// Solicita y cargar la informacion necesaria de una linea
void CargarLinea(Linea &l);


/// Agrega la parada al recorrido de linea
void AgregarParadaARecorridoDeLinea(Linea &l, Parada p);
///Precondicion: Si recorrido !RecorridoVacio exitetramo(DestinoRecorido,nuevaParada)


/// Lista la informacion de todas las paradas del recorrido(número de parada y nombre de ciudad)
void ListarParadasDeRecorridoEnLinea(Linea l);


#endif // LINEA_H_INCLUDED
