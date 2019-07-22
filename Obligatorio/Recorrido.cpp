#include "Recorrido.h"


void CrearRecorrido(Recorrido &r)
{
    r.prim = NULL;
    r.ult = NULL;
}

void InsBackRecorrido(Recorrido &r, Parada p)
{
    NodoRecorrido * nuevo = new NodoRecorrido;
    nuevo->parada = p;
    nuevo->sig = NULL;
    if(r.ult == NULL)
    {
        r.ult = nuevo;
        r.prim = nuevo;
    }
    else
    {
        r.ult->sig = nuevo;
        r.ult = nuevo;
    }
}

boolean RecorridoVacio(Recorrido &r)
{
    return (boolean) (r.prim == NULL);
}

int LargoRecorrido(Recorrido r)
{
    int Largo = 0;
    while(r.prim != NULL)
    {
        Largo++;
        r.prim = r.prim->sig;
    }
    return Largo;
}

void MostrarRecorrido(Recorrido r)
{
    while(r.prim != NULL)
    {
        MostrarParadaAlternativo(r.prim->parada);
        r.prim = r.prim->sig;
    }
}


void MostrarOrigen(Recorrido r)
{
    if(r.prim == NULL)
        printf(" No asignado.");
    else
        MostrarParada(r.prim->parada);
}

void MostrarDestino(Recorrido r)
{
    if(r.ult == NULL)
        printf(" No asignado.");
    else
        MostrarParada(r.ult->parada);
}

Parada Destino (Recorrido r)
{
    return r.ult->parada;
}
