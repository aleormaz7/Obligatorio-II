#include "ListaTerminos.h"

boolean listaTerminosEsVacia(ListaTerminos listaT)
{
    boolean EsVacia = FALSE;
    if (listaT == NULL)
        EsVacia = TRUE;
    return EsVacia;
}

void listaTerminosResto(ListaTerminos &listaT); /*borrar 1er valor*/


void listaTerminosCrear(ListaTerminos &listaT)
{
    listaT = NULL;
}

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente ordenado por grado*/


//Precondición: lista no vacia
void listaTerminosMostrar(ListaTerminos t)
{
    while (t->Sig != NULL)
    {
        MostrarTermino(t->info);
        t = t->Sig;
    }
}

long int evaluarPolinomio(ListaTerminos listaT, int valor)
{
    long int resultado  = 0;
    return resultado;
}

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado)
{

}

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado)
{

}
/*
void levantarTerminos(file * f, ListaTerminos &listaT)
{

}

void bajarTerminos(file * f, ListaTerminos listaTerminos);
*/

boolean representaPolinomioNulo(ListaTerminos listaTerminos)
{
    boolean resu = FALSE;
    if (listaTerminos == NULL)
        resu = TRUE;
    return resu;
}

ListaTerminos reducePolinomio(ListaTerminos listaTerminos)
{
    ListaTerminos aux;
    return aux;
}
