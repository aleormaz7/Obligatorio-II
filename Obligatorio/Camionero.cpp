#include "Camionero.h"

Camionero :: Camionero() : nombre(), fechaNacimiento()
{
    cedula = 0;
    cantTatuajes = 0;
}

Camionero :: Camionero(long ced,String nom,int cntTatuajes,Fecha fchNac) : nombre(nom), fechaNacimiento(fchNac)
{
    cedula = ced;
    cantTatuajes = cntTatuajes;
}

Camionero :: Camionero(const Camionero &c) : nombre(c.nombre),fechaNacimiento(c.fechaNacimiento)
{
    cedula = c.cedula;
    cantTatuajes = c.cantTatuajes;
}

Camionero :: ~Camionero()
{

}

long Camionero :: getCedula()
{
    return cedula;
}

String Camionero :: getNombre()
{
    return nombre;
}

int Camionero :: getCantTatuajes()
{
    return cantTatuajes;
}

Fecha Camionero :: getFechaNacimiento()
{
    return fechaNacimiento;
}

String Camionero :: getTipo()
{
    return "Camionero";
}
