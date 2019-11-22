#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


#include <stdio.h>
#include "String.h"

class Fecha
{
    private:
        int dia,mes,anio;

    public:
        Fecha ();

        Fecha(int,int,int);

        Fecha (const Fecha &);

        int getDia();

        int getMes();

        int getAnio();

        bool operator<(Fecha);///esMenor ?

        bool operator>(Fecha);///esMayor ?

        bool operator==(Fecha);///Son iguales?

        bool operator>=(Fecha);///Mayor igual?

        bool operator<=(Fecha);///Menor igual?

        Fecha operator++();///dar fecha dia siguiente

        Fecha operator++(int x);

        Fecha operator+(int);///agregar x cant dias a fecha

        int operator-(Fecha);///diferencia dias entre fechas

        bool esValida();/// esFechaValida?

        void SumarUnDia();

        void RestarUnDia();

        void MostrarFecha();


};

#endif // FECHA_H_INCLUDED
