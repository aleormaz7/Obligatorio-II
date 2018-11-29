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

boolean listaRevisionesEsVacia(listaRevision L)
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

int cantRevisonesEntreFechas(listaRevision L, Fecha f1, Fecha f2)
{
    int cant = 0;
    while (L != NULL)
    {
        Fecha f = darFechaRev(L->info);
        if(f.anio >= f1.anio && f.anio <= f2.anio)
        {
             if(f.mes >= f1.mes && f.mes <= f2.mes)
             {
                 if(f.dia >= f1.dia && f.dia <= f2.dia)
                 {
                     cant++;
                 }
             }
        }
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

int cntRevisionesCodigoExp(listaRevision L, long int codExp)
{
    int cnt = 0;

    while(L != NULL)
    {
        if(darCodigoExpedienteDeRevision(L->info) == codExp);
            cnt ++;
        L = L->sig;
    }
    return cnt;
}
