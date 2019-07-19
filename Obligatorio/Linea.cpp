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
    printf("\nLinea: ");
    MostrarString(l.numeroLinea);
    printf(" || Origen: ");
    MostrarOrigen(l.recorrido);
    printf(" || Destino: ");
    MostrarDestino(l.recorrido);
    printf(" || Cant. de paradas: ");
    printf("%d",LargoRecorrido(l.recorrido));
}

void CargarLinea(Linea &l)
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
    /*
    if(ExiteAlMenosUnTramo(g))
    {
         printf("\nQuiere agregar el recorrido de la linea?");
    }
    else
        printf("\nSe creo exitosamente la linea, pero no es posible especificar un recorrido,\nya que aun no se han especificado tramos entre ciudades.");
    */
}

void ListarParadasDeRecorridoEnLinea(Linea l)
{
    printf("\nLinea: ");
    print(l.numeroLinea);
    printf(", ");
    MostrarRecorrido(l.recorrido);
}

