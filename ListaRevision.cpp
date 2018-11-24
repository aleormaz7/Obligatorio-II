/*
#include "ListaRevision.h"

void MostrarLista(listaRevision L)
{
    while(L != NULL)
    {
        printf(" %d",L->info);
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

void InsFront(listaRevision &L, int e)
{
    listaRevision aux = new nodo;
    aux-> info = e;
    aux->sig = L;
    L = aux;
}


int Primero(listaRevision L)
{
    return (L->info);
}


void Resto(listaRevision &L)
{
    listaRevision aux = L;
    L = L->sig;
    delete(aux);
}

int LargoRecu(listaRevision L)
{
    if(L == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + LargoRecu(L->sig);
    }
}


int UltimoRecu(listaRevision L)
{
    if(L->sig == NULL)
        return L->info;
    else
        UltimoRecu(L->sig);
}


int ContarRecu(listaRevision L, int valor)
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
}


boolean PerteneceRecu(listaRevision L, int valor)
{
    if(L == NULL)
    {
        return FALSE;
    }
    else
    {
        if(L->info == valor)
        {
            return TRUE;
        }
        else
        {
            PerteneceRecu(L->sig,valor);
        }
    }
}


void SustituirRecu(listaRevision &L, int num1,int num2)
{
    if(L != NULL)
    {
        if(L->info == num1)
        {
            L->info = num2;
        }

        SustituirRecu(L->sig,num1,num2);
    }
}



int MaximoRecu(listaRevision L)
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
}


void ParesImparesRecu(listaRevision L, listaRevision &LPares, listaRevision &LImpares)
{
    if(L != NULL)
    {
        if((L->info % 2) == 0)
        {
            InsFront(LPares,L->info);
        }
        else
        {
            InsFront(LImpares,L->info);
        }

        ParesImparesRecu(L->sig, LPares, LImpares);
    }
}

void InsBackRecu(listaRevision &L, int valor)
{
    if(L == NULL)
    {
        L = new nodo;
        L->info = valor;
        L->sig = NULL;
    }
    else
    {
        InsBackRecu(L->sig,valor);
    }
}
*/
