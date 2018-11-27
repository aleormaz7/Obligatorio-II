#include "ListaRevision.h"


void MostrarLista(listaRevision L)
{
    while(L != NULL)
    {

        //printf(" %d",L->info);
        L = L->sig;
    }
}

void Crear(listaRevision &L)
{
    L = NULL;
}

boolean EsVacia(listaRevision L)
{
    boolean es = FALSE;

    if(L == NULL)
    {
        es = TRUE;
    }

    return es;
}

void InsFront(listaRevision &L, Revision r)
{
    listaRevision aux = new nodoL;
    aux-> info = r;
    aux->sig = L;
    L = aux;
}

Revision Primero(listaRevision L)
{
    return (L->info);
}

void Resto(listaRevision &L)
{
    listaRevision aux = L;
    L = L->sig;
    delete(aux);
}

Revision UltimoRecu(listaRevision L)
{
    if(L->sig == NULL)
        return L->info;
    else
        UltimoRecu(L->sig);
}

boolean PerteneceRecu(listaRevision L, Revision r)
{
    if(L == NULL)
    {
        return FALSE;
    }
    else
    {
        if(darCodigoExpedienteDeRevision(L->info) == darCodigoExpedienteDeRevision(r))
        {
            return TRUE;
        }
        else
        {
            PerteneceRecu(L->sig,r);
        }
    }
}

void InsBackRecu(listaRevision &L, Revision r)
{
    if(L == NULL)
    {
        L = new nodoL;
        L->info = r;
        L->sig = NULL;
    }
    else
    {
        InsBackRecu(L->sig,r);
    }
}


void ListarRevisiones(listaRevision L)
{
    while(L != NULL)
    {
        mostrarRevision(L->info);
        L = L->sig;
    }
}

void ListarRevisionesPorCodigoExpediente(listaRevision L, long int cod)
{
    while(L != NULL)
    {
        if(darCodigoExpedienteDeRevision(L->info) == cod)
        {
            mostrarRevision(L->info);
        }
        L = L->sig;
    }
}


void EliminarRevisionesPorExpediente(listaRevision &L, long int codigoExp)
{
    listaRevision aux;
    Crear(aux);
    if(L != NULL)
    {
        if(darCodigoExpedienteDeRevision( L->info) == codigoExp)
        {
            aux = L->sig;
            delete(L);
            L = aux;
            EliminarRevisionesPorExpediente(L,codigoExp);
        }
        else
        {
            EliminarRevisionesPorExpediente(L->sig,codigoExp);
        }
    }
}

long int codigoExpedienteMayorCantRevisiones(listaRevision L)
{
    /*long int auxMayor;
    long int auxCodigoExp;
    int cantRevisiones = 0;

    while(L != NULL)
    {
        auxMayor = darCodigoExpedienteDeRevision(L->info);
        L = L->sig;
        if(darCodigoExpedienteDeRevision(L->info) > auxMayor)
        {
            cantRevisiones++;

        }

    }*/

}

int cantRevisonesEntreFechas(listaRevision L, Fecha f1, Fecha f2)
{
    int cant = 0;
    while (L != NULL)
    {

        ///comparar por anio mes dia
        //if((darFechaRev(L->info) >= f1) && (darFechaRev(L->info) <= f2))
        //{
        //    cant++;
        //}

        L = L->sig;
    }
    return cant;
}

void cantRevisionesCadaTipo(listaRevision L, int &cantTipo1, int &cantTipo2, int &cantTipo3)
{
    cantTipo1 = 0;
    cantTipo2 = 0;
    cantTipo3 = 0;

    while(L != NULL)
    {
        Resultante r = darResultanteRevision(L->info);
        switch(r)
        {
            case SATISFACTORIO:
                cantTipo1++;
                break;
            case INCOMPLETA:
                cantTipo2++;
                break;
            case PENDIENTE:
                cantTipo3++;
                break;
            default:
                break;
        }
        L = L->sig;
    }
}


