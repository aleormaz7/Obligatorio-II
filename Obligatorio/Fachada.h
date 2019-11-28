#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include "Camioneros.h"
#include "Camiones.h"

#include "TipoError.h"


class Fachada
{
   private:
        Camioneros camioneros;
        Camiones camiones;

    public:
        Fachada();
        void AltaCamionero(Camionero *,tipoError &);
        void AltaCamion(Camion *,long,tipoError &);
        void ModificarViajesAnuales(int,String,Camion * &,tipoError &);

        Iterador ListadoCamioneros();
        Iterador ListadoCamiones();
        void DetalleCamion(String,Camion * &,tipoError &);
        float TotalMetrosCubicosAnuales();
        void CantidadCamionesPorTipo(int &cantSimple,int &cantGrande,int &cantRemolque);

        void CantidadCamionesGrandesFechaAdq(int &cant,Fecha &f);
};


#endif // FACHADA_H_INCLUDED
