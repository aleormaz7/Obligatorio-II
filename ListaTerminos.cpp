#include "ListaTerminos.h"

Boolean listaTerminosEsVacia(ListaTerminos listaT)
{
    Boolean EsVacia = FALSE;
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
    if (!vacia(t))
    {
        while (t->Sig != NULL)
        {
            MostrarTermino(t->info);
            t = t->sig;
        }
    }
}

long int evaluarPolinomio(ListaTerminos listaT, int valor);

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void levantarTerminos(file * f, ListaTerminos &listaTerminos);

void bajarTerminos(file * f, ListaTerminos listaTerminos);

Boolean representaPolinomioNulo(ListaTerminos listaTerminos)
{
    Boolean resu = FALSE;
    if (listaTerminos == NULL)
        resu = TRUE;
    return resu;
}

ListaTerminos reducePolinomio(ListaTerminos listaTerminos);
