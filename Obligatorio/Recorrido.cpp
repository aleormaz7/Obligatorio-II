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
    if (r.ult == NULL)
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

boolean EsVacia(Recorrido &r)
{
    return (boolean) (r.prim == NULL);
}

int LargoRecorrido(Recorrido r)///VER ESTO ????????????????????
{
    /*
    if(r.prim == NULL)
        return 0;
    else
       return 1 + LargoRecorrido(r.prim->sig);
       ///VER ESTO ????????????????????
       */
    int Largo = 0;
    while(r.prim !=NULL)
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
        MostrarParada(r.prim->parada);
        r.prim = r.prim->sig;
    }
}

/*void CargarRecorrido(Recorrido &r)
{


}*/

void MostrarOrigen(Recorrido r)
{
   // MostrarParada(r.prim);
}

void MostrarDestino(Recorrido r)
{
    //MostrarParada(r.ult);
}
