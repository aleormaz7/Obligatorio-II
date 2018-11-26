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

/*int LargoRecu(listaRevision L)
{
    if(L == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + LargoRecu(L->sig);
    }
}*/


Revision UltimoRecu(listaRevision L)
{
    if(L->sig == NULL)
        return L->info;
    else
        UltimoRecu(L->sig);
}


/*int ContarRecu(listaRevision L, int valor)
{
    if(L == NULL)
    {
        return 0;
    }
    else
    {
        if(L->info == valor)
        {
            return 1 + ContarRecu(L->sig,valor);
        }
        else
        {
            return ContarRecu(L->sig,valor);
        }
    }
}*/


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


/*void SustituirRecu(listaRevision &L, int num1,int num2)
{
    if(L != NULL)
    {
        if(L->info == num1)
        {
            L->info = num2;
        }

        SustituirRecu(L->sig,num1,num2);
    }
}*/



/*int MaximoRecu(listaRevision L)
{
    if(L->sig == NULL)
    {
        return L->info;
    }
    else
    {
        int aux = MaximoRecu(L->sig);
        if(L->info > aux)
        {
            return L->info;
        }
        else
        {
            return aux;
        }
    }
}*/



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

