#include "CamionConRemolque.h"

CamionConRemolque :: CamionConRemolque() : CamionGrande()
{
    capRemolque = 0;
}

CamionConRemolque :: CamionConRemolque(String mat,String mar,int cant,Camionero * c,float vol,Fecha f,int cap) : CamionGrande(mat,mar,cant,c,vol,f)
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
    return "CAMION_CON_REMOLQUE";
}

float CamionConRemolque :: calcularMetrosCubicosAnuales()
{
    return 0.0;
}
