#ifndef CAMIONCONREMOLQUE_H_INCLUDED
#define CAMIONCONREMOLQUE_H_INCLUDED

#include "CamionGrande.h"

class CamionConRemolque : public CamionGrande
{
    private:
        float capRemolque;
    public:
        CamionConRemolque();
        CamionConRemolque(String,String,int,float,Fecha,float);
        CamionConRemolque(const CamionConRemolque &);
        ~CamionConRemolque();
        int getCapRemolque();
        String getTipo();
        float calcularMetrosCubicosAnuales();
};

#endif // CAMIONCONREMOLQUE_H_INCLUDED
