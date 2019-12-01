#include "CamionConRemolque.h"

CamionConRemolque :: CamionConRemolque() : CamionGrande()
{
    capRemolque = 0;
}

CamionConRemolque :: CamionConRemolque(String mat,String mar,int cant,float vol,Fecha f,float cap) : CamionGrande(mat,mar,cant,vol,f)
{
    capRemolque = cap;
}

CamionConRemolque :: CamionConRemolque(const CamionConRemolque &c) : CamionGrande(c)
{
    capRemolque = c.capRemolque;
}

CamionConRemolque :: ~CamionConRemolque()
{
}

int CamionConRemolque :: getCapRemolque()
{
    return capRemolque;
}

String CamionConRemolque :: getTipo()
{
    return "CAMION CON REMOLQUE";
}

float CamionConRemolque :: calcularMetrosCubicosAnuales()
{
    float resu = CamionGrande :: calcularMetrosCubicosAnuales();
    resu = resu + (capRemolque * getCantViajesAnuales());
    return resu;
}
