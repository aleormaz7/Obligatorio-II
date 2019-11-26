#include "CamionSimple.h"

CamionSimple :: CamionSimple() : Camion(), depto()
{

}

CamionSimple :: CamionSimple(String mat,String mar,int cant,String dep) : Camion(mat,mar,cant), depto(dep)
{

}

CamionSimple :: CamionSimple(const CamionSimple &c) : Camion(c), depto(c.depto)
{

}

CamionSimple :: ~CamionSimple()
{

}

String CamionSimple :: getDepto()
{
    return depto;
}

String CamionSimple :: getTipo()
{
    return "CAMION SIMPLE";
}

float CamionSimple :: calcularMetrosCubicosAnuales()
{
    return (getCantViajesAnuales() * 10);
}
