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

void listadoCamioneros(Fachada f);

void listadoCamiones(Fachada f);

void detalleCamion(Fachada f);

#endif // CONTROLADOR_H_INCLUDED
