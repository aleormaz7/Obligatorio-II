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

void CargarLinea(Linea &l, Grafo g)
{
    int num;
    Recorrido recorrido;
    CrearRecorrido(recorrido);
    l.recorrido = recorrido;
    String auxNumLinea;
    strcrear(auxNumLinea);
    printf("\n Numero Linea: ");
    scan(auxNumLinea);
    StringAMayusculas(auxNumLinea);
    strcop(l.numeroLinea, auxNumLinea);
    if(ExiteAlMenosUnTramo(g))
    {
         printf("\nQuiere agregar el recorrido de la linea?");
    }
    else
        printf("\nSe creo exitosamente la linea, pero no es posible especificar un recorrido,\nya que aun no se han especificado tramos entre ciudades.");
}

void ListarParadasDeRecorridoEnLinea(Linea l)
{


}

