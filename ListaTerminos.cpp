#include "ListaTerminos.h"

Boolean Vacia(ListaTerminos listaT)
{
    Boolean Resu = FALSE;
    if (listaT == NULL)
        Resu = TRUE;
    return Resu;
}

void resto(ListaTerminos &listaT); /*borrar 1er valor*/

/*Precondición: lista no vacía*/
void Crear(ListaTerminos &listaT)
{
    listaT = NULL;
}

void insertar(ListaTerminos &listaT, Termino t);
/*inserta recursivamente ordenado por grado*/


//Precondición: lista no vacia
void mostrarListaTerminos(ListaTerminos t)
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

int Evaluar(ListaTerminos listaT, int valor);

void SumaPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void MultiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void LevantarTerminos(file * f, ListaTerminos &listaTerminos);

void BajarTerminos(file * f, ListaTerminos listaTerminos);

Boolean representaPolinomioNulo(ListaTerminos listaTerminos)
{
    Boolean resu = FALSE;
    if (listaTerminos == NULL)
        resu = TRUE;
    return resu;
}

ListaTerminos Reduce(ListaTerminos listaTerminos);
