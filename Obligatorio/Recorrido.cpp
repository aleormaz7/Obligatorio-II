#include "Recorrido.h"


void Crear(Recorrido &r)
{
    r.prim = NULL;
    r.ult = NULL;
}

void InsFront(Recorrido &r, Parada p)
{
    //Nodo nodo = new Nodo;
    //nodo->parada = p;
   //to be continued
}

boolean EsVacia(Recorrido &r)
{
    return (boolean) (r.prim == NULL);
}

///MostrarRecorrido(Recorrido r);

///Primero //Devuelve el primer elemento de la secuencia.//Precondición: la secuencia no es vacía.

///Resto ?// Secuencia ® SecuenciaDevuelve la secuencia sin su primer elemento.Precondición: la secuencia no es vacía

int Largo(Recorrido r);//Devuelve la cantidad de elementos de la secuencia.
