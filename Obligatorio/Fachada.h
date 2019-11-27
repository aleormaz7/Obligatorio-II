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
        void AltaCamion(Camion * c,long cedula,tipoError &error);

        void ListadoCamioneros(Iterador &);

        void ListadoCamiones(Iterador &iter);

};


#endif // FACHADA_H_INCLUDED
