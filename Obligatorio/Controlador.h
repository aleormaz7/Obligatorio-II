#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include "String.h"
#include "Fecha.h"
#include "Camionero.h"
#include "Fachada.h"
#include <limits>

class Controlador
{

    private:
        Fachada fachada;
    public:
        Controlador();

        void altaCamionero();

        void altaCamion();

        void modificarViajesAnuales();

        void listadoCamioneros();

        void listadoCamiones();

        void detalleCamion();

        void totalMetrosCubicosAnuales();

        void obtenerCamionesPorTipo();

        void cantidadCamionesGrandesFechaAdq();

};



#endif // CONTROLADOR_H_INCLUDED
