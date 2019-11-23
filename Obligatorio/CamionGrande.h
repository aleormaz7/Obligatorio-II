#ifndef CAMIONGRANDE_H_INCLUDED
#define CAMIONGRANDE_H_INCLUDED

#include "Camion.h"

class CamionGrande : public Camion
{

    private:
        float volumen;
        Fecha fechaAdquirido;

    public:
        CamionGrande();
        CamionGrande(String,String,int,Camionero*,float,Fecha);
        CamionGrande(const CamionGrande &);
        ~CamionGrande();
        float getVolumen();
        String getTipo();
        float calcularMetrosCubicosAnuales();
};

#endif // CAMIONGRANDE_H_INCLUDED
