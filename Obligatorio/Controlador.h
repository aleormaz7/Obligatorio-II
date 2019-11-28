#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include "String.h"
#include "Fecha.h"
#include "Camionero.h"
#include "Fachada.h"
#include <limits>

void altaCamionero(Fachada &f);

void altaCamion(Fachada &f);

void modificarViajesAnuales(Fachada &f);

void listadoCamioneros(Fachada f);

void listadoCamiones(Fachada f);

void detalleCamion(Fachada f);

void totalMetrosCubicosAnuales(Fachada f);

void obtenerCamionesPorTipo(Fachada f);


#endif // CONTROLADOR_H_INCLUDED
