#include "ABBPolinomio.h"

void ABBPolinomioCrear(ABBPolinomio &a)
{
    a = NULL;
}

boolean ABBPolinomioEsVacio(ABBPolinomio a)
{
    boolean resu = FALSE;
    if (a == NULL)
        resu = TRUE;
    return resu;
}

Polinomio ABBPolinomioDarRaiz(ABBPolinomio a)
{
    return a->info;
}

ABBPolinomio darHijoIzq(ABBPolinomio a)
{
    return a->hizq;
}

ABBPolinomio darHijoDer(ABBPolinomio a)
{
    return a->hder;
}


void ABBPolinomioListar(ABBPolinomio a)
{
     if (a != NULL)
     {
         ABBPolinomioListar(a->hizq); ///ListarOrdenado(a -> hizq);
         mostrarPolinomio(a->info);
         printf("\n\t");
         ABBPolinomioListar(a->hder); ///ListarOrdenado(a -> hder);
     }
}

boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio)
{
    String straux;
    if (a == NULL)
        return FALSE;
    else
    {
        darNombrePolinomio(a->info,straux);
        if (streq(straux,nombrePolinomio))
            return TRUE;
        else
        {
            if (strmen(nombrePolinomio,straux))
                return ABBPolinomioExiste(a->hizq,nombrePolinomio);
            else
                return ABBPolinomioExiste(a->hder,nombrePolinomio);
        }
    }
}

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p)
{
    if(a == NULL)
    {
        a = new nodoABB;
        a->info = p;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        String auxABB,auxPol;
        strcrear(auxABB);
        strcrear(auxPol);

        darNombrePolinomio(a->info,auxABB);
        darNombrePolinomio(p,auxPol);
        if (strmen(auxPol,auxABB))
            ABBPolinomioInsertar(a->hizq, p);
        else
            ABBPolinomioInsertar(a->hder, p);
    }
}

Polinomio darPolinomio(ABBPolinomio a, String nombrePol)
{
    String straux;
    darNombrePolinomio(a->info,straux);
    if(streq(straux,nombrePol))
        return a->info;
    else
    {
        if (strmen(nombrePol,straux))
            return darPolinomio(a->hizq,nombrePol);
        else
            return darPolinomio(a->hder,nombrePol);
    }
}

void ABBPolinomioEliminar(ABBPolinomio &a)
{
    if(a != NULL)
    {
        ABBPolinomioEliminar(a->hizq);
        ABBPolinomioEliminar(a->hder);
        borrarPolinomio(a->info);
        a = NULL;
    }
}

