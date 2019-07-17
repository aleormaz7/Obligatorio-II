#include "Linea.h"


int DarNumero(Linea l)
{
    return l.numero;
}

Recorrido DarRecorrido(Linea l)
{
    return l.recorrido;
}

void MostrarLinea(Linea l)
{
    printf("Linea numero: %d", l.numero);
    printf("\nRecorrido: ");
    //MostrarRecorrido(l.recorrido);
}

void CargarLinea(Linea &l)
{
    Linea linea;
    int num;
    Recorrido recorrido;
    String s;
    strcrear(s);
    printf("Cargar linea:");
    printf("\nNumero: ");
    scanf("%d",num);
    //CargarRecorrido(recorrido);
    //linea.numero = num;
    //linea.recorrido = recorrido;
}

