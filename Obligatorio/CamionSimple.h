#ifndef CAMIONSIMPLE_H_INCLUDED
#define CAMIONSIMPLE_H_INCLUDED

#include "Camion.h"

class CamionSimple : public Camion
{

    private:
        String depto;

    public:
        CamionSimple();
        CamionSimple(String,String,int,String,Camionero *);
        CamionSimple(const CamionSimple &);
        ~CamionSimple();
        String getDepto();
        String getTipo();
        float calcularMetrosCubicosAnuales();

};




#endif // CAMIONSIMPLE_H_INCLUDED
