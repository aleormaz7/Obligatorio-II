#ifndef CAMIONCONREMOLQUE_H_INCLUDED
#define CAMIONCONREMOLQUE_H_INCLUDED


#include "CamionGrande.h"

class CamionConRemolque : public CamionGrande
{
    private:
        int capRemolque;

    public:
        CamionConRemolque();
        CamionConRemolque(String,String,int,Camionero*,float,Fecha,int);
        CamionConRemolque(const CamionConRemolque &);
        ~CamionConRemolque();
        int getCapRemolque();
        String getTipo();
        float calcularMetrosCubicosAnuales();

};

#endif // CAMIONCONREMOLQUE_H_INCLUDED
