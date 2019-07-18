#include "Linea.h"


void DarCodigoLinea(Linea l,String &nomLinea)
{
    strcop(nomLinea,l.numeroLinea);
}

Recorrido DarRecorrido(Linea l)
{
    return l.recorrido;
}

Linea DarLinea(Linea l)
{


}

void MostrarLinea(Linea l)
{
    printf("\n: Numero Linea: ");
    MostrarString(l.numeroLinea);
    /*printf("\n: Origen: ");
    MostrarOrigen(l.recorrido);
    printf("\n: Destino: ");
    MostrarDestino(l.recorrido);
    printf("\n: Cant Paradas: ");
    printf("%d",Largo(l.recorrido));*/
}

void CargarLinea(Linea &l)
{
    Linea linea;
    int num;
    Recorrido recorrido;
    String auxNumLinea;
    strcrear(auxNumLinea);
    printf("\n Cargar linea:");
    printf("\n Numero Linea: ");
    scan(auxNumLinea);
}

