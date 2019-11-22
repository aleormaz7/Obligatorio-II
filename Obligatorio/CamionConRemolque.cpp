#include "CamionConRemolque.h"

CamionConRemolque :: CamionConRemolque()
{

}

CamionConRemolque :: CamionConRemolque(String,String,int,int)
{

}

CamionConRemolque :: CamionConRemolque(const CamionConRemolque &)
{

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
    return 0.0;
}
