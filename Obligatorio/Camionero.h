#ifndef CAMIONERO_H_INCLUDED
#define CAMIONERO_H_INCLUDED



#include "String.h"
#include "Fecha.h"

#include "Objeto.h"

class Camionero : public Objeto
{
    private:
        long cedula;
        String nombre;
        int cantTatuajes;
        Fecha fechaNacimiento;

    public:
        Camionero();///c.defecto
        Camionero(long,String,int,Fecha);///c.comun
        Camionero(const Camionero &);///c.copia
        ~Camionero();
        long getCedula();
        String getNombre();
        int getCantTatuajes();
        Fecha getFechaNacimiento();
        String getTipo();

};



#endif // CAMIONERO_H_INCLUDED
