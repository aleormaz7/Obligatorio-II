#include "Linea.h"

void DarCodigoLinea(Linea l,String &nomLinea)
{
    strcrear(nomLinea);
    strcop(nomLinea,l.numeroLinea);
}

Recorrido DarRecorrido(Linea l)
{
    return l.recorrido;
}

void MostrarLinea(Linea l)
{
    printf("\nLinea: ");
    print(l.numeroLinea);
    printf(" || Origen: ");
    MostrarOrigen(l.recorrido);
    printf(" || Destino: ");
    MostrarDestino(l.recorrido);
    printf(" || Cant. de paradas: ");
    printf("%d",LargoRecorrido(l.recorrido));
}

void CargarLinea(Linea &l)
{
    Recorrido recorrido;
    CrearRecorrido(recorrido);
    l.recorrido = recorrido;

    String auxNumLinea;
    strcrear(auxNumLinea);
    printf("\n Numero Linea: ");
    scan(auxNumLinea);
    StringAMayusculas(auxNumLinea);
    strcrear(l.numeroLinea);
    strcop(l.numeroLinea, auxNumLinea);
    strdestruir(auxNumLinea);
}

//7.
void ListarParadasDeRecorridoEnLinea(Linea l)
{
    printf("\nLinea ");
    print(l.numeroLinea);
    printf(":");
    MostrarRecorrido(l.recorrido);
}

void AgregarParadaARecorridoDeLinea(Linea &l, Parada p)
{
    InsBackRecorrido(l.recorrido,p);
}

