#include "CamionGrande.h"

CamionGrande :: CamionGrande() : Camion(), fechaAdquirido()
{
    volumen = 0.0;
}

CamionGrande :: CamionGrande(String mat,String mar,int cant,float vol,Fecha fch) : Camion(mat,mar,cant), fechaAdquirido(fch)
{
    volumen = vol;
}

CamionGrande :: CamionGrande(const CamionGrande &c) : Camion(c), fechaAdquirido(c.fechaAdquirido) ///ver cabezal Camion(parametros)??
{
    volumen = c.volumen;
}

CamionGrande :: ~CamionGrande()
{

}

float CamionGrande :: getVolumen()
{
    return volumen;
}

String CamionGrande :: getTipo()
{
    return "CAMION GRANDE";
}

Fecha CamionGrande :: getFechaAdquirido()
{
    return fechaAdquirido;
}

float CamionGrande :: calcularMetrosCubicosAnuales()
{
    return (getCantViajesAnuales() * volumen);
}


