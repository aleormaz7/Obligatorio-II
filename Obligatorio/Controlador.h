#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include "String.h"
#include "Fecha.h"
#include "Camionero.h"
#include "Fachada.h"
#include <limits>

void altaCamionero(Fachada &);

void altaCamion(Fachada &);

void modificarViajesAnuales(Fachada &);

void listadoCamioneros(Fachada);

void listadoCamiones(Fachada);

void detalleCamion(Fachada);

void totalMetrosCubicosAnuales(Fachada);

#endif // CONTROLADOR_H_INCLUDED
