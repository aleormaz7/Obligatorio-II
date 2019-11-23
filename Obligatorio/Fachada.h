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
        void AltaCamionero(Camionero *,tipoError &error);


        void ListadoCamioneros(Iterador &);

        //void AltaCamion(Camion *);
};


#endif // FACHADA_H_INCLUDED
