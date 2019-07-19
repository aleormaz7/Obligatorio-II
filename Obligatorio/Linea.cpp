#include "Linea.h"


void DarCodigoLinea(Linea l,String &nomLinea)
{
    strcop(nomLinea,l.numeroLinea);
}

Recorrido DarRecorrido(Linea l)
{
    return l.recorrido;
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
    int num;
    Recorrido recorrido;
    String auxNumLinea;
    strcrear(auxNumLinea);
    printf("\n Numero Linea: ");
    scan(auxNumLinea);
    StringAMayusculas(auxNumLinea);
    strcop(l.numeroLinea, auxNumLinea);
    /*
    if(ExiteAlMenosUnTramo())
    {
         printf("\nQuiere agregar el recorrido de la linea?");
    }
    else
    {
        printf("\nNo es posible especificar un recorrido a la linea,");
        printf("\nya que aun no se han especificado tramos entre ciudades.");
    }*/
}

void ListarParadasDeRecorridoEnLinea(Linea l)
{


}

