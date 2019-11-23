#ifndef CAMION_H_INCLUDED
#define CAMION_H_INCLUDED

#include "Objeto.h"
#include "Camionero.h"


class Camion : public Objeto
{
    private:
        String matricula;
        String marca;
        int cantViajesAnuales;
        Camionero * camionero;

    public:
        Camion();
        Camion(String,String,int,Camionero *);
        Camion(const Camion &);
        ~Camion();
        String getMatricula();
        String getMarca();
        int getCantViajesAnuales();
        void setCantViajesAnuales(int);
        virtual String getTipo() = 0;
        virtual float calcularMetrosCubicosAnuales() = 0;
};

#endif // CAMION_H_INCLUDED
