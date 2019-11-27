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

        void ListadoCamioneros(Iterador &);
        void ListadoCamiones(Iterador &);
        void DetalleCamion(String,Camion * &,tipoError &);


};


#endif // FACHADA_H_INCLUDED
