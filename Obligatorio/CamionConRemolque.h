#ifndef CAMIONCONREMOLQUE_H_INCLUDED
#define CAMIONCONREMOLQUE_H_INCLUDED


#include "Camion.h"

class CamionConRemolque : public Camion
{
    private:
        int capRemolque;

    public:
        CamionConRemolque();
        CamionConRemolque(String,String,int,int);
        CamionConRemolque(const CamionConRemolque &);
        ~CamionConRemolque();
        int getCapRemolque();
        String getTipo();
        float calcularMetrosCubicosAnuales();

};

#endif // CAMIONCONREMOLQUE_H_INCLUDED
