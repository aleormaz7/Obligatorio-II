#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include "Fachada.h"

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

        void camioneroConMayorCntTatuajes();

};



#endif // CONTROLADOR_H_INCLUDED
